/*poj 3020 一般图最大匹配 带花树开花算法
  题意：
  给出一个h*w的图，每个点都是'o'或'*'，最少要用多少个1*2的矩形才能把图中所有的'*'都覆盖掉。
  限制：
  1 <= h <= 40; 1 <= w <= 10
  思路：
  最小边覆盖=|V|-最大匹配
  一般图最大匹配，带花树开花算法
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_V = 405;

// 并查集维护
int fa[MAX_V];
int getFa(int x) { 
	return fa[x] == x ? x : fa[x] = getFa(fa[x]);
}
void merge(int a, int b) {
	a = getFa(a);
	b = getFa(b);
	if (a != b) fa[a] = b;
}

int V, match[MAX_V];
vector<int> e[MAX_V];
int Q[MAX_V], rear;
int next[MAX_V], mark[MAX_V], vis[MAX_V];

// 朴素算法求某阶段中搜索树上两点x, y的最近公共祖先r
int LCA(int x, int y) {
	static int t = 0; t++;
	while (true) {
		if (x != -1) {
			x = getFa(x); // 点要对应到对应的花上去
			if (vis[x] == t) return x;
			vis[x] = t;
			if (match[x] != -1) x = next[match[x]];
			else x = -1;
		}
		swap(x, y);
	}
}

void group(int a, int p) {
	while (a != p) {
		int b = match[a], c = next[b];

		// next数组是用来标记花朵中的路径的，综合match数组来用，实际上形成了
		// 双向链表，如(x, y)是匹配的，next[x]和next[y]就可以指两个方向了。
		if (getFa(c) != p) next[c] = b;

		// 奇环中的点都有机会向环外找到匹配，所以都要标记成S型点加到队列中去，
		// 因环内的匹配数已饱和，因此这些点最多只允许匹配成功一个点，在aug中
		// 每次匹配到一个点就break终止了当前阶段的搜索，并且下阶段的标记是重
		// 新来过的，这样做就是为了保证这一点。
		if (mark[b] == 2) mark[Q[rear++] = b] = 1;
		if (mark[c] == 2) mark[Q[rear++] = c] = 1;

		merge(a, b); merge(b, c);
		a = c;
	}
}

// 增广
void aug(int s) {
	for (int i = 0; i < V; i++) // 每个阶段都要重新标记
		next[i] = -1, fa[i] = i, mark[i] = 0, vis[i] = -1;
	mark[s] = 1;
	Q[0] = s; rear = 1; 
	for (int front = 0; match[s] == -1 && front < rear; front++) {
		int x = Q[front]; // 队列Q中的点都是S型的
		for (int i = 0; i < (int)e[x].size(); i++) {
			int y = e[x][i];
			if (match[x] == y) continue; // x与y已匹配，忽略
			if (getFa(x) == getFa(y)) continue; // x与y同在一朵花，忽略
			if (mark[y] == 2) continue; // y是T型点，忽略
			if (mark[y] == 1) { // y是S型点，奇环缩点
				int r = LCA(x, y); // r为从i和j到s的路径上的第一个公共节点
				if (getFa(x) != r) next[x] = y; // r和x不在同一个花朵，next标记花朵内路径
				if (getFa(y) != r) next[y] = x; // r和y不在同一个花朵，next标记花朵内路径

				// 将整个r -- x - y --- r的奇环缩成点，r作为这个环的标记节点，相当于论文中的超级节点
				group(x, r); // 缩路径r --- x为点
				group(y, r); // 缩路径r --- y为点
			}
			else if (match[y] == -1) { // y自由，可以增广，R12规则处理
				next[y] = x;
				for (int u = y; u != -1; ) { // 交叉链取反
					int v = next[u];
					int mv = match[v];
					match[v] = u, match[u] = v;
					u = mv;
				}
				break; // 搜索成功，退出循环将进入下一阶段
			}
			else { // 当前搜索的交叉链+y+match[y]形成新的交叉链，将match[y]加入队列作为待搜节点
				next[y] = x;
				mark[Q[rear++] = match[y]] = 1; // match[y]也是S型的
				mark[y] = 2; // y标记成T型
			}
		}
	}
}

bool g[MAX_V][MAX_V];
const int N=45;
char str[N][N];
int mp[N][N];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int h,w;
bool ok(int x,int y){
	if(x>=0 && x<h && y>=0 && y<w && str[x][y]=='*')
		return true;
	return false;
}
void init(){
	memset(g,0,sizeof(g));
	for(int i=0;i<MAX_V;++i) e[i].clear();
}
void add_edge(int u,int v){
	if(g[u][v]) return ;
	e[u].push_back(v);
	e[v].push_back(u);
	g[u][v]=g[v][u]=1;
}
int gao(){	//增广匹配，求最大匹配
	int ret=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<V;++i)
		if(match[i]==-1) aug(i);
	for(int i=0;i<V;++i)
		if(match[i]!=-1) ++ret;
	return ret;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&h,&w);
		for(int i=0;i<h;++i)
			scanf("%s",str[i]);
		V=0;
		for(int i=0;i<h;++i)
			for(int j=0;j<w;++j){
				if(str[i][j]=='*') mp[i][j]=V++;
				else mp[i][j]=-1;
			}
		for(int i=0;i<h;++i)
			for(int j=0;j<w;++j){
				if(mp[i][j]!=-1){
					int u=mp[i][j],v;
					for(int k=0;k<4;++k){
						int tmpx=i+dx[k];
						int tmpy=j+dy[k];
						if(ok(tmpx,tmpy)){
							v=mp[tmpx][tmpy];
							add_edge(u,v);
						}
					}
				}
			}
		int ans=gao();
		ans=V-ans/2;
		printf("%d\n",ans);
	}
	return 0;
}

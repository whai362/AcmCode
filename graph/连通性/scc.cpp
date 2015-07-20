#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define PB push_back
const int MAX_V = 1e4+5;
int V;
vector<int> G[MAX_V]; //图
vector<int> rG[MAX_V]; //反向图
vector<int> vs; //后序遍历顺序的顶点列表
bool used[MAX_V]; //访问标记
int cmp[MAX_V]; //所属强连通分量的拓扑序
void add_edge(int fr, int to){
	G[fr].PB(to);
	rG[to].PB(fr);
}
void dfs(int u){
	used[u] = true;
	for(int i = 0; i < G[u].size(); ++i){
		int ch = G[u][i];
		if(!used[ch]) dfs(ch);
	}
	vs.PB(u);
}
void rdfs(int u,int k){
	used[u] = true;
	cmp[u] = k;
	for(int i = 0; i < rG[u].size(); ++i){
		int ch = rG[u][i];
		if(!used[ch]) rdfs(ch, k);
	}
}
//点的序号从0开始
int scc(){
	fill(used, used+V, 0);
	vs.clear();
	for(int v = 0; v < V; ++v){
		if(!used[v]) dfs(v);
	}
	fill(used, used+V, 0);
	int k = 0;
	for(int i = vs.size() - 1; i >= 0; --i){
		if(!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}

void init(int n){
	for(int i = 0; i <= n; ++i){
		G[i].clear();
		rG[i].clear();
	}
}
int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
		init(n);
		V = n;
		for(int i = 0; i < m; ++i){
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u-1, v-1);
		}
		int scc_cnt = scc();
		int u = 0;
		int ans = 0;
		for(int i = 0; i < V; ++i){
			if(cmp[i] == scc_cnt - 1){
				u = i;
				++ans;
			}
		}
		
		//判断强连通分量是否连通
		fill(used, used+V, 0);
		rdfs(u, 0);
		for(int i = 0; i < V; ++i){
			if(!used[i]){
				// 存在不可达的点
				ans = 0;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

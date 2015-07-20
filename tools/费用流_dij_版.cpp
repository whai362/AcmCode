/*poj 2135
  题意：
  给出一个有n个点m条边的图，求从点1到点n再从点n回到点1的最短路径，要求每条路最多只能经过一次。
  限制：
  1 <= n <= 1000; 1 <= m <= 10000
  思路：
  费用流
  建图：
  超级源点0，连边：0->1，流量为2，费用为0；
  超级汇点n+1，连边：n->n+1，流量为2，费用为0；
  其他和图的边一样，建双向边，流量为1，费用为边权。

  该模板利用dij求最短路, 复杂度O(F |E| log|V|);
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_V = 1005;
#define PII pair<int,int>
#define PB push_back
#define X first
#define Y second
struct edge{ int to, cap, cost, rev; };
int V;	//顶点数
vector<edge> G[MAX_V];
int h[MAX_V]; //顶点的势
int dist[MAX_V]; //最短距离
int prevv[MAX_V], preve[MAX_V]; //最短路中的前驱节点和对应的边
void add_edge(int fr, int to, int cap, int cost){
	G[fr].PB((edge){to, cap, cost, G[to].size()});
	G[to].PB((edge){fr, 0, -cost, G[fr].size()-1});
}
//求解从s到t流量为f的最小费用流
//如果没有流量为f的流，则返回-1
int min_cost_flow(int s, int t, int f){
	int res = 0;
	fill(h, h+V, 0);
	while(f > 0){
		//使用dij更新h
		priority_queue< PII, vector<PII>, greater<PII> > que;
		fill(dist, dist+V, INF);
		dist[s] = 0;
		que.push(PII(0, s));
		while(!que.empty()){
			PII p = que.top(); que.pop();
			int v = p.Y;
			if(dist[v] < p.X) continue;
			for(int i = 0; i < G[v].size(); ++i){
				edge &e = G[v][i];
				int tmp = dist[v] + e.cost + h[v] - h[e.to];
				if(e.cap > 0 && dist[e.to] > tmp){
					dist[e.to] = tmp;
					prevv[e.to] = v;
					preve[e.to] = i;
					que.push(PII(dist[e.to], e.to));
				}
			}
		}
		if(dist[t] == INF){
			//不能再增广
			return -1;
		}
		for(int v = 0; v < V; ++v) h[v] += dist[v];
		//沿s到t最短路尽量增广
		int d = f;
		for(int v = t; v != s; v = prevv[v]){
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d * h[t];
		for(int v = t; v != s; v = prevv[v]){
			 edge &e = G[prevv[v]][preve[v]];
			 e.cap -= d;
			 G[v][e.rev].cap += d;
		}
	}
	return res;
}
void init(){
	for(int i = 0; i < V; ++i) G[i].clear();
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	V = n + 2;
	init();
	while(m--){
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		add_edge(u, v, 1, c);
		add_edge(v, u, 1, c);
	}
	add_edge(0, 1, 2, 0);
	add_edge(n, n+1, 2, 0);
	int ans = min_cost_flow(0, n+1, 2);
	cout<<ans<<endl;
	return 0;
}

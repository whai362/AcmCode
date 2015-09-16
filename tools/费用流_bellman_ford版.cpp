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

  该模板利用bellman-ford求最短路，复杂度为O(F|V||E|)
 */
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define PB push_back
const int INF = 0x3f3f3f3f;
const int MAX_V = 1005;
//终点，容量，费用，反向边
struct edge { int to, cap, cost, rev; };
int V;	//顶点数
vector<edge> G[MAX_V];
int dist[MAX_V];	//最短距离
int prevv[MAX_V], preve[MAX_V];	//最短路中的前驱节点和对应的边
void add_edge(int fr, int to, int cap, int cost) {
	G[fr].PB((edge) {to, cap, cost, G[to].size()});
	G[to].PB((edge) {fr, 0, -cost, G[fr].size() - 1});
}
//求解从s到t流量为f的最小费用流
//如果不能再增广则返回-1
int min_cost_flow(int s, int t, int f) {
	int res = 0;
	while (f > 0) {
		//利用bellman-ford求s到t的最短路
		fill(dist, dist + V, INF);
		dist[s] = 0;
		bool update = true;
		while (update) {
			update = false;
			for (int v = 0; v < V; ++v) {
				if (dist[v] == INF) continue;
				for (int i = 0; i < G[v].size(); ++i) {
					edge &e = G[v][i];
					if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}
		//不能再增广
		if (dist[t] == INF) return -1;
		//沿s到t的最短路尽量增广
		int d = f;
		for (int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
		f -= d;
		res += d * dist[t];
		for (int v = t; v != s; v = prevv[v]) {
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}
void init() {
	for (int i = 0; i < V; ++i) G[i].clear();
}
int main() {
	int n, m;
	int u, v, cost;
	scanf("%d%d", &n, &m);
	V = n + 2;
	init();
	while (m--) {
		scanf("%d%d%d", &u, &v, &cost);
		add_edge(u, v, 1, cost);
		add_edge(v, u, 1, cost);
	}
	add_edge(0, 1, 2, 0);
	add_edge(n, n + 1, 2, 0);
	int ans = min_cost_flow(0, n + 1, 2);
	cout << ans << endl;
	return 0;
}

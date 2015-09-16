#include <iostream>
#include <cstdio>
#include <queue>
#include <tr1/unordered_set>
using namespace std;
using namespace std::tr1;

const int N = 5000 + 5;
const int V = 20000 + 5;

struct E {
	int u, v, c;
};

struct Q {
	int x, ans, id;
}ans[N];

priority_queue<E> q;

vector<P> G[N];

int sum[N];

int a[N];

unordered_set<P> used;

void gao(int n) {
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < G[i].size(); ++j) {
			P e = G[i][j];
			int u = i;
			int v = e.v;
			int c = e.c;
			if(u > v) swap(u, v);
			if(used.find(P(u, v)) != used.end()) continue;
			if(e.c <= maxx) {
				q.push((E){u, v, c});
				used.insert(P(u, v));
				int s = c;
				int p = lower_bound(a, a + q, s) - a;
				if(p < q) {
					++sum[p];
				}
			}
		}
	}
	while(!q.empty()) {
		E e = q.front(); q.pop();
		int fr = e.u;
		for(int i = 0; i < G[fr].size(); ++i) {
			int u, v, s;
			u = fr;
			v = G[u][i].v;
			if(u > v) swap(u, v);
			if(used.find(P(u, v)) != used.end()) continue;
			s = e.s + G[u][i].c;
			if(s <= maxx) {
				q.push((E){u, v, c});
				used.insert(P(u, v));
				int p = lower_bound(a, a + q, s) - a;
				if(p < q) {
					++sum[p];
				}
			}
		}
	}
	for(int i = 1; i < q; ++i) {
		sum[i] += sum[i - 1];
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &q);
		init(n, m);
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].PB(v);
			G[v].PB(u);
		}
		for(int i = 0; i < q; ++i) {
			int x;
			scanf("%d", &x);
		}
		gao(n);
	}
	return 0;
}

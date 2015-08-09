#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct E { int to, cost; }

vector<E> G[N];

int u[N], v[N], c[N];

int main() {
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 0; i < m; ++i) {
		int u, v;
		LL c;
		scanf("%d%d%I64d", &u[i], &v[i], &c[i]);
		G[u[i]].PB((E){ v[i], c[i] });
	}
	}
}

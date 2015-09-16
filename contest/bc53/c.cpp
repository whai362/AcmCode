#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define PB push_back

const int N = 1e5 + 5;

vector<int> G[N];
int a[N];
double d[N];

void dfs(int u, int depth, int fa = -1) {
	d[u] = depth;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(v == fa) continue;
		dfs(v, depth + 1, u);
	}
}

void gao(int n) {
	for(int i = 2; i <= n; ++i) {
		G[a[i]].PB(i);
	}
	dfs(1, 0);

	sort(d + 1, d + 1 + n);

	double ans = 0;

	if(n <= 100) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j < i; ++j) {
				ans += (d[i] + 1) * (d[j] + 1) / (d[i] + d[j] + 2) * pow(2, j - 1);
			}
		}
		ans /= (pow(2, n) - n - 1);
	} else {
		for(int i = n - 100; i <= n; ++i) {
			for(int j = n - 100; j < i; ++j) {
				ans += (d[i] + 1) * (d[j] + 1) / (d[i] + d[j] + 2) / pow(2, n - j + 1);
			}
		}
	}
	printf("%.6f\n", ans);
}

void init(int n) {
	for(int i = 0; i <= n; ++i)
		G[i].clear();
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		init(n);
		for(int i = 2; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		gao(n);
	}
	return 0;
}

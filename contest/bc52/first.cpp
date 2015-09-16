/*hdu 5418
  题意：
  给出一个n个点，m条边的无向图，问从点1出发，经过每个点至少一次的最小花费。
  限制：
  0 <= n <= 15
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N = 17;
const int INF = 0x3f3f3f3f;

int dis[N][N];
int dp[1 << N][N];

void floyd(int n) {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++) {
			if (dis[i][k] == INF) continue;
			for (int j = 0; j < n; j++) {
				if (dis[k][j] == INF) continue;
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
}
int DP(int n) {
	if (n == 1)
		return 0;
	int ans = INF;
	for (int i = 0; i < (1 << (n - 1)); ++i)
		for (int j = 1; j < n; ++j)
			if (i == (1 << (j - 1)))
				dp[i][j] = dis[0][j];
			else if (i & (1 << (j - 1))) {
				dp[i][j] = INF;
				for (int k = 1; k < n; ++k)
					if (k != j && (i & (1 << (k - 1))))
						dp[i][j] = min(dp[i ^ (1 << (j - 1))][k] + dis[k][j],
								dp[i][j]);
			}
	for (int i = 1; i < n; ++i) {
		ans = min(ans, dp[(1 << (n - 1)) - 1][i] + dis[i][0]);
	}
	return ans;
}

void init(int n, int m) {
	memset(dis, 0x3f, sizeof(dis));
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; ++i)
		dis[i][i] = 0;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		init(n, m);
		for (int i = 0; i < m; ++i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			--u, --v;
			dis[u][v] = dis[v][u] = min(dis[u][v], c);
		}
		floyd(n);
		printf("%d\n", DP(n));
	}
	return 0;
}


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define LL __int64

const LL INF = 10000000000000000LL;
const int N = 3 * 1e5 + 5;
const int M = 5005;

LL a[N], pre[N];
LL dp[M][M];

void init(int n) {
	pre[0] = pre[1] = 0;
	for(int i = 2; i <= n; ++i) {
		pre[i] = pre[i - 1] + a[i] - a[i - 1];
	}
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < M; ++j) {
			dp[i][j] = INF;
		}
	}
}

int main() {
	int n, k;
	cin>>n>>k;
	for(int i = 1; i <= n; ++i)
		cin>>a[i];
	sort(a + 1, a + 1 + n);

	int sz = n / k;
	int u = n % k;
	int v = k - u;

	init(n);

	dp[0][0] = 0;
	for(int i = 0; i <= u; ++i) {
		for(int j = 0; j <= v; ++j) {
			int x = i * (sz + 1) + j * sz + 1;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + pre[x + sz] - pre[x]);
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + pre[x + sz - 1] - pre[x]);
		}
	}
	cout<<dp[u][v]<<endl;
	return 0;
}

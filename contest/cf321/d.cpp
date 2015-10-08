#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL __int64

const int N = 20;

LL a[N];
LL G[N][N];
LL dp[1 << N][N];
LL num[1 << N];

void gao(int n, int m, int k) {
	memset(dp, -1, sizeof(dp));
	LL ans = 0;
	for(int i = 0; i < n; ++i) {
		dp[1 << i][i] = a[i];
		num[1 << i] = 1;
		if(m == 1) {
			ans = max(ans, a[i]);
		}
	}
	
	int maxx = (1 << n);
	for(int i = 0; i < maxx; ++i) {
		for(int j = 0; j < n; ++j) {
			if(dp[i][j] == -1) continue;
			for(int k = 0; k < n; ++k) {
				if(i & (1 << k)) continue;
				dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] + a[k] + G[j][k]);
				num[i | (1 << k)] = num[i] + 1;
				if(num[i | (1 << k)] == m) {
					ans = max(ans, dp[i | (1 << k)][k]);
				}
			}
		}
	}
	cout<<ans<<endl;
}

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	for(int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	for(int i = 0; i < k; ++i) {
		int u, v;
		LL c;
		cin>>u>>v>>c;
		--u; --v;
		G[u][v] = c;
	}
	gao(n, m, k);
	return 0;
}

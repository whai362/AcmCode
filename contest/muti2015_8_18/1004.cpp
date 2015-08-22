#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 105;
const int MOD = 1000000007;
#define LL __int64
LL f[N];
int a[N][N];

int deal(int x, int m) {
	for(int i = m - 1; i >= 0; --i) {
		x = a[i][x];
	}
	return x;
}

bool vis[N];

int main() {
	int n, m;
	f[0] = 1;
	for(int i = 1; i < N; ++i) {
		f[i] = f[i - 1] * i % MOD;
	}
	while(scanf("%d%d", &n, &m) != EOF) {
		int cnt = 0;
		int flag = 1;
		for(int i = 0; i < m; ++i) {
			int cc = 0;
			memset(vis, 0, sizeof(vis));
			for(int j = 0; j < n; ++j) {
				scanf("%d", &a[i][j]);
				if(a[i][j] == -1) {
					++cnt;
					break;
				} else {
					--a[i][j];
					if(vis[a[i][j]] == 0) {
						++cc;
						vis[a[i][j]] = 1;
					}
				}
			}
			if(a[i][0] != -1 && cc != n) {
				flag = 0;
			}
		}
		if(flag == 0) puts("0");
		else if(cnt > 0) {
			LL ans = 1;
			for(int i = 0; i < cnt - 1; ++i) {
				ans = ans * f[n] % MOD;
			}
			cout<<ans<<endl;
		} else {
			LL ans = 1;
			for(int i = 0; i < n; ++i) {
				if(deal(i, m) != i) {
					ans = 0;
					break;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL __int64
const int N = 10;
const int MAXN = 1e6 + 5;
const int MOD = 258280327;
int cnt[N];
LL dp[2][MAXN];

void init() {
	memset(cnt, 0, sizeof(cnt));
}

LL C[N][N];

void predo() {
	for(int i = 0; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
	}
	for(int i = 2; i < N; ++i) {
		for(int j = 1; j < i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}
}


void gao(int n, int A, int B, int sum) {
	int V = n * 9;
	int now = 0;
	fill(dp[now], dp[now] + V, 0);
	dp[now][0] = 1;
	for(int i = 1; i < 10; ++i) {
		now ^= 1;
		fill(dp[now], dp[now] + V, 0);
		for(int j = V; j >= 0; --j) {
			dp[now][j] = dp[now ^ 1][j];
			for(int k = 1; k <= cnt[i]; ++k) {
				if(j >= k * i)
					dp[now][j] = (dp[now][j] + C[cnt[i]][k] * dp[now ^ 1][j - k * i] % MOD) % MOD;
			}
		}
	}

	LL ans = 0;

	if(A > B) swap(A, B);
	if((sum - 1) % 9 + 1 == A || (sum - 1) % 9 + 1 == B) ++ans;
	for(int i = 1; i <= V; ++i) {
		int tmp = sum - i;
		int a = (i - 1) % 9 + 1;
		int b = (tmp - 1) % 9 + 1;
		if(a > b) swap(a, b);
		if(a == A && b == B) {
			ans = (ans + dp[now][i]) % MOD;
		}
	}

	cout<<ans<<endl;
	//for(int i = 0; i <= V; ++i) {
	//	cout<<dp[now][i]<<' ';
	//}
	//cout<<endl;
}

int main() {
	int T;
	predo();
	scanf("%d", &T);
	while(T--) {
		int n;
		int A, B;
		scanf("%d%d%d", &n, &A, &B);
		init();
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			int a;
			scanf("%d", &a);
			++cnt[a];
			sum += a;
		}
		gao(n, A, B, sum);
	}
}

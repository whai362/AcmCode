#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 + 5;
int dp[N];
int a[N];
void gao(int n) {
	for(int i = 0; i < n; ++i) {
		dp[a[i]] = 1;
	}
	int ans = 0;
	for(int i = N - 1; i >= 1; --i) {
		if(dp[i]) {
			for(int j = 2 * i; j < N; j += i)
				dp[i] = max(dp[i], dp[j] + 1);
			ans = max(ans, dp[i]);
		}
	}
	cout<<ans<<endl;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	gao(n);
	return 0;
}

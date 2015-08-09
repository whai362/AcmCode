#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define LL __int64
#define P pair<LL, int>
const int N = 2 * 1e5 + 5;
map< P, LL > dp;
LL a[N];
void gao(int n, int k) {
	for(int i = 0; i < n; ++i) {
		if(a[i] % k == 0) {
			dp[P(a[i], 3)] += dp[P(a[i] / k, 2)];
			dp[P(a[i], 2)] += dp[P(a[i] / k, 1)];
		}
		++dp[P(a[i], 1)];
		//cout<<dp[P(a[i], 1)]<<' '<<dp[P(a[i], 2)]<<' '<<dp[P(a[i], 3)]<<endl;
	}
	LL ans = 0;
	sort(a, a + n);
	n = unique(a, a + n) - a;
	for(int i = 0; i < n; ++i) {
		ans += dp[P(a[i], 3)];
	}
	cout<<ans<<endl;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%I64d", &a[i]);
	gao(n, k);
	return 0;
}

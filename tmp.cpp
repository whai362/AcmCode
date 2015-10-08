#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#define LL __int64
using namespace std;

const int MOD = 1000000007;
const int N = 1e5 + 5;
map<int, int> cnt;

LL a_b_MOD_c(LL a,LL b,LL mod){
	LL ret = 1;
	a %= mod;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int a[N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			++cnt[a[i]];
		}
		sort(a, a + n);
		int m = unique(a, a + n) - a;
		LL ans = 0;

		for(int i = 0; i < m; ++i) {
			int A = cnt[a[i]];
			int B = n - A;
			cout<<a[i]<<' '<<(a_b_MOD_c(2, n, MOD) - a_b_MOD_c(2, B, MOD) + MOD) % MOD<<endl;
			ans = (ans + a[i] * (a_b_MOD_c(2, n, MOD) - a_b_MOD_c(2, B, MOD) + MOD) % MOD) % MOD;
		}
		cout<<ans<<endl;
	}
}

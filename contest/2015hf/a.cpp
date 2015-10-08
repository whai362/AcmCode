#include <iostream>
#include <cstdio>
using namespace std;

#define LL __int64

const int MOD = 105225319;
const int N = 1005;

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


LL inv(LL a, LL m) {
	LL p = 1, q = 0, b = m, c, d;
	while (b > 0) {
		c = a / b;
		d = a; a = b; b = d % b;
		d = p; p = q; q = d - c * q;
	}
	return p < 0 ? p + m : p;
}


LL fac[N], ny[N];
void predo() {
	fac[1] = ny[1] = 1;
	for(int i = 2; i < N; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		ny[i] = inv(fac[i], MOD);
	}
}

LL C(int n, int m) {
	if(m > n) return 0;
	return fac[n] * ny[m] % MOD * ny[n - m] % MOD;
}

LL deal(int x, int n, int m) {
	int y = n - x;

	LL ret = C(n, x);
	LL tmp = a_b_MOD_c(m + 1, x * y, MOD);
	for(int i = 0; i <= y; ++i) {
		if(i & 1) {
			tmp = ((tmp - C(y, i) * a_b_MOD_c(m, (y - i) * x, MOD)) % MOD + MOD) % MOD;
		} else {
			tmp = (tmp + C(y, i) * a_b_MOD_c(m, (y - i) * x, MOD)) % MOD;
		}
	}
	for(int i = 0; i <= x; ++i) {
		if(i & 1) {
			tmp = ((tmp - C(x, i) * a_b_MOD_c(m, (x - i) * y, MOD)) % MOD + MOD) % MOD;
		} else {
			tmp = (tmp + C(x, i) * a_b_MOD_c(m, (x - i) * y, MOD)) % MOD;
		}
	}
	cout<<ret<<' '<<tmp<<endl;
	return ret * tmp % MOD;
}

int main() {
	
	predo();

	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		LL ans = 0;
		for(int i = 1; i < n; ++i) {
			ans = (ans + deal(i, n, m)) % MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}

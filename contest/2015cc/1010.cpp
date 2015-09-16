#include <iostream>
#include <cstdio>

using namespace std;

#define LL __int64
const int N = 25;
LL p[N];
LL a[N];

LL exp_mod(LL a, LL b, LL p) {
	LL res = 1;
	while(b != 0) {
		if(b&1) res = (res * a) % p;
		a = (a*a) % p;
		b >>= 1;
	}
	return res;
}

LL Comb(LL a, LL b, LL p) {
	if(a < b)   return 0;
	if(a == b)  return 1;
	if(b > a - b)   b = a - b;

	LL ans = 1, ca = 1, cb = 1;
	for(LL i = 0; i < b; ++i) {
		ca = (ca * (a - i))%p;
		cb = (cb * (b - i))%p;
	}
	ans = (ca*exp_mod(cb, p - 2, p)) % p;
	return ans;
}

LL lucas(LL n, LL m, int M_id) {
	LL ans = 1;
	while(n && m && ans) {
		ans = (ans*Comb(n%p[M_id], m%p[M_id], p[M_id])) % p[M_id];
		n /= p[M_id];
		m /= p[M_id];
	}
	return ans;
}

LL Ext_gcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) { x = 1, y = 0; return a; }
	LL ret = Ext_gcd(b, a % b, y, x);
	y -= a / b * x;
	return ret;
}

LL mul(LL a,LL b,LL m){
    LL ret = 0;
    a %= m;
    while(b){
        if(b & 1) ret = (ret + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return ret;
}

LL CRT(LL a[], LL m[], int n) {
	LL M = 1;
	for (int i = 0; i < n; ++i) M *= m[i];
	//cout<<M<<endl;
	LL ret = 0;
	for (int i = 0; i < n; ++i) {
		LL x, y;
		LL tm = M / m[i];
		Ext_gcd(tm, m[i], x, y);
		ret = (ret + mul(mul(tm, (x + M) % M, M), a[i], M)) % M;
	}
	return (ret + M) % M;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		LL n, m;
		int k;
		scanf("%I64d%I64d%d", &n, &m, &k);
		LL MAX_P = 0;
		for(int i = 0; i < k; ++i) {
			scanf("%I64d", &p[i]);
			MAX_P = max(MAX_P, p[i]);
		}

		for(int i = 0; i < k; ++i) {
			a[i] = lucas(n, m, i);
		}
		//for(int i = 0; i < k; ++i) {
		//	cout<<a[i]<<' '<<p[i]<<endl;
		//}
		LL ans = CRT(a, p, k);
		cout<<ans<<endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#define LL __int64
using namespace std;


LL inv(LL a, LL m) {
	LL p = 1, q = 0, b = m, c, d;
	while (b > 0) {
		c = a / b;
		d = a; a = b; b = d % b;
		d = p; p = q; q = d - c * q;
	}
	return p < 0 ? p + m : p;
}

const int MOD = 5;
const int N = 15;
LL f[N], ny[N];

void predo() {
	f[0] = ny[0] = 1;
	for(int i = 1; i < N; ++i) {
		f[i] = f[i - 1] * i % MOD;
		ny[i] = inv(f[i], MOD);
	}
}

LL C(int n, int m) {
	if(m > n) return 0;
	return f[n] * ny[m] % MOD * ny[n - m] % MOD;
}

LL lucas(int n, int m, int MOD) {
	if (n < m) return 0;	//зЂвт
	LL ret = 1;
	while (n && m) {
		LL a = n % MOD, b = m % MOD;
		//cout<<a<<' '<<b<<endl;
		if (a < b) return 0;
		ret = ret * C(a, b) % MOD;
		n /= MOD;
		m /= MOD;
	}
	return ret;
}

int main() {
	predo();
	//cout<<C(2, 1)<<endl;
	cout<<lucas(9, 5, 5)<<endl;
}

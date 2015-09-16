//2*(2*n-1)!/(n!*(n-1)!)-1
#include <iostream>
#include <cstdio>
using namespace std;
#define LL __int64
const int MOD = 1000000007;
const int N = 2 * 1e6 + 5;

LL fac[N], ny[N];

LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}


void predo(int n) {
	fac[1] = ny[1] = 1;
	for(int i = 2; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		ny[i] = inv(fac[i], MOD);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	++n;
	predo(2 * n - 1);
	cout<<(2LL * fac[2 * n - 1] % MOD * ny[n] % MOD * ny[n - 1] % MOD - 1 + MOD) % MOD<<endl;
}

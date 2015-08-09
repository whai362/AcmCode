#include <iostream>
#include <cstdio>
#define LL __int64
using namespace std;
const int MOD = 1000000007;
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

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		cout<<(a_b_MOD_c(2, n - 1, MOD) - 1 + MOD) % MOD<<endl;
	}
	return 0;
}

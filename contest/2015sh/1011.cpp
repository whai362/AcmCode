#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define PB push_back

vector<int> A, B;

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
	int k1, b1, k2, C;
	while(scanf("%d%d%d%d", &C, &k1, &b1, &k2) != EOF) {
	}
}

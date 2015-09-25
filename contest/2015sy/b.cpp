#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define LL __int64

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

double get_p(int x, int m) {
	double tmp = a_b_MOD_c(2, x, m - 1);
	tmp = tmp * log(5 + 2 * sqrt(6)) / log(2);
	return tmp;
}

int main() {
	int x, m;
	cin>>x>>m;
	double p = get_p(x, m);
	cout<<p<<endl;
	double ans = (5 + 2 * sqrt(6)) * pow(2, p);
	printf("%.6f\n", ans);

}

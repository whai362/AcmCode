#include <iostream>
#include <cstdio>
using namespace std;

#define LL __int64

LL get_phi(LL x) {
	LL ret = 1;
	for(LL i = 2; i * i <= x; ++i)
		if(x % i == 0) {
			ret = ret * (i - 1);
			x /= i;
			while(x % i == 0) x /= i, ret *= i;
		}
	if(x > 1) ret = ret * (x - 1);
	return ret;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		LL ans = get_phi(n + 1);
		printf("%I64d\n", ans);
	}
	return 0;
}

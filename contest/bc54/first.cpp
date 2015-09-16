#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define LL __int64

const int N = 105;

LL f[N * N], tot;
LL a[N];

void deal(LL x) {
	for(LL i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			while(x % i == 0) {
				f[tot++] = i;
				x /= i;
			}
		}
	}
	if(x > 1) f[tot++] = x;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		tot = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%I64d", &a[i]);
			deal(a[i]);
		}
		sort(f, f + tot);
		if(tot <= 1) {
			puts("-1");
		} else {
			printf("%I64d\n", f[0] * f[1]);
		}
	}
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
#define LL __int64
const int N = 5 * 1e5 + 5;
LL a[N];
int main() {
	int n, m, z, l;
	int T;
	scanf("%d", &T);
	while(T--) { 
		scanf("%d%d%d%d", &n, &m, &z, &l);
		LL now = 0;
		for(int i = 0; i < n; ++i) {
			a[i] = now;
			now = (now * m + z) % l;
		}
		LL ans = a[0] * 2;
		for(int i = 1; i < n; ++i ) {
			ans ^= (a[i] * 2);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

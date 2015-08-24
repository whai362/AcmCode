#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 1005;

double a[N];
double sum[N];

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%lf", &a[i]);
			a[i] = log(a[i]);
		}
		sum[0] = 0;
		for(int i = 1; i <= n; ++i) {
			sum[i] = sum[i - 1] + a[i];
		}
		printf("Case #%d:\n", ++cas);
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			++u, ++v;
			double len = v - u + 1;
			double ans = (sum[v] - sum[u - 1]) / len;
			ans = exp(ans);
			printf("%.9f\n", ans);
		}
	}
	return 0;
}

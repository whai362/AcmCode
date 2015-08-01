#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N], c[N], d[N];
int main() {
	int n, m;
	int x, y;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &x, &y);
	int max_s1 = 0, max_s2 = 0, max_a = 0, max_b = 0, max_c = 0, max_d = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		max_s1 = max(max_s1, a[i] + b[i]);
		max_a = max(max_a, a[i]);
		max_b = max(max_b, b[i]);
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &c[i], &d[i]);
		max_s2 = max(max_s2, c[i] + d[i]);
		max_c = max(max_c, c[i]);
		max_d = max(max_d, d[i]);
	}
	if(max_s1 < max_s2 && max_a < max_c && max_b < max_d) puts("Min");
	else puts("Max");
	return 0;
}

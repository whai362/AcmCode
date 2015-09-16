#include<cstdio>
#include<algorithm>
const int M = 700000;
using namespace std;

long long g[M];

int main() {
	g[1] = 1;
	g[2] = 3;
	for (int i = 3; i < M; ++i)
		g[i] = g[i - 1] + (lower_bound(g + 1, g + i, i) - g);
	int n;
	while (scanf("%d", &n), n)
		printf("%d\n", lower_bound(g + 1, g + M, n) - g);
	return 0;
}

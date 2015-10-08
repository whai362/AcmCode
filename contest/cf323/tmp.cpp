#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
int	min_v[N]; //存储长度i+1（len）的子序列最大元素的最小值
int LIS(int arr[], int size) {
	int len = 1;
	min_v[0] = arr[0];
	for (int i = 1; i < size; ++i) {
		if (arr[i] >= min_v[len - 1]) { //
			min_v[len++] = arr[i];
		} else {
			int pos = lower_bound(min_v, min_v + len, arr[i]) - min_v;
			min_v[pos] = arr[i];
		}
	}
	return len;
}

int a[N];

void gao(int n, int m, int t) {
	int ans = LIS(a, n * m);
	sort(a, a + n);
	int maxx = 0, max_v = 0, cnt = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1]) ++cnt;
		else {
			if (cnt > maxx || (cnt == maxx && max_v <= a[i])) {
				maxx = cnt;
				max_v = a[i];
			}
			cnt = 1;
		}
	}
	maxx = max(maxx, cnt);
	printf("%d\n", ans + maxx * (t - m));
}

int main() {
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int m = min(1000, t);
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
			a[i * n + j] = a[j];
	gao(n, m, t);

	return 0;
}

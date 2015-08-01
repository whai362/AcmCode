#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int sum[N];

int ok(int x) {
	bool used[10];
	memset(used, 0, sizeof(used));
	while(x) {
		int dg = x % 10;
		if(used[dg]) return 0;
		used[dg] = 1;
		x /= 10;
	}
	return 1;
}

void predo() {
	for(int i = 1; i < N; ++i) {
		a[i] = ok(i);
	}
	sum[0] = 0;
	for(int i = 1; i < N; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
}
int main() {
	int T;
	predo();
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", sum[b] - sum[a - 1]);
	}
	return 0;
}

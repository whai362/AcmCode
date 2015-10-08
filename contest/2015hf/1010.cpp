#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

#define P pair<int, int>
#define X first
#define Y second

const int N = 2 * 1e5 + 5;

P a[N];

bool cmp(P a, P b) {
	return a.X > b.X;
}

void gao(int n) {
	int flag = 1;
	ans.clear();
	for(int i = 0; i < n; ++i) {
		if(a[i].Y <= i) {
			int pos = min(a[i].Y, i - a[i].Y); //
		} else {
			flag = 0;
			break;
		}
	}
	if(flag == 0) {
		puts("impossible");
	} else {
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].X, &a[i].Y);
		}
		sort(a, a + n, cmp);
		printf("Case #%d: ", ++cas);
		gao(n);
	}
	return 0;
}

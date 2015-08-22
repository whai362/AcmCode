#include <iostream>
#include <cstdio>
using namespace std;

#define P pair<int, int>

const int N = 1005;

P a[N];

bool cmp(P a, P b) {
	if(a.X == b.X) {
		return a.Y > b.Y;
	}
	return a.X > b.X;
}

LL dp[N][N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d", &a[i].X, &a[i].Y);
		}
	}
	sort(a, a + n, cmp);
	
	for(int i = 0; i < 


}

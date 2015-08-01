#include <iostream>
#include <cstdio>
using namespace std;
int maxx[N];
int a[N];
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		build(0, n-1, 1);
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i) {
			int op;
			scanf("%d", &op);
			if(op == 1) {
				
			}
		}
	}
}

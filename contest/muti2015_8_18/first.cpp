#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct E {
	int u, v, c;
}e[10000];
int tot;

bool cmp(E a, E b) {
	return a.c > b.c;
}

int fa[100];
void init_bcj() {
	for(int i = 0; i <= 100; ++i)
		fa[i] = i;
}

int get_fa(int x) {
	if(x != fa[x]) return fa[x] = get_fa(fa[x]);
	return x;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		tot = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				e[tot].u = i;
				e[tot].v = j;
				e[tot++].c = __gcd(i, j);
			}
		}

		sort(e, e + tot, cmp);

		init_bcj();

		int ans = 0;

		int cnt = 0;

		for(int i = 0; i < tot; ++i) {
			int fu = get_fa(e[i].u);
			int fv = get_fa(e[i].v);
			if(fu == fv) continue;
			fa[fv] = fu;
			ans += e[i].c;
			//cout<<e[i].u<<','<<e[i].v<<','<<e[i].c<<' ';
			//cout<<e[i].c<<' ';
			++cnt;
			if(cnt == n - 1) break;
		}
		cout<<ans<<endl;
	}

	return 0;
}

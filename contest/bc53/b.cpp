#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define PB push_back

const int N = 1005;

int G[N][N];
int du[N];
int fa[N];
int get_fa(int x) {
	if(x != fa[x]) return fa[x] = get_fa(fa[x]);
	return x;
}

int u[N], v[N];
bool ok(int id, int n) {
	int c1 = 0;
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
	for(int i = 0; i < n; ++i) {
		if(i == id) continue;
		int fu = get_fa(u[i]);
		int fv = get_fa(v[i]);
		if(fu == fv) continue;
		fa[fv] = fu;
	}
	int ac = get_fa(1);
	for(int i = 1; i <= n; ++i) {
		if(du[i] > 2) return false;
		if(get_fa(i) != ac) return false;
		if(du[i] == 1) ++c1;
		if(c1 > 2) return false;
	}
	if(c1 == 2) return true;
	return false;
}

bool gao(int n) {
	if(n == 1) return true;
	for(int i = 0; i < n; ++i) {
		--du[u[i]];
		--du[v[i]];
		if(ok(i, n)) return true;
		++du[u[i]];
		++du[v[i]];
	}
	return false;
}

void init(int n) {
	memset(du, 0, sizeof(du));
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		init(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &u[i], &v[i]);
			++du[u[i]];
			++du[v[i]];
		}
		if(gao(n)) puts("YES");
		else puts("NO");
	}
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e6 + 5;

int fa[N];

int cnt[N];

int get_fa(int x) {
	if(x != fa[x]) return fa[x] = get_fa(fa[x]);
	return x;
}

int main() {
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; ++i)
		fa[i] = i;

	for(int i = 1; i <= n; ++i) {
		int u, v;
		v = i;
		scanf("%d", &u);
		int fu, fv;
		fu = get_fa(u);
		fv = get_fa(v);
		if(fu == fv) continue;
		fa[fv] = fu;
	}

	int ans = 0;

	for(int i = 1; i <= n; ++i) {
		int f = get_fa(i);
		//cout<<i<<' '<<f<<endl;
		if(cnt[f] == 0) ++ans;
		++cnt[f];
	}
	cout<<ans<<endl;
	return 0;
}

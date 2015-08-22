#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

const int N = 105;
map<string, int> mp;
string n1[N], n2[N];
int tot;

int fa[N], r[N];
int get_fa(int x) {
	if(x != fa[x]) {
		int tmp = fa[x];
		fa[x] = get_fa(fa[x]);
		r[x] = r[tmp] ^ r[x];
		return fa[x];
	}
	return x;
}

void gao(int n) {
	for(int i = 0; i < n; ++i) {
		int u = mp[n1[i]], v = mp[n2[i]];
		int fu = get_fa(u), fv = get_fa(v);
		if(fu == fv) {
			if(r[u] == r[v]) {
				puts("No");
				return ;
			}
		} else {
			fa[fv] = fu;
			r[fv] = r[u] ^ r[v] ^ 1;
		}
	}
	puts("Yes");
}

void init(int n) {
	mp.clear();
	tot = 0;
}

int main() {
	int T;
	cin>>T;
	int cas = 0;
	while(T--) {
		int n;
		cin>>n;
		init(n);
		for(int i = 0; i < n; ++i) {
			cin>>n1[i]>>n2[i];
			if(mp[n1[i]] == 0) {
				mp[n1[i]] = ++tot;
			}
			if(mp[n2[i]] == 0) {
				mp[n2[i]] = ++tot;
			}
		}
		for(int i = 0; i <= tot; ++i) {
			fa[i] = i;
			r[i] = 0;
		}
		printf("Case #%d: ", ++cas);
		gao(n);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int N = 105;
#define LL __int64

int fa[N];
int cnt[N];
int get_fa(int x) {
	if(x != fa[x]) return fa[x] = get_fa(fa[x]);
	return x;
}

void init_bcj(int n) {
	for(int i = 0; i <= n; ++i) {
		fa[i] = i;
		cnt[i] = 1;
	}
}

LL gao(string str) {
	init_bcj(str.length());
	for(int i = 0; i < str.length(); ++i) {
		for(int j = i + 1; j < str.length(); ++j) {
			int u = str[i] - '0';
			int v = str[j] - '0';
			if(u > v) continue;
			int fu = get_fa(u);
			int fv = get_fa(v);
			if(fu == fv) continue;
			fa[fv] = fu;
			cnt[fu] += cnt[fv];
			cnt[fv] = 0;
		}
	}
	LL ret = 1;
	for(int i = 1; i <= str.length(); ++i) {
		if(cnt[i]) ret *= cnt[i];
	}
	return ret * ret;
}

int main() {
	string str = "1234567";
	LL ans = gao(str);
	while(next_permutation(str.begin(), str.end())) {
		ans += gao(str);
	}
	cout<<ans<<endl;
	return 0;
}

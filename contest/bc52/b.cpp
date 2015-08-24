#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL __int64

const int N = 5 * 1e4 + 5;
int w[N];

int cnt[N];

LL Cn3(int n) {
	if(n < 3) return 0;
	LL ret = (LL)n * (n - 1) * (n - 2) / 6;
	return ret;
}

void gao(int n, int m) {
	for(int i = 1; i <= n; ++i)
		cnt[i] += cnt[i - 1];
	if(m < 3) {
		puts("0");
		return ;
	}
	LL fm = 0;
	for(int i = 1; i <= n; ++i) {
		fm += Cn3(cnt[i]) * w[i];
	}
	LL fz = Cn3(m);
	LL d = __gcd(fm, fz);

	fm /= d;
	fz /= d;
	if(fz == 1) cout<<fm<<endl;
	else cout<<fm<<'/'<<fz<<endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &w[i]);
		}
		for(int i = 0; i < m; ++i) {
			int l, r;
			scanf("%d%d", &l, &r);
			++cnt[l];
			--cnt[r + 1];
		}
		gao(n, m);
	}
	return 0;
}

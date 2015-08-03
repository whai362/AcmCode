#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000;
int b[1000000];
int deal(int x, int n, int a) {
	int ret = 0;
	for(int i = 0; i < n; ++i) {
		if(x & (1 << i)){
			a %= b[i];
			++ret;
		}
	}
	if(a == 0) return ret;
	return INF;
}

bool cmp(int a, int b) {
	return a > b;
}

void gao(int n, int a) {
	sort(b, b+n, cmp);
	int lim = (1 << n);
	int ans = INF;
	for(int i = 0; i < lim; ++i) {
		ans = min(ans, deal(i, n, a));
	}
	if(ans != INF) cout<<ans<<endl;
	else cout<<-1<<endl;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, a;
		scanf("%d%d", &n, &a);
		for(int i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		gao(n, a);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define LL __int64
const int N = 1e5 + 5;
LL a[N];
LL s[N];
LL cnt[N];

int mylog(LL x) {
	int l = 0, r = 40;
	while(l + 1 < r) {
		int mid = (l + r) >> 1;
		if((1LL << mid) <= x)
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}

int fun(LL x) {
	if(x == 0) return 1;
	return mylog(x) + 1;
}
bool acba(int S, LL &la, LL &lb, int r) {
	if(fun(s[r]) < S) return false;
	while(la < r && fun(s[r] - s[la]) > S) ++la;
	while(lb < r && fun(s[r] - s[lb]) >= S) ++lb;
	if(la == r) return false;
	if(lb > 0) --lb;
	//if(lb == r) || fun(s[r] - s[lb]) < S) --lb;
	return true;
}
int deal(int S, int n) {
	LL la = 0, lb = 0;
	LL ret = 0;
	for(int i = 1; i <= n; ++i) {
		if(!acba(S, la, lb, i)) continue;
		if(lb < la || fun(s[i] - s[la]) != S) continue;
		ret += (la + 1 + lb + 1) * (lb - la + 1) / 2 + (lb - la + 1) * i;
	}
	return ret;
}
void gao(int n) {
	s[0] = 0;
	for(int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1; i <= 40; ++i) {
		cnt[i] = deal(i, n);
	}
	LL ans = 0;
	for(int i = 1; i <= 40; ++i) {
		ans += cnt[i] * i;
	}
	printf("%I64d\n", ans);
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%I64d", &a[i]);
		}
		gao(n);
	}
	return 0;
}

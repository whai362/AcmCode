#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

#define LL long long

set<LL> myset;
set<LL> :: iterator it;

LL _abs(LL x) {
	if(x < 0) return -x;
	return x;
}

int main() {
	int n;
	scanf("%d", &n);
	LL ans = 0;
	for(int i = 0; i < n; ++i) {
		LL x;
		if(scanf("%lld", &x) == EOF) x = 0;
		if(i == 0) {
			ans += x;
		} else {
			it = myset.lower_bound(x);
			if(it == myset.end()) {
				--it;
			} else if(it != myset.begin()) {
				LL v1 = (*it);
				--it;
				LL v2 = (*it);
				if(_abs(v1 - x) < _abs(v2 - x))
					++it;
			}
			ans += _abs((*it) - x);
		}
		myset.insert(x);
	}
	cout<<ans<<endl;
	return 0;
}

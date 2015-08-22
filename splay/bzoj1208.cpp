#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
#define LL long long

const int MOD = 1000000;

set<LL> pet, peo;
set<LL> :: iterator it;

LL _abs(LL x) {
	if(x < 0) return -x;
	return x;
}

void gao(LL &ans) {
	if(pet.size() == 0 || peo.size() == 0) return ;
	else if(pet.size() == 1) {
		it = pet.begin();
		LL v = (*it);
		pet.erase(it);
		it = peo.lower_bound(v);
		if(it == peo.end()) {
			--it;
		} else if(it == peo.begin()) {
		} else {
			LL p_v1 = (*it);
			--it;
			LL p_v2 = (*it);
			if(_abs(p_v1 - v) < _abs(p_v2 - v))
				++it;
		}
		//cout<<(*it)<<' '<<v<<endl;
		ans = (ans + _abs((*it) - v)) % MOD;
		peo.erase(it);
	} else {
		it = peo.begin();
		LL p_v = (*it);
		peo.erase(it);
		it = pet.lower_bound(p_v);
		if(it == pet.end()) {
			--it;
		} else if(it == pet.begin()) {
		} else {
			LL v1 = (*it);
			--it;
			LL v2 = (*it);
			if(_abs(v1 - p_v) < _abs(v2 - p_v))
				++it;
		}
		//cout<<p_v<<' '<<(*it)<<endl;
		ans = (ans + _abs((*it) - p_v)) % MOD;
		pet.erase(it);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	LL ans = 0;
	for(int i = 0; i < n; ++i) {
		int u;
		LL v;
		scanf("%d%lld", &u, &v);
		if(u == 0) {
			pet.insert(v);
		} else {
			peo.insert(v);
		}
		gao(ans);
	}
	cout<<ans<<endl;
}

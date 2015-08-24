#include <iostream>
#include <cstdio>
using namespace std;

#define LL __int64

LL cal(LL a, LL remain) {
	if(a < remain) return 0;
	return remain - 1;
}

LL gao(LL l) {
	LL ret = (l - 1) * (l - 2) / 2;
	for(int i = 1; i < l; ++i) {
		ret -= 3 * cal(i, l - i);
	}
	return ret;
}

int main() {
	int l;
	while(cin>>l) {
		cout<<gao(l)<<endl;
	}
}

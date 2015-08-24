#include <iostream>
#include <cstdio>
using namespace std;

#define LL __int64

LL gao(int l){
	LL ret=0;
	for(int i=1;2*i<l;++i) {
		ret+=(l-1)/2-(l/2-i);
	}
	return ret;
}

int main() {
	int l;
	while(cin>>l) {
		cout<<gao(l)<<endl;
	}
	return 0;
}


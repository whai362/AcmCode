#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define LL __int64

int main() {
	
	LL T, S, q;

	cin>>T>>S>>q;

	int ans = 0;
	while(1) {
		if(S < T) ++ans;
		else break;
		S *= q;
	}
	cout<<ans<<endl;
	return 0;
}

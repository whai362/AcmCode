#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define LL __int64

int main() {
	LL T, S, q;
	cin>>T>>S>>q;
	T *= q;
	S *= q;

	LL st = 0;
	LL hv = S;
	
	int ans = 1;

	while(1) {
		while(st < T && st <= hv) {
			st += q;
			hv += q - 1;
		}
		if(st >= T && st <= hv) {
			break;
		} else {
			++ans;
			st = 0;
			hv -= q - 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

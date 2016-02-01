#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 1000000007;

int main() {
	int n, m;
	cin>>n>>m;
	long long ans = 1;
	if(n % 3 == 0) {
		n /= 3;
		for(int i = 0; i < n; ++i) {
			ans = ans * m % MOD;
		}
		cout<<ans<<endl;
	} else {
		cout<<0<<endl;
	}

	return 0;
}

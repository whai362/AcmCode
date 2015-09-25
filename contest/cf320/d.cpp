#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define LL __int64

const int N = 1e5 + 5;

char str[N];

int main() {
	int n, m;
	cin>>n>>m;
	cin>>str;

	LL ans = 0;


	for(int i = 0; i < n; ++i) {
		ans += m - 1;
		if(str[i] != str[i + 1]) {
			ans += (LL)(m - 1) * (n - i - 1);
		}
		if(i && str[i] != str[i - 1]) {
			ans += (LL)(m - 1) * i;
		}
	}
	cout<<ans<<endl;

	return 0;
}

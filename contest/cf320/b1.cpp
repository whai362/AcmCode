#include <iostream>
#include <cstdio>
using namespace std;
#define LL __int64
const int N = 2 * 1e5 + 5;

LL a[N];

LL pre[N], bac[N];

int main() {
	int n, k, x;
	cin>>n>>k>>x;
	for(int i = 1; i <= n; ++i) {
		cin>>a[i];
	}
	pre[1] = a[1];
	for(int i = 2; i <= n; ++i) {
		pre[i] = pre[i - 1] | a[i];
	}
	bac[n] = a[n];
	for(int i = n - 1; i > 0; --i) {
		bac[i] = bac[i + 1] | a[i];
	}

	LL ans = 0;

	for(int i = 1; i <= n; ++i) {
		LL tmp = a[i];
		for(int j = 0; j <=k; ++j) {
			LL jie = (pre[i - 1] | tmp) | bac[i + 1];
			//cout<<tmp<<endl;
			ans = max(ans, jie);
			tmp *= x;
		}
	}
	cout<<ans<<endl;
}

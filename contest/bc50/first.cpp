#include <iostream>
#include <cstdio>
using namespace std;
bool ok(int x, int n) {
	int a[30], tot = 0;
	for(int i = 0; i < n; ++i) {
		if(x & (1 << i)) a[tot++] = i;
	}
	for(int i = 1; i < tot; ++i) {
		if(a[i] - a[i - 1] <= 2) return false;
	}
	return true;
}
int main() {
	int n;
	while(cin>>n) {
	int lim = (1 << n);
	int ans = 0;
	for(int i = 1; i < lim; ++i) {
		if(ok(i, n)){  ++ans; }
	}
	cout<<ans<<endl;
	}
	return 0;
}

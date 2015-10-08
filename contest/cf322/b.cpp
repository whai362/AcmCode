#include <iostream>
#include <cstdio>
using namespace std;

#define LL __int64

const int N = 1e5 + 5;

LL a[N];
LL ans[N];
int main() {
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	LL maxx = 0;
	for(int i = n - 1; i >= 0; --i) {
		if(a[i] > maxx) ans[i] = 0;
		else ans[i] = maxx + 1 - a[i];
		maxx = max(maxx, a[i]);
	}
	for(int i = 0; i < n; ++i) {
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}

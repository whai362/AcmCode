#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int N = 105;
string na[N], so[N];
int a[N];

map<string, int> mp;

void gao(int n) {
	int ans = 0;
	//for(int i = 0; i < n; ++i) {
	//	cout<<a[i]<<' ';
	//}
	//cout<<endl;
	for(int i = 1; i < n; ++i) {
		int p = i;
		if(a[p] < a[p - 1]) {
			++ans;
			while(p > 0 && a[p] < a[p - 1]) {
				swap(a[p], a[p - 1]);
				--p;
			}
		}
	}
	//for(int i = 0; i < n; ++i) {
	//	cout<<a[i]<<' ';
	//}
	//cout<<endl;
	cout<<ans<<endl;
}

int main() {
	int T;
	cin>>T;
	int cas = 0;
	while(T--) {
		int n;
		mp.clear();
		cin>>n;
		getchar();
		for(int i = 0; i < n; ++i) {
			getline(cin, na[i]);
			so[i] = na[i];
		}
		sort(so, so + n);
		for(int i = 0; i < n; ++i) {
			mp[so[i]] = i + 1;
		}
		for(int i = 0; i < n; ++i) {
			a[i] = mp[na[i]];
		}
		printf("Case #%d: ", ++cas);
		gao(n);
	}
	return 0;
}

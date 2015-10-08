#include <iostream>
#include <cstdio>
using namespace std;

const int N =  1e5 + 5;

bool vis[N];
bool used[N];
bool have[N];
int a[N];
int main() {

	int n;
	cin>>n;
	for(int i = 0; i < n; ++i) {
		cin>>a[i];
		if(a[i] <= n) vis[a[i]] = 1;
	}
	for(int i = 0; i < n; ++i) {
		if(vis[a[i]] == 1) {
			used[i] = 1;
			have[a[i]] = 1;
			vis[a[i]] = 0;
		}
	}
	//for(int i = 1; i <= 4; ++i) {
	//	cout<<have[i]<<' ';
	//}
	//cout<<endl;

	int p = 0;
	for(int i = 1; i <= n; ++i) {
		if(have[i]) continue;
		while(p < n && used[p]) ++p;
		a[p] = i;
		++p;
	}
	for(int i = 0; i < n; ++i) {
		cout<<a[i]<<' ';
	}
	cout<<endl;
}

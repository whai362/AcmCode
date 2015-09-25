#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string A = "c";
string B = "ff";
string nxt;
int p[105], tot;
int main() {
	int n;
	cin>>n;
	for(int i = 3; i <= n; ++i) {
		nxt = A + B;
		A = B;
		B = nxt;
	}
	cout<<nxt<<endl;
	tot = 0;
	for(int i = 0; i < nxt.length() - 2; ++i) {
		if(nxt[i] == 'c' && nxt[i + 1] == 'f' && nxt[i + 2] == 'f') {
			p[tot++] = i;
		}
	}
	for(int i = 0; i < tot; ++i) {
		cout<<p[i]<<' ';
	}
	cout<<endl;
	int ans = 0;
	for(int i = 0; i < tot; ++i) {
		for(int j = i + 1; j < tot; ++j) {
			ans += p[j] - p[i];
		}
	}
	cout<<ans<<endl;

}

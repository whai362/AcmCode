#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string str;

int gao(int x, char ch) {
	int ret = 0;
	for(int i = 0; i < x; ++i) {
		if(str[i] == ch) ++ret;
	}
	return ret;
}

int main() {
	cin>>str;
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < n; ++i) {
		int k;
		cin>>k;
		string tmp = str;
		for(int j = tmp.length() - k; j < tmp.length(); ++j) {
			str += tmp[j];
		}
		for(int j = 0; j < tmp.length() - k; ++j) {
			str += tmp[j];
		}
	}
	cout<<str<<endl;
	for(int i = 0; i < m; ++i) {
		int l, r;
		char ch;
		cin>>l>>r>>ch;
		cout<<gao(r, ch)<<' '<<gao(l - 1, ch)<<endl;
	}
}

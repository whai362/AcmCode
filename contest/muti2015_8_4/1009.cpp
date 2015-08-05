#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	
	for(int n = 1; n < 15; ++n) {
		string A = "b";
		string B = "a";
		//cout<<A<<endl;
		//cout<<B<<endl;
		string tmp;
		for(int i = 0; i < n; ++i) {
			tmp = B + A;
			//cout<<tmp<<endl;
			A = B;
			B = tmp;
		}
		for(int i = 1; i <tmp.length(); ++i) {
			int ans = 0;
			for(int j = 1; j <= i; ++j) {
				int flag = 1;
				for(int k = j; k <= i; ++k) {
					if(tmp[k] != tmp[k - j]) {
						flag = 0;
						break;
					}
				}
				if(flag) {
					ans = i - j + 1;
					break;
				}
			}
			cout<<ans<<' ';
		}
		cout<<endl;
	}
}

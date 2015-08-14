#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main() {
	cout<<3<<endl;
	for(int i = 0; i < 3; ++i) {
	int n = 10000;
	cout<<n<<endl;
	for(int i = 0; i < n; ++i) {
		cout<<(rand() % n + 1) * (rand() % n + 1)<<' ';
	}
	cout<<endl;
	cout<<n<<endl;
	for(int i = 0; i < n; ++i) {
		int l = rand() % n + 1;
		int r = rand() % n + 1;
		if(l > r) swap(l, r);
		cout<<l<<' '<<r<<endl;
	}
	cout<<endl;
	}
}

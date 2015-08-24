#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n = 10000;
	int m = 2000;
	cout<<n<<' '<<m<<endl;
	for(int i = 0; i < n; ++i) {
		printf("5%c", i == n - 1 ? '\n' : ' ');
	}
	for(int i = 0; i < m; ++i) {
		cout<<1<<' '<<n<<endl;
	}
}

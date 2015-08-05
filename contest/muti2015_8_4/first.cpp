#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	int m;
	int z;
	int l;
	cin>>n>>m>>z>>l;
	int now = 0;
	for(int i = 0; i < 20; ++i) {
		cout<<now<<' ';
		now = (now*m + z) % l;
	}
	cout<<endl;
	return 0;
}

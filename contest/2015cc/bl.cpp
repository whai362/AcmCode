#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

int main() {
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	for(int i = 2; a.size() < 1000; ++i) {
		for(int j = 0; j < a[i]; ++j) {
			a.push_back(i + 1);
		}
	}
	//for(int i = 0; i < 100; ++i) {
	//	cout<<a[i]<<' ';
	//}
	//cout<<endl;
	int n;
	while(cin>>n) {
		int p = upper_bound(a.begin(), a.end(), n) - a.begin();
		p = upper_bound(a.begin(), a.end(), p) - a.begin();
		cout<<p<<endl;
	}
}

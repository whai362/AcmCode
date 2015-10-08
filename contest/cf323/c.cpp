/*===================================================================
# Author: whai
#
# Last modified: 2015-10-04 01:09
#
# Filename: c.cpp
===================================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 505;

multiset<int> myset;
multiset<int> :: iterator it;
int a[N * N];
vector<int> ans;
int main() {
	int n;
	cin>>n;
	for(int i = 0; i < n * n; ++i) {
		cin>>a[i];
		myset.insert(a[i]);
	}
	for(int i = 0; i < n; ++i) {
		it = myset.end();
		--it;
		int x = (*it);
		myset.erase(it);
		for(int j = 0; j < ans.size(); ++j) {
			int d = __gcd(ans[j], x);
			myset.erase(myset.find(d));
			myset.erase(myset.find(d));
		}
		ans.PB(x);
	}
	for(int i = 0; i < n; ++i) {
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}


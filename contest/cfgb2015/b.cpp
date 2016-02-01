/*======================================================
# Author: whai
# Last modified: 2015-12-30 23:17
# Filename: b.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

vector<LL> a;
set<LL> used;

void predo() {
	for(int i = 1; i < 62; ++i) {
		LL all1 = 0;
		for(int j = 0; j < i; ++j) {
			all1 = all1 * 2 + 1;
		}
		for(int j = 0; j < i - 1; ++j) {
			LL tmp = all1 - (1LL << j);
			if(used.find(tmp) == used.end()) {
				a.PB(tmp);
				used.insert(tmp);
			}
		}
	}
	sort(a.begin(), a.end());
	//for(int i = 0; i < a.size(); ++i) {
	//	cout<<a[i]<<' ';
	//}
	//cout<<endl;
}

int main() {
	predo();
	LL L, R;
	while(cin>>L>>R) {
		int ans = 0;
		for(int i = 0; i < a.size(); ++i) {
			if(a[i] >= L && a[i] <= R) {
				//cout<<a[i]<<' ';
				++ans;
			}
		}
		//cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}


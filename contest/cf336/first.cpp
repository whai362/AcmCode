/*======================================================
# Author: whai
# Last modified: 2015-12-25 18:02
# Filename: first.cpp
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

const int N = 1005;

int maxx[N];

int main() {
	int n, s;
	while(cin>>n>>s) {
		for(int i = 0; i < n; ++i) {
			int f, t;
			cin>>f>>t;
			maxx[f] = max(maxx[f], t);
		}
		int ans = -1;
		for(int i = s; i >= 0; --i) {
			ans = max(ans + 1, maxx[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}


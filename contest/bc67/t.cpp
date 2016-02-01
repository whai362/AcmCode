/*======================================================
# Author: whai
# Last modified: 2015-12-26 20:48
# Filename: t.cpp
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

int a[105][105];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, m;
		cin>>n>>m;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				cin>>a[i][j];
			}
		}
		int ans = 0;
		if((n & 1) || (m & 1)) {
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= m; ++j) {
					ans += (a[i][j] ^ 1);
				}
			}
			ans &= 1;
			if(ans) puts("no");
			else puts("yes");
		} else {
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= m; ++j) {
					ans += (a[i][j] ^ 1);
				}
			}
			ans &= 1;
			if(!ans) puts("no");
			else puts("yes");

		}
	}
	return 0;
}


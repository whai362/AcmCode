/*======================================================
# Author: whai
# Last modified: 2015-11-16 00:29
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

P a[5];

int _abs(int x) {
	if(x < 0) return -x;
	return x;
}

int main() {
	int n;
	while(cin>>n) {
		for(int i = 0; i < n; ++i) {
			cin>>a[i].X>>a[i].Y;
		}
		if(n == 1) {
			puts("-1");
		} if(n >= 2) {
			int ans = 0;
			for(int i = 0; i < n; ++i) {
				for(int j = i + 1; j < n; ++j) {
					int w = _abs(a[i].X - a[j].X);
					int h = _abs(a[i].Y - a[j].Y);
					ans = max(w * h, ans);
				}
			}
			if(ans == 0) {
				puts("-1");
			} else {
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}


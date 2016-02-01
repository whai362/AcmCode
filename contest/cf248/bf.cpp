/*======================================================
# Author: whai
# Last modified: 2015-12-08 11:39
# Filename: bf.cpp
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

int a[N], b[N];

int _abs(int x) {
	if(x < 0) return -x;
	return x;
}

int deal(int n) {
	int ret = 0;
	for(int i = 1; i < n; ++i) {
		ret += _abs(a[i] - a[i - 1]);
	}
	return ret;
}

int main() {
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; ++i) {
		cin>>a[i];
		b[i] = a[i];
	}
	int ans = 100005;
	for(int i = 1; i <= n; ++i) {
		//cout<<i<<':';
		for(int j = 1; j <= n; ++j) {
			//if(i == j) continue;
			for(int k = 0; k < m; ++k) {
				if(a[k] == i) {
					a[k] = j;
				}
			}
			//cout<<deal(m)<<' ';
			ans = min(ans, deal(m));
			for(int k = 0; k < m; ++k) {
				a[k] = b[k];
			}
		}
		//cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

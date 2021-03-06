/*======================================================
# Author: whai
# Last modified: 2015-11-10 21:19
# Filename: bl.cpp
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

int cnt[100];

int main() {
	int n, m;
	cin>>n>>m;
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			ans += (__gcd(i, j) - 1) * 2 + 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}


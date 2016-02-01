/*======================================================
# Author: whai
# Last modified: 2016-01-31 22:16
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

const int N = 1e3 + 5;

int G[N][N];

LL shu0(int x, int y) {
	LL ret = 0;
	int dx = 1, dy = 1;
	while(x <= 1000 && y <= 1000) {
		ret += G[x][y];
		x += dx;
		y += dy;
	}
	return ret;
}

LL shu1(int x, int y) {
	LL ret = 0;
	int dx = 1, dy = -1;
	while(x <= 1000 && y >= 0) {
		ret += G[x][y];
		x += dx;
		y += dy;
	}
	return ret;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		memset(G, 0, sizeof(G));
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x; --y;
			++G[x][y];
		}
		LL ans = 0;
		for(int i = 0; i <= 1000; ++i) {
			LL cnt = shu0(0, i);
			ans += cnt * (cnt - 1) / 2;
		}
		for(int i = 1; i <= 1000; ++i) {
			LL cnt = shu0(i, 0);
			ans += cnt * (cnt - 1) / 2;
		}
		for(int i = 0; i <= 1000; ++i) {
			LL cnt = shu1(0, i); 
			ans += cnt * (cnt - 1) / 2;
		}
		for(int i = 1; i <= 1000; ++i) {
			LL cnt = shu1(i, 1000);
			ans += cnt * (cnt - 1) / 2;
		}
		cout<<ans<<endl;
	}
	return 0;
}


/*======================================================
# Author: whai
# Last modified: 2015-11-16 00:47
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

const int N = 2 * 1e5 + 5;

int a[N];

int _abs(int x) {
	if(x < 0) return -x;
	return x;
}

void gao(int n) {
	LL ans = _abs(a[0]);
	int now = a[0];
	for(int i = 1; i < n; ++i) {
		if(a[i] > now) {
			ans += (LL)a[i] - now;
		} else {
			ans += (LL)now - a[i];
		}
		now = a[i];
	}
	cout<<ans<<endl;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}

		gao(n);
	}
	return 0;
}

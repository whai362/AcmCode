/*======================================================
# Author: whai
# Last modified: 2015-11-01 12:35
# Filename: 1007.cpp
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 105;

P a[N];

vector<LL> b;

LL sqr(LL x) {
	return x * x;
}

LL dis(P a, P b) {
	return sqr(a.X - b.X) + sqr(a.Y - b.Y);
}

bool gao(int n) {
	if(n != 4) {
		return false;
	}
	b.clear();
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			b.PB(dis(a[i], a[j]));
		}
	}
	sort(b.begin(), b.end());
	//for(int i = 0; i < b.size(); ++i) {
	//	cout<<b[i]<<' ';
	//}
	//cout<<endl;
	for(int i = 0; i < 4; ++i) {
		if(b[i] != b[0]) return false;
	}
	for(int i = 4; i < 6; ++i) {
		if(b[i] != 2 * b[0]) return false;
	}
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].X, &a[i].Y);
		}
		if(gao(n)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}

/*======================================================
# Author: whai
# Last modified: 2015-10-20 18:04
# Filename: c.cpp
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

const int N = 1e5 + 5;

LL a[N];

bool ok(LL x, int n, int m) {
	int tmp = m;
	LL sum = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] == 0) continue;
		sum += a[i];
		while(sum + i >= x) {
			sum -= x - i;
			--tmp;
			if(tmp < 0) return false;
		}
	}
	if(tmp == 0) return sum <= 0;
	return true;
}

void gao(int n, int m) {
	LL L = 0, R = n + 5;
	for(int i = 1; i <= n; ++i) {
		R += a[i];
	}
	while(L < R) {
		LL mid = (L + R) >> 1;
		if(ok(mid, n, m)) R = mid;
		else L = mid + 1;
	}

	cout<<L<<endl;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; ++i) {
		scanf("%I64d", &a[i]);
	}

	gao(n, m);
	return 0;
}


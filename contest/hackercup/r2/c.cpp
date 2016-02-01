/*======================================================
# Author: whai
# Last modified: 2016-01-24 03:56
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
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int MOD = 1e9 + 7;
const int N = 200005;

P a[N];

LL sqr(LL x) {
	return x * x;
}

LL _abs(LL x) {
	if(x < 0) return -x;
	return x;
}

LL b[N];
LL c[N];
LL calc(P a[], int n) {
	LL ret = 0;
	for(int i = 0; i < n - 1; ++i) {
		b[i] = _abs(a[i].X - a[i + 1].X);
		//cout<<b[i]<<' ';
	}
	//cout<<endl;

	b[n - 1] = 0;

	LL add = 0;
	for(int i = n - 2; i >= 0; --i) {
		add = (add + b[i + 1] * (n - 2 - i)) % MOD;
		c[i] = 2 * b[i] * add;
		//cout<<c[i]<<' ';
	}
	//cout<<endl;

	for(int i = n - 2; i >= 0; --i) {
		c[i] = (c[i] + c[i + 1]) % MOD;
		//cout<<c[i]<<' ';
		ret = (ret + c[i]) % MOD;
	}
	//cout<<endl;
	//cout<<ret<<endl;

	for(int i = n - 2; i >= 0; --i) {
		b[i] = (sqr(b[i]) * (n - 1 - i) % MOD + b[i + 1]) % MOD;
		
		//cout<<b[i]<<' ';
		ret = (ret + b[i]) % MOD;
	}
	//cout<<endl;

	return ret;
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
		LL ans = 0;
		sort(a, a + n);
		cout<<calc(a, n)<<endl;
	}

	return 0;
}


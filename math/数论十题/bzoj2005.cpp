/*======================================================
# Author: whai
# Last modified: 2015-11-15 20:50
# Filename: bzoj2005.cpp
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;
int mu[N];
void getMu() {
	for(int i = 1; i < N; ++i) {
		int target = i == 1 ? 1 : 0;
		int delta = target - mu[i];
		mu[i] = delta;
		for(int j = 2 * i; j < N; j += i)
			mu[j] += delta;
	}
}

LL gao(int d, LL n, LL m) {
	LL ret = 0;
	n /= d, m /= d;
	for(int i = 1; i <= min(n, m); ++i) {
		ret += mu[i] * (n / i) * (m / i);
	}
	return ret;
}

int main() {
	getMu();
	int n, m;
	scanf("%d%d", &n, &m);
	LL ans = 0;
	for(int i = 1; i <= min(n, m); ++i) {
		ans += gao(i, n, m) * i;
	}
	cout<<ans * 2 - (LL)n * m<<endl;
	return 0;
}


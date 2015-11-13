/*======================================================
# Author: whai
# Last modified: 2015-11-03 15:51
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
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 2 * 1e3 + 5;
int a[N];
unordered_map<LL, int> cnt;
unordered_map<LL, int> :: iterator it;

void deal(LL x) {
	for(LL i = 1; i * i <= x; ++i) {
		if(x % i == 0) {
			++cnt[i];
			int tmp = x / i;
			if(i != tmp) {
				++cnt[tmp];
			}
		}
	}
}

LL ans[N];


void gao(int n) {
	LL sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += a[i];
		deal(sum);
	}
	for(it = cnt.begin(); it != cnt.end(); ++it) {
		ans[(*it).Y] = max(ans[(*it).Y], (*it).X);
	}
	for(int i = n; i > 0; --i) {
		ans[i - 1] = max(ans[i - 1], ans[i]);
	}
	for(int i = 1; i <= n; ++i) {
		printf("%I64d\n", ans[i]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	gao(n);
	return 0;
}

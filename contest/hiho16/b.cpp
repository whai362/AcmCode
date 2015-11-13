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
using namespace std;

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 2 * 1e3 + 5;
int a[N];
#define PLL pair<LL, LL>
map<PLL, int> cnt;

LL s[N];
vector<LL> fac;

LL ans[N];

void deal(LL x) {
	for(int i = 0; i < fac.size(); ++i) {
		int tmp = x % fac[i];
		int tmp_k = ++cnt[PLL(fac[i], tmp)];
		ans[tmp_k] = max(ans[tmp_k], fac[i]);
	}
}

void gao(int n) {
	LL sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += a[i];
		s[i] = sum;
	}
	for(LL i = 1; i * i <= sum; ++i) {
		if(sum % i == 0) {
			fac.PB(i);
			LL tmp = sum / i;
			if(tmp != i) {
				fac.PB(tmp);
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		deal(s[i]);
	}
	for(int i = n; i > 0; --i) {
		ans[i - 1] = max(ans[i - 1], ans[i]);
	}
	for(int i = 1; i <= n; ++i) {
		printf("%lld\n", ans[i]);
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

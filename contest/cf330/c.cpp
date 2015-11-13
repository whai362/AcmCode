/*======================================================
# Author: whai
# Last modified: 2015-11-09 01:11
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

const int N = 2 * 1e5 + 5;
const LL INF = 100000000000000LL;
LL a[N];

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%I64d", &a[i]);
		}
		sort(a, a + n);
		LL ans = INF;
		for(int i = 0; i < (n + 1) / 2; ++i) {
			ans = min(ans, a[i + (n - 2) / 2 + 1] - a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}


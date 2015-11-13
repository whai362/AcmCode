/*======================================================
# Author: whai
# Last modified: 2015-10-23 15:09
# Filename: d.cpp
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

const int N = 5 * 1e6 + 5;

int cnt[N];

void predo() {
	for(int i = 2; i < N; ++i) {
		cnt[i] += cnt[i - 1];
	}
}

int main() {
	int T;
	predo();
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", cnt[a] - cnt[b]);
	}
	return 0;
}



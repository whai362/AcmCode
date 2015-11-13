/*======================================================
# Author: whai
# Last modified: 2015-10-28 13:15
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
const int INF = 0x3f3f3f3f;
int p[N];
int a[N];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 2; i <= n; ++i) {
		scanf("%d", &p[i]);
		G[p[i]].PB(i);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	gao(n, k);
	
	return 0;
}


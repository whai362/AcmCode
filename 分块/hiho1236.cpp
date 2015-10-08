/*======================================================
# Author: whai
#
# Last modified: 2015-10-05 21:28
#
# Filename: hiho1236.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int j = 1; j <= n; ++j) {
			for(int i = 1; i <= 5; ++i) {
				scanf("%d", &a[i][j]);
				score[i][j].X = a[i][j];
				score[i][j].Y = j;
			}
		}
		for(int i = 1; i <= 5; ++i) {
			sort(score[i] + 1, s[i] + n + 1);
			sort(a[i] + 1, a[i] + n + 1);
		}
		int SZ = sqrt(n);
		int bl = n / SZ;
		if(n % sz) ++bl;


	}
	return 0;
}


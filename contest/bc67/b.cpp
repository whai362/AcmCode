/*======================================================
# Author: whai
# Last modified: 2015-12-26 19:43
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
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1005;

int a[N][N];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, m;
		cin>>n>>m;
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
				if(a[i][j]) ++cnt;
			}
		}
		cnt %= 2;
		int ans = ((n + m - 1) % 2) ^ cnt;
		if(ans == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}


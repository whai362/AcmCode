/*======================================================
# Author: whai
# Last modified: 2015-12-10 15:17
# Filename: b2.cpp
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

const int N = 505;

const int M = 1e5 + 5;

bool used[N][N];
char str[M];
int ans[M];

int main() {
	int n, m, x0, y0;

	while(scanf("%d%d%d%d", &n, &m, &x0, &y0) != EOF) {
		memset(used, 0, sizeof(used));
		scanf("%s", str);
		int len = strlen(str);
		ans[0] = 1;
		used[x0][y0] = 1;
		int nowx = x0, nowy = y0;
		int cnt = 1;
		for(int i = 0; i < len - 1; ++i) {
			int tmpx = nowx, tmpy = nowy;
			if(str[i] == 'U') {
				if(tmpx > 1) --tmpx;
			} else if(str[i] == 'D') {
				if(tmpx < n) ++tmpx;
			} else if(str[i] == 'L') {
				if(tmpy > 1) --tmpy;
			} else if(str[i] == 'R') {
				if(tmpy < m) ++tmpy;
			}
			if(used[tmpx][tmpy]) ans[i + 1] = 0;
			else {
				++cnt;
				ans[i + 1] = 1;
				used[tmpx][tmpy] = 1;
			}
			nowx = tmpx, nowy = tmpy;
		}
		ans[len] = n * m - cnt;
		for(int i = 0; i <= len; ++i) {
			printf("%d ", ans[i]);
		}
		puts("");
	}

	return 0;
}


/*======================================================
# Author: whai
# Last modified: 2015-10-12 17:39
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

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1000;

int a[2][N], b[N];

int pre[2][N];
int bac[2][N];
int ans[N];
int main() {
	int n;
	
	scanf("%d", &n);
	for(int i = 0; i < 2; ++i) {
		for(int j = 1; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	for(int i = 0; i < 2; ++i) {
		for(int j = 1; j < n; ++j) {
			pre[i][j] = pre[i][j - 1] + a[i][j];
		}
	}

	for(int i = 0; i < 2; ++i) {
		for(int j = n - 1; j > 0; --j) {
			bac[i][j] = bac[i][j + 1] + a[i][j];
		}
	}

	for(int i = 1; i <= n; ++i) {
		ans[i] = pre[0][i - 1] + bac[1][i] + b[i];
	}
	sort(ans + 1, ans + 1 + n);

	cout<<ans[1] + ans[2]<<endl;

	return 0;
}


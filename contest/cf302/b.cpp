/*======================================================
# Author: whai
# Last modified: 2015-11-07 20:13
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

const int N = 105;

char ans[N][N];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			ans[i][j] = 'S';
		}
	}
	int cnt = 0;
	if(k) {
	for(int i = 0; i < n; ++i) {
		int j = 0 + i % 2;
		for(; j < n; j += 2) {
			ans[i][j] = 'L';
			++cnt;
			if(cnt == k) break;
		}
		if(cnt == k) break;
	}
	}
	if(cnt == k) {
		puts("YES");
		for(int i = 0; i < n; ++i)
			cout<<ans[i]<<endl;
	} else {
		puts("NO");
	}
	return 0;
}


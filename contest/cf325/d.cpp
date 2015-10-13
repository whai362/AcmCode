/*======================================================
# Author: whai
# Last modified: 2015-10-12 18:35
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

int n, k;

char str[5][200];
bool vis[5][200];

bool ok(char c) {
	if(c == '.' || c == 0) return true;
	return false;
}

void gao() {
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < 3; ++i) {
		if(str[i][0] == 's') {
			vis[i][0] = 1;
		}
	}
	int i;
	for(i = 0; i < n; i += 3) {
		for(int j = 0; j < 3; ++j) {
			if(vis[j][i]) {
				if(!ok(str[j][i + 1])) continue;
				for(int k = j - 1; k <= j + 1; ++k) {
					if(0 <= k && k < 3 && ok(str[k][i + 1]) && ok(str[k][i + 2]) && ok(str[k][i + 3]))
						vis[k][i + 3] = 1;
				}
			}
		}
	}
	for(int j = 0; j < 3; ++j) {
		if(vis[j][i]) {
			puts("YES");
			return ;
		}
	}
	puts("NO");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		memset(str, 0, sizeof(str));
		for(int i = 0; i < 3; ++i) {
			scanf("%s", str[i]);
		}
		gao();
	}

	return 0;
}


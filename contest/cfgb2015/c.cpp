/*======================================================
# Author: whai
# Last modified: 2015-12-30 23:33
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
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 505;

char G[N][N];

int sr[N][N];
int sc[N][N];

void gao(int x1, int y1, int x2, int y2) {
	int ans = 0;
	for(int i = x1; i <= x2; ++i) {
		ans += sc[i][y2 - 1] - sc[i][y1 - 1];
	}
	for(int i = y1; i <= y2; ++i) {
		ans += sr[x2 - 1][i] - sr[x1 - 1][i];
	}
	printf("%d\n", ans);
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(sr, 0, sizeof(sr));
		memset(sc, 0, sizeof(sc));
		for(int i = 1; i <= n; ++i) {
			scanf("%s", G[i] + 1);
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m - 1; ++j) {
				if(G[i][j] == '.' && G[i][j + 1] == '.') {
					sc[i][j] = 1;
				}
			}
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m - 1; ++j) {
				sc[i][j + 1] += sc[i][j];
			}
		}
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n - 1; ++j) {
				if(G[j][i] == '.' && G[j + 1][i] == '.') {
					sr[j][i] = 1;
				}
			}
		}
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n - 1; ++j) {
				sr[j + 1][i] += sr[j][i];
			}
		}

		//for(int i = 1; i <= n; ++i) {
		//	for(int j = 1; j <= m; ++j) {
		//		cout<<sc[i][j]<<' ';
		//	}
		//	cout<<endl;
		//}
		//cout<<endl;
		//for(int i = 1; i <= n; ++i) {
		//	for(int j = 1; j <= m; ++j) {
		//		cout<<sr[i][j]<<' ';
		//	}
		//	cout<<endl;
		//}

		int q;
		scanf("%d", &q);
		for(int i = 0; i < q; ++i) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			gao(x1, y1, x2, y2);
		}
	}
	return 0;
}


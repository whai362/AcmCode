/*======================================================
# Author: whai
# Last modified: 2015-10-25 18:29
# Filename: e.cpp
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
using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second
#define MP make_pair

const int N = 1005;

char str[N][N];

bool used[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ok(int x, int y, int n, int m) {
	if(x >= 0 && x < n && y >= 0 && y < m && str[x][y] != '#' && used[x][y] == 0)
		return true;
	return false;
}

int mj[4][1005][1005];

vector<int> gao(int type, int n, int m) {
	memset(used, 0, sizeof(used));
	queue< pair<P, int> > que;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(str[i][j] == type + '0') {
				que.push(MP(P(i, j), 0));
				mj[type][i][j] = 0;
				used[i][j] = 1;
			}
		}
	}
	vector<int> ret;
	ret.PB(N * N); ret.PB(N * N); ret.PB(N * N);
	ret[type - 1] = 0;
	while(!que.empty()) {
		pair<P, int> now = que.front(); que.pop();
		for(int i = 0; i < 4; ++i) {
			int tmpx = now.X.X + dx[i];
			int tmpy = now.X.Y + dy[i];
			if(ok(tmpx, tmpy, n, m)) {
				que.push(MP(P(tmpx, tmpy), now.Y + 1));
				used[tmpx][tmpy] = 1;
				char ch = str[tmpx][tmpy];
				mj[type][tmpx][tmpy] = now.Y;
				if(ch == '1') {
					ret[0] = min(ret[0], now.Y);
				} else if(ch == '2') {
					ret[1] = min(ret[1], now.Y);
				} else if(ch == '3') {
					ret[2] = min(ret[2], now.Y);
				}
			}
		}
	}
	return ret;
}

vector<int> ans[3];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%s", str[i]);
	}
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			mj[1][i][j] = mj[2][i][j] = mj[3][i][j] = N * N;
		}
	}
	
	int out = N * N;
	for(int i = 1; i <= 3; ++i) {
		ans[i] = gao(i, n, m);
		int tmp = 0;
		for(int j = 0; j < ans[i].size(); ++j) {
			tmp += ans[i][j];
		}
		out = min(out, tmp);
	}
	
	//for(int i = 1; i <= 3; ++i) {
	//	cout<<"+++++"<<endl;
	//	for(int  j = 0; j < n; ++j) {
	//		for(int k = 0; k < m; ++k) {
	//			cout<<mj[i][j][k]<<' ';
	//		}
	//		cout<<endl;
	//	}
	//}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			out = min(out, mj[1][i][j] + mj[2][i][j] + mj[3][i][j] + 1);
		}
	}
	if(out == N * N) puts("-1");
	else cout<<out<<endl;

	return 0;
}


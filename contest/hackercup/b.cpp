/*======================================================
# Author: whai
# Last modified: 2016-01-11 20:51
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

const int N = 1e3 + 5;

char str[2][N];

bool vis[2][N];

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		memset(vis, 0, sizeof(vis));
		int n;
		scanf("%d", &n);
		scanf("%s", str[0] + 1);
		scanf("%s", str[1] + 1);
		str[0][0] = str[0][n + 1] = str[1][0] = str[1][n + 1] = 'X';
		str[0][n + 2] = str[1][n + 2] = 0;
		//cout<<str[0]<<endl;
		//cout<<str[1]<<endl;

		++n;

		int ans = 0;

		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j <= n; ++j) {
				if(str[i][j] == '.' && str[i][j - 1] == 'X' && str[i][j + 1] == 'X' && vis[i][j] == 0) {
					//cout<<i<<' '<<j<<endl;
					++ans;
					vis[i][j] = 1;
					if(str[i ^ 1][j] == '.') {
						vis[i ^ 1][j] = 1;
						int p = j + 1;
						while(p <= n && str[i ^ 1][p] == '.') {
							vis[i ^ 1][p] = 1;
							++p;
						}
						p = j - 1;
						while(p >= 0 && str[i ^ 1][p] == '.') {
							vis[i ^ 1][p] = 1;
							--p;
						}
					}
				}
			}
		}
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j <= n; ++j) {
				if(str[i][j] == '.' && vis[i][j] == 0) {
					//cout<<i<<' '<<j<<' '<<str[i][j]<<endl;
					++ans;
					if(str[i ^ 1][j] == '.') vis[i ^ 1][j] = 1;
					int p = j;
					while(p <= n && str[i][p] == '.') {
						vis[i][p] = 1;
						++p;
					}
				}
			}
		}
		cout<<"Case #"<<++cas<<": ";
		cout<<ans<<endl;
	}
	return 0;
}


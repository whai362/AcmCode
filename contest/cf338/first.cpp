/*======================================================
# Author: whai
# Last modified: 2016-01-08 22:01
# Filename: first.cpp
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

const int N = 105;

bool vis[N];

int main() {
	
	int n, m;
	while(cin>>n>>m) {
		int cnt = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; ++i) {
			int c, x;
			cin>>c;
			for(int i = 0; i < c; ++i) {
				cin>>x;
				if(vis[x] == 0) {
					++cnt;
					vis[x] = 1;
				}
			}
		}
		if(cnt == m) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}

	return 0;
}


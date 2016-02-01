/*======================================================
# Author: whai
# Last modified: 2015-12-04 14:22
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
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;

int a[N];

int get_sg(int x, int k) {
	bool vis[3] = {0};
	if(x == 0) return 0;
	if(x == 1) return 1;
	if(x >= 5 && x % 2 == 1) return 0;
	vis[get_sg(x - 1, k)] = 1;
	if(x % 2 == 0) {
		if(k % 2 == 0) vis[0] = 1;
		else vis[get_sg(x / 2, k)] = 1;
	}
	int ret = 0;
	while(vis[ret]) ++ ret;
	return ret;
}

void gao(int n, int k) {
	int ans = 0;

	for(int i = 0; i < n; ++i) {
		ans ^= get_sg(a[i], k);
	}
	
	if(ans == 0) {
		puts("Nicky");
	} else {
		puts("Kevin");
	}
}

/*int sg[105];
bool vis[105];

void bf(int n, int k) {
	sg[0] = 0;
	for(int i = 1; i <= 100; ++i) {
		memset(vis, 0, sizeof(vis));
		vis[sg[i - 1]] = 1;
		if(i % 2 == 0) {
			if(k % 2 == 0) vis[0] = 1;
			else vis[sg[i / 2]] = 1;
		}
		int tmp = 0;
		while(vis[tmp]) ++tmp;
		sg[i] = tmp;
	}
	for(int i = 0; i <= 100; ++i) {
		cout<<sg[i]<<' ';
	}
	cout<<endl;
	for(int i = 0; i <= 100; ++i) {
		cout<<get_sg(i, k)<<' ';
	}
	cout<<endl;
}*/

int main() {
	int n, k;

	while(scanf("%d%d", &n, &k) != EOF) {
		//bf(n, k);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		gao(n, k);
	}

	return 0;
}


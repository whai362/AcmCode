/*======================================================
# Author: whai
# Last modified: 2015-11-01 12:04
# Filename: 1006.cpp
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


const int N = 1e5 + 5;

int a[N];

bool pre[2][N];
bool bac[2][N];

bool gao(int n) {
	memset(pre, 0, sizeof(pre));
	memset(bac, 0, sizeof(bac));
	pre[0][0] = pre[1][0] = pre[0][1] = pre[1][1] = 1;
	for(int i = 2; i <= n; ++i) {
		if(a[i] == a[i - 1]) {
			pre[0][i] = pre[0][i - 1];
			pre[1][i] = pre[1][i - 1];
		} else if(a[i] > a[i - 1]) {
			pre[0][i] = pre[0][i - 1];
			pre[1][i] = 0;
		} else {
			pre[1][i] = pre[1][i - 1];
			pre[0][i] = 0;
		}
	}
	bac[0][n + 1] = bac[1][n + 1] = bac[0][n] = bac[1][n] = 1;
	for(int i = n - 1; i > 0; --i) {
		if(a[i] == a[i + 1]) {
			bac[0][i] = bac[0][i + 1];
			bac[1][i] = bac[1][i + 1];
		} else if(a[i] < a[i + 1]) {
			bac[0][i] = bac[0][i + 1];
			bac[1][i] = 0;
		} else {
			bac[1][i] = bac[1][i + 1];
			bac[0][i] = 0;
		}
	}
	//for(int i = 1; i <= n; ++i) {
	//	cout<<pre[0][i]<<' ';
	//}
	//cout<<endl;
	//for(int i = 1; i <= n; ++i) {
	//	cout<<pre[1][i]<<' ';
	//}
	//cout<<endl;
	//for(int i = 1; i <= n; ++i) {
	//	cout<<bac[0][i]<<' ';
	//}
	//cout<<endl;
	//for(int i = 1; i <= n; ++i) {
	//	cout<<bac[1][i]<<' ';
	//}
	//cout<<endl;

	for(int i = 1; i <= n; ++i) {
		if(pre[0][i - 1] && bac[0][i + 1]) {
			if(i == 1 || i == n) return true;
			if(a[i - 1] <= a[i + 1]) return true;
		}
		if(pre[1][i - 1] && bac[1][i + 1]) {
			if(i == 1 || i == n) return true;
			if(a[i - 1] >= a[i + 1]) return true;
		}
	}
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		if(gao(n)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}


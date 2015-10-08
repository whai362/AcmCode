/*===================================================================
# Author: whai
#
# Last modified: 2015-10-04 00:24
#
# Filename: first.cpp
===================================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 55;
int a[N], b[N];
int ans[N * N], tot;
int main() {
	int n;
	cin>>n;
	tot = 0;
	for(int i = 0; i < n * n; ++i) {
		int u, v;
		cin>>u>>v;
		if(a[u] == 0 && b[v] == 0) {
			ans[tot++] = i;
			a[u] = 1;
			b[v] = 1;
		}
	}
	for(int i = 0; i < tot; ++i) {
		cout<<ans[i] + 1<<' ';
	}
	cout<<endl;
	return 0;
}


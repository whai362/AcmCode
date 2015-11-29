/*======================================================
# Author: whai
# Last modified: 2015-11-25 00:45
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

const int N = 1e5 + 5;

int a[N];
multiset<int> pool;

bool ok(int x,  int minn, int maxx) {
	//cout<<x<<' '<<maxx<<' '<<minn<<endl;
	if(x >= maxx - 1 && x <= maxx) return true;
	if(x >= minn && x <= minn + 1) return true;
	return false;
}

void gao(int n) {
	int ans = 1;
	int p = 0, q = 1;
	pool.insert(a[0]);
	while(p < n) {
		while(q < n && (pool.empty() || ok(a[q], (*pool.begin()), (*pool.rbegin())))) {
			pool.insert(a[q]);
			++q;
		}
		ans = max(ans, (int)pool.size());
		//cout<<p<<' '<<q<<' '<<(*pool.begin())<<' '<<(*pool.rbegin())<<endl;
		pool.erase(pool.find(a[p]));
		++p;
	}
	cout<<ans<<endl;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		pool.clear();
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		gao(n);
	}
	return 0;
}


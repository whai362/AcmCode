/*======================================================
# Author: whai
# Last modified: 2015-10-28 12:17
# Filename: k.cpp
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

const LL INF = 1e18 + 5;

set<LL> used;
queue<LL> q;
LL a[25], tot;

void predo() {
	used.insert(1);
	LL fac = 1;
	tot = 0;
	for(LL i = 2; INF / fac >= i; ++i) {
		fac *= i;
		a[tot++] = fac;
		q.push(fac);
		used.insert(fac);
	}
	
	while(!q.empty()) {
		LL now = q.front(); q.pop();
		for(int i = 0; i < tot; ++i) {
			if(INF / now >= a[i]) {
				LL tmp = now * a[i];
				if(used.find(tmp) == used.end()) {
					q.push(tmp);
					used.insert(tmp);
				}
			}
		}
	}
}

int main() {
	predo();
	int T;
	scanf("%d", &T);
	while(T--) {
		LL a;
		scanf("%I64d", &a);
		if(used.find(a) == used.end()) puts("NO");
		else puts("YES");
	}
	return 0;
}


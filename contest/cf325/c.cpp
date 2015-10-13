/*======================================================
# Author: whai
# Last modified: 2015-10-12 18:13
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 4005;

struct Dt {
	int v, d;
	LL p;
}a[N];

int ans[N], tot;

void print(int n) {
	for(int i = 0; i < n; ++i) {
		cout<<a[i].p<<' ';
	}
	cout<<endl;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d%I64d", &a[i].v, &a[i].d, &a[i].p);
	}
	int p = 0;
	while(p < n) {
		if(a[p].p < 0) {
			++p;
			continue;
		}
		ans[tot++] = p + 1;
		int aff = a[p].v;
		queue<int> q;
		for(int i = p + 1; aff > 0 && i < n; ++i) {
			if(a[i].p >= 0) {
				a[i].p -= aff;
				--aff;
				if(a[i].p < 0) {
					q.push(i);
				}
			}
		}
		
		//print(n);

		while(!q.empty()) {
			int now = q.front(); q.pop();
			for(int i = now + 1; i < n; ++i) {
				if(a[i].p >= 0) {
					a[i].p -= a[now].d;
					if(a[i].p < 0) {
						q.push(i);
					}
				}
			}
		}
		//print(n);
		++p;
	}
	cout<<tot<<endl;
	for(int i = 0; i < tot; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}

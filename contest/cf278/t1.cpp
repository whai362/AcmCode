/*======================================================
# Author: whai
# Last modified: 2015-12-06 22:03
# Filename: t1.cpp
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
int main() {
	int T;
	int n, V;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &V);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		LL now = 0;
		int i;
		for(i = 0; i < n; ++i) {
			now += a[i];
			if(now > V) {
				break;
			}
		}
		cout<<i<<endl;
	}
	return 0;
}


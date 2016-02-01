/*======================================================
# Author: whai
# Last modified: 2015-12-27 13:44
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

int x[2], y[2], r[2];

int sqr(int x) {
	return x * x;
}

int dis() {
	return sqr(x[0] - x[1]) + sqr(y[0] - y[1]);
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		for(int i = 0; i < 2; ++i) {
			cin>>x[i]>>y[i]>>r[i];
		}
		if(r[0] < r[1]) {
			swap(x[0], x[1]);
			swap(y[0], y[1]);
			swap(r[0], r[1]);
		}
		int sum_r = sqr(r[0] + r[1]);
		int d = dis();
		if(d > sum_r) {
			puts("4");
		} else if(d == sum_r) {
			puts("3");
		} else {
			int delta = sqr(r[0] - r[1]);
			if(delta == 0 && d == 0) {
				puts("-1");
			} else if(delta == d) {
				puts("1");
			} else if(delta < d) {
				puts("2");
			} else {
				puts("0");
			}
		}
	}
	return 0;
}


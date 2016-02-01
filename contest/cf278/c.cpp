/*======================================================
# Author: whai
# Last modified:	2015-12-05 15:25
# Filename:		c.cpp
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

const LL INF = 1000000000000000LL;

int y[3];
int m[3];
LL p[3];

bool ok(int a, int b, int c) {
	a += y[0];
	b += y[1];
	c += y[2];
	int dec = max(0, b - m[2]);
	int time;
	if(dec != 0) time = m[0] / dec;
	else {
		return false;
	}
	if(m[0] % dec) ++time;
	int cost = time * max(0, m[1] - c);
	return cost < a;
}

int main() {
	for(int i = 0; i < 3; ++i) {
		cin>>y[i];
	}
	for(int i = 0; i < 3; ++i) {
		cin>>m[i];
	}
	for(int i = 0; i < 3; ++i) {
		cin>>p[i];
	}
	
	LL ans = INF;

	for(int i = 0; i < 1000; ++i) {
		if(ok(i, 0, 0)) {
			ans = min(ans, i * p[0]);
			break;
		}
		for(int j = 0; j < 1000; ++j) {
			if(ok(i, j, 0)) {
				ans = min(ans, i * p[0] + j * p[1]);
				break;
			}
			for(int k = 0; k < 1000; ++k) {
				if(ok(i, j, k)) {
					ans = min(ans, i * p[0] + j * p[1] + k * p[2]);
					break;
				}
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}


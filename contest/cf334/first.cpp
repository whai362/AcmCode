/*======================================================
# Author: whai
# Last modified: 2015-12-01 23:25
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

int a[10];
int w[10];
int s, us;

int m[]={500, 1000, 1500, 2000, 2500};

int main() {
	for(int i = 0; i < 5; ++i) {
		cin>>a[i];
	}
	for(int i = 0; i < 5; ++i) {
		cin>>w[i];
	}
	cin>>s>>us;
	LL ans = 0;
	for(int i = 0; i < 5; ++i) {
		ans += max(m[i] / 10 * 3, (250 - a[i]) * (m[i] / 250) - w[i] * 50);
	}
	ans += s * 100 - us * 50;
	cout<<ans<<endl;
	return 0;
}


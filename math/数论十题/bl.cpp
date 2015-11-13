/*======================================================
# Author: whai
# Last modified: 2015-11-10 21:19
# Filename: bl.cpp
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

int cnt[100];

int main() {
	int a, b, d;
	cin>>a>>b>>d;
	int ans = 0;
	for(int i = 1; i <= a; ++i) {
		for(int j = 1; j <= b; ++j) {
			if(__gcd(i, j) == d) ++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}


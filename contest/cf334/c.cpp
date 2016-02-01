/*======================================================
# Author: whai
# Last modified: 2015-12-02 00:06
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
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;

char str[N];

int gao(int n) {
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < n - 1; ++i) {
		if(str[i] == str[i + 1]) {
			++cnt1;
		} else {
			++cnt2;
		}
	}
	//cout<<cnt1<<' '<<cnt2<<endl;
	int ans = cnt2 + min(2, cnt1) + 1;
	cout<<ans<<endl;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		scanf("%s", str);
		gao(n);
	}
	return 0;
}


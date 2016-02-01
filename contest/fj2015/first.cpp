/*======================================================
# Author: whai
# Last modified: 2015-12-27 13:34
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 105;

int p[N];

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, m;
		cin>>n>>m;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &p[i]);
			p[i] = 100 - p[i];
		}
		sort(p, p + n);
		int ans = 0;
		for(int i = 0; i < n && m > 0; ++i) {
			if(m >= p[i]) {
				++ans;
				m -= p[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


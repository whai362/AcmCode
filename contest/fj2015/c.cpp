/*======================================================
# Author: whai
# Last modified: 2015-12-27 13:58
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 5005;
const LL INF = 1e18;
LL dp[N];

LL w[N], v[N];

void init() {
	for(int i = 0; i < N; ++i) {
		dp[i] = INF;
	}
}

int main() {
	
	int T;
	cin>>T;

	while(T--) {
		init();
		int n;
		LL B;
		cin>>n>>B;
		for(int i = 0; i < n; ++i) {
			cin>>w[i]>>v[i];
		}
		dp[0] = 0;
		int V = 5001;
		for(int i = 0; i < n; ++i) {
			for(int j = V; j >= 0; --j) {
				if(j >= v[i]) {
					dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
				}
			}
		}
		for(int i = N - 2; i >= 0; --i) {
			dp[i] = min(dp[i + 1], dp[i]);
		}
		int ans = 0;
		for(int i = 0; i < N; ++i) {
			if(dp[i] > B) {
				ans = i - 1;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

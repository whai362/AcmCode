/*======================================================
# Author: whai
# Last modified: 2015-10-26 20:18
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;

LL x[N], h[N];

int dp[N][3];
int la[N][3];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%I64d%I64d", &x[i], &h[i]);
	}

	dp[0][0] = 1;
	la[0][0] = x[0];
	//dp[0][1] = 1;
	//la[0][1] = x[0] + h[0];
	//dp[0][2] = 0;
	//la[0][2] = x[0];

	for(int i = 1; i < n; ++i) {
		LL left = x[i] - h[i];

		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		la[i][0] = x[i];

		if(left > la[i - 1][0]) {
			if(dp[i - 1][0] + 1 > dp[i][0]) {
				dp[i][0] = dp[i - 1][0] + 1;
			}
		}
		if(left > la[i - 1][1]) {
			if(dp[i - 1][1] + 1 > dp[i][0]) {
				dp[i][0] = dp[i - 1][1] + 1;
			}
		}

		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
		la[i][1] = x[i];

		LL right = x[i] + h[i];
		if(i == n - 1) {
			++dp[i][1];
		} else {
			if(right < x[i + 1]) {
				++dp[i][1];
			}
			la[i][1] = right;
		}
	}

	cout<<max(dp[n - 1][0], dp[n - 1][1])<<endl;

	return 0;
}

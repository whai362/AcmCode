/*======================================================
# Author: whai
# Last modified: 2016-01-24 03:13
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

#define LL __int64
#define PB push_back
#define X first
#define Y second

const int N = 3005;

double P[N][N], dp[N];

void gao(int n, int k, double p) {
	P[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= i; ++j) {
			P[i][j] = 0;
			if(j - 1 >= 0) P[i][j] = P[i - 1][j - 1] * p;
			if(j <= i - 1) P[i][j] += P[i - 1][j] * (1 - p);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i - 1; j >= 0; --j) {
			P[i][j] += P[i][j + 1];
		}
	}
	//for(int i = 0; i <= n; ++i) {
	//	for(int j = 0; j <= i; ++j) {
	//		cout<<P[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}

	memset(dp, 0, sizeof(dp));
	for(int i = n; i >= k; --i) {
		for(int j = k; j <= i; ++j) {
			dp[i - j] = max(dp[i - j], dp[i] + P[j][k]);
		}
	}
	printf("%.9lf\n", dp[0]);
}

int cas = 0;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, k;
		double p;
		scanf("%d%d%lf", &n, &k, &p);
		//cout<<n<<' '<<k<<' '<<p<<endl;
		printf("Case #%d: ", ++cas);
		gao(n, k, p);
	}
	return 0;
}


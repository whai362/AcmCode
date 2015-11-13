/*======================================================
# Author: whai
# Last modified: 2015-11-01 12:47
# Filename: 1008.cpp
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
#define P pair<int, LL>
#define X first
#define Y second

const int N = 3 * 1e3;
const LL INF = 10000000000000000LL;
LL f[N];

P a[N];

LL dp[N];

int main() {
	int T;
	int n;
	
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n - 1; ++i) {
			scanf("%I64d", &f[i]);
			if(i) a[i] = P(i, f[i]);
		}
		for(int i = 0; i < N; ++i) {
			dp[i] = -INF;
		}
		int V = n - 2;
		dp[0] = 0;
		for(int i = 1; i < n - 1; ++i) {
			for(int j = a[i].X; j <= V; ++j) {
				dp[j] = max(dp[j], dp[j - a[i].X] + a[i].Y - f[0]);
			}
		}
		//cout<<n<<' '<<f[0]<<endl;
		cout<<dp[V] + n * f[0]<<endl;
	}

	return 0;
}


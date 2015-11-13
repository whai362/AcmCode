/*======================================================
# Author: whai
# Last modified: 2015-11-09 00:46
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int MOD = 1e9 + 7;

const int N = 1e5 + 5;

LL a[N];
LL ten[15];
int b[N];

int main() {
	int n, k;
	ten[1] = 1;
	for(int i = 2; i < 15; ++i) {
		ten[i] = ten[i - 1] * 10;
	}
	while(scanf("%d%d", &n, &k) != EOF) {
		int bl = n / k;
		for(int i = 0; i < bl; ++i) {
			scanf("%I64d", &a[i]);
		}
		for(int i = 0; i < bl; ++i) {
			scanf("%d", &b[i]);
		}
		LL ans = 1;
		for(int i = 0; i < bl; ++i) {
			LL L1 = 0;
			LL R1 = max(0LL, b[i] * ten[k] - 1);
			LL L2 = (b[i] + 1) * ten[k] - 1;
			LL R2 = ten[k + 1] - 1;
			//cout<<L1<<' '<<R1<<' '<<L2<<' '<<R2<<endl;
			LL tmp = R1 / a[i] - L1 / a[i] + R2 / a[i] - L2 / a[i];
			//cout<<"!"<<tmp<<endl;
			if(b[i] != 0) ++tmp;
			ans = ans * tmp % MOD;
		}
		cout<<ans<<endl;
	}

	return 0;
}


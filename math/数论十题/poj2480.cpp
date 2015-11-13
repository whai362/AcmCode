/*======================================================
# Author: whai
# Last modified: 2015-11-11 19:53
# Filename: poj2480.cpp
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

LL get_phi(LL x) {
	LL ret = 1;
	for (LL i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			ret = ret * (i - 1);
			x /= i;
			while(x % i == 0) x /= i, ret *= i;
		}
	}
	if(x > 1) ret = ret * (x - 1);
	return ret;
}

void gao(LL n) {
	LL ans = 0;
	for(LL i = 1; i * i <= n; ++i) {
		if(n % i == 0) {
			LL tmp = n / i;
			ans += i * get_phi(tmp);
			//cout<<i<<' '<<get_phi(tmp)<<endl;
			if(tmp != i) {
				ans += tmp * get_phi(i);
				//cout<<tmp<<' '<<get_phi(i)<<endl;
			}
		}
	}
	cout<<ans<<endl;
}

int main() {
	LL n;
	while(scanf("%I64d", &n) != EOF) {
		gao(n);
	}
	return 0;
}


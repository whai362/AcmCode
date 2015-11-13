/*======================================================
# Author: whai
# Last modified: 2015-11-07 15:40
# Filename: 4173.cpp
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const LL MOD = 998244353LL;

LL get_phi(LL x) {
	LL ret = 1;
	for(LL i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			ret = ret * (i - 1);
			x /= i;
			while(x % i == 0) x /= i, ret *= i;
		}
	}
	if(x > 1) ret = ret * (x - 1);
	return ret;
}

int main() {
	LL n, m;
	cin>>n>>m;
	LL ans = ((n % MOD) * (m % MOD)) % MOD * (get_phi(n) % MOD) % MOD * (get_phi(m) % MOD) % MOD;
	cout<<ans<<endl;
	return 0;
}


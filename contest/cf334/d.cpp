/*======================================================
# Author: whai
# Last modified: 2015-12-02 00:55
# Filename: d.cpp
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

const int MOD = 1000000007;

LL a_b_MOD_c(LL a,LL b,LL mod){
	LL ret = 1;
	a %= mod;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

const int N = 1e6 + 5;

int main() {
	LL p, k;
	while(cin>>p>>k) {
		LL ans;
		if(k == 0LL) {
			//cout<<'!'<<endl;
			ans = a_b_MOD_c(p, p - 1, MOD);
		} if(k == 1LL) {
			ans = a_b_MOD_c(p, p, MOD);
		} else {
			LL tmp = k;
			int cnt = 1;
			while(tmp != 1) {
				tmp = tmp * k % p;
				++cnt;
			}
			//cout<<cnt<<endl;
			cnt = (p - 1) / cnt;
			ans = a_b_MOD_c(p, cnt, MOD);
		}
		cout<<ans<<endl;
	}
	return 0;
}


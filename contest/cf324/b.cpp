/*======================================================
# Author: whai
# Last modified: 2015-10-07 00:46
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

int main() {
	int n;
	cin>>n;
	cout<<((a_b_MOD_c(27, n, MOD) - a_b_MOD_c(7, n, MOD)) % MOD + MOD) % MOD<<endl;
	return 0;
}


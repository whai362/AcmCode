/*======================================================
# Author: whai
# Last modified:	2015-10-21 09:19
# Filename:		d.cpp
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

LL a_b_MOD_c(LL a, LL b, LL mod) {
	LL ret = 1;
	a %= mod;
	while(b) {
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

LL MOD;

struct Matrix {
	LL a[5][5];
	int n, m;
	Matrix(int _n = 0, int _m = 0, LL val = 0) {
		n = _n;
		m = _m;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				a[i][j] = (i == j ? val : 0);
			}
		}
	}
	Matrix operator * (Matrix tmp) {
		Matrix ret(n, tmp.m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < tmp.m; ++j)
				for(int k = 0; k < m; ++k)
					ret.a[i][j] = (ret.a[i][j] + a[i][k] * tmp.a[k][j]) % MOD;
		return ret;
	}

	Matrix operator ^ (LL b) {
		Matrix ret(n, m, 1), base = (*this);
		while(b) {
			if(b & 1) ret = ret * base;
			base = base * base;
			b >>= 1;
		}
		return ret;
	}
};

bool ok(LL k, LL l) {
	if(l >= 62) return true;
	return k < (1LL << l);
}

LL get_fib(LL n, LL m) {
	MOD = m;
	if(n == 2) return 3;
	Matrix a0(1, 2);
	a0.a[0][0] = 2;
	a0.a[0][1] = 3;
	Matrix m0(2, 2);
	m0.a[0][0] = 0;
	m0.a[0][1] = m0.a[1][0] = m0.a[1][1] = 1;
	m0 = m0 ^ (n - 2);
	a0 = a0 * m0;
	return a0.a[0][1];
}

int main() {
	LL n, k, l, m;
	cin>>n>>k>>l>>m;
	if(!ok(k, l)) {
		puts("0");
		return 0;
	}
	
	LL fib = get_fib(n, m);
	LL ans = 1;
	for(int i = 0; i < l; ++i) {
		if(i >= 62 || (k & (1LL << i)) == 0) {
			ans = (ans * fib) % m;
		} else {
			ans = (ans * (a_b_MOD_c(2, n, m) - fib) % m) % m;
		}
	}
	ans = (ans + m) % m;
	cout<<ans<<endl;
	return 0;
}

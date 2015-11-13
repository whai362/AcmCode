/*======================================================
# Author: whai
# Last modified: 2015-11-07 16:26
# Filename: bzoj3240.cpp
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

const int MOD = 1e9 + 7;

const int N = 1e6 + 5;

char str1[N], str2[N];

struct Matrix {
	LL a[3][3];
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
	void print() {
		for(int i = 0; i < n; ++i, puts(""))
			for(int j = 0; j < m; ++j)
				cout<<a[i][j]<<' ';
		puts("");
	}
	Matrix operator *(Matrix tmp) {
		Matrix ret(n, tmp.m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < tmp.m; ++j)
				for(int k = 0; k < m; ++k)
					ret.a[i][j] = (ret.a[i][j] + a[i][k] * tmp.a[k][j]) % MOD;
		return ret;
	}
	Matrix operator ^(LL b) {
		Matrix ret(n, m, 1), base = (*this);
		while(b) {
			if(b & 1) ret = ret * base;
			b >>= 1;
			base = base * base;
		}
		return ret;
	}
};

int main() {
	LL n, m, a, b, c, d;
	scanf("%s%s", str1, str2);
	scanf("%lld%lld%lld%lld", &a, &b,&c, &d);
	n = m = 0;
	int len =  strlen(str1);
	LL phi = MOD - 1;
	if(a == 1) phi = MOD;
	for(int i = 0; i < len; ++i) {
		n = (n * 10 + str1[i] - '0') % phi;
	}
	--n;
	if(n < 0) n += phi;

	phi = MOD - 1;
	if(c == 1) phi = MOD;
	len = strlen(str2);
	for(int i = 0; i < len; ++i) {
		m = (m * 10 + str2[i] - '0') % phi;
	}
	--m;
	if(m < 0) m += phi;
	Matrix a0(1, 2);
	a0.a[0][0] = a0.a[0][1] = 1;
	Matrix han(2, 2), lie(2, 2);
	han.a[0][0] = a; han.a[1][0] = b; han.a[0][1] = 0; han.a[1][1] = 1;
	lie.a[0][0] = c; lie.a[1][0] = d; lie.a[0][1] = 0; lie.a[1][1] = 1;
	
	Matrix row = (han ^ m) * lie;

	a0 = a0 * (row ^ n);
	a0 = a0 * (han ^ m);

	cout<<a0.a[0][0]<<endl;

	return 0;
}


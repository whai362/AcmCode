/*======================================================
# Author: whai
# Last modified: 2015-11-19 14:15
# Filename: bzoj2693.cpp
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

const int N = 1e7 + 5;
const int MOD = 1e8 + 9;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

LL sum[N];

int pri[N], pri_cnt;
int phi[N];

LL inv(LL a, LL m) {
	LL p = 1, q = 0, b = m, c, d;
	while (b > 0) {
		c = a / b;
		d = a; a = b; b = d % b;
		d = p; p = q; q = d - c * q;
	}
	return p < 0 ? p + m : p;
}


void get_phi() {
	phi[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (!phi[i]) { pri[pri_cnt++] = i; phi[i] = i - 1; }
		for(int j = 0; i * pri[j] < N && j < pri_cnt; ++j) {
			if (i % pri[j] == 0) {
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			} else {
				phi[i * pri[j]] = phi[i] * (pri[j] - 1);
			}
		}
	}
}

void predo() {
	for(int i = 1; i < N; ++i) {
		for(int j = 1; j * i < N; ++j) {
			sum[j * i] = (sum[j * i] + i * phi[i]) % MOD;
		}
	}
	LL div2 = inv(2, MOD);
	for(int i = 1; i < N; ++i) {
		sum[i] = n * sum[i] % MOD * div2 % MOD;
	}
}

int main() {
	int T;
	get_phi();
	predo();
	while(T--) {
		int n, m;
	}
	return 0;
}

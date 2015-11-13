/*======================================================
# Author: whai
# Last modified: 2015-11-12 14:37
# Filename: spoj_GCDEX.cpp
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

#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e6 + 5;
int pri[N], pri_cnt;
int phi[N];

void get_phi() {
	phi[1] = 1;
	for(int i = 2; i < N; ++i) {
		if(!phi[i]) { pri[pri_cnt++] = i; phi[i] = i - 1; }
		for(int j = 0; i * pri[j] < N && j < pri_cnt; ++j) {
			if(i % pri[j] == 0) {
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			} else {
				phi[i * pri[j]] = phi[i] * (pri[j] - 1);
			}
		}
	}
}

LL ans[N];

void predo() {
	for(int i = 1; i < N; ++i) {
		for(int j = 2 * i; j < N; j += i) {
			ans[j] += phi[j / i] * i;
		}
	}
	for(int i = 2; i < N; ++i) {
		ans[i] += ans[i - 1];
	}
}

int main() {
	get_phi();
	predo();
	int n;
	while(scanf("%d", &n) && n) {
		printf("%lld\n", ans[n]);
	}
	return 0;
}


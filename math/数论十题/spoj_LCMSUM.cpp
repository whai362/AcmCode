/*======================================================
# Author: whai
# Last modified: 2015-11-11 20:55
# Filename: spoj_LCMSUM.cpp
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

//LL get_sum(int x) {
//	if(x == 1) return 2;
//	return (LL)x * phi[x];
//}
//
//void gao(int n) {
//	LL ans = 0;
//	for(int i = 1; i * i <= n; ++i) {
//		if(n % i == 0) {
//			int tmp = n / i;
//			ans += get_sum(tmp);
//			if(i != tmp) {
//				ans += get_sum(i);
//			}
//		}
//	}
//	printf("%lld\n", n * ans / 2);
//}
LL ans[N];
void predo() {
	phi[1] = 2;
	for(int i = 1; i < N; ++i) {
		LL tmp = (LL)phi[i] * i;
		for(int j = i; j < N; j += i) {
			ans[j] += tmp;
		}
	}
	for(int i = 1; i < N; ++i) {
		ans[i] = i * ans[i] / 2;
	}
}

int main() {
	int T;
	get_phi();
	predo();
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}


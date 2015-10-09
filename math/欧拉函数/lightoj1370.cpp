/*======================================================
# Author: whai
# Last modified: 2015-10-08 14:49
# Filename: lightoj1370.cpp
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

const int N = 1500005;
int pri[N], pcnt;
int phi[N];
void getphi() {
	phi[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (!phi[i]) { pri[pcnt++] = i; phi[i] = i - 1; }
		for (int j = 0; i * pri[j] < N && j < pcnt; ++j) {
			if (i % pri[j] == 0) {
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			else phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
}

int tab[N];

void predo() {
	memset(tab, 0x3f, sizeof(tab));
	phi[1] = 0;
	for(int i = N - 1; i > 0; --i) {
		tab[phi[i]] = i;
	}
	for(int i = N - 2; i > 0; --i) {
		tab[i] = min(tab[i], tab[i + 1]);
	}
}

int main() {
	getphi();
	predo();
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		int n;
		scanf("%d", &n);
		LL ans = 0;
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			ans += tab[x];
		}
		printf("Case %d: %lld Xukha\n", ++cas, ans);
	}
	return 0;
}

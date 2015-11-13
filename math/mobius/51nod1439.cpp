/*======================================================
# Author: whai
# Last modified: 2015-11-03 11:28
# Filename: 51nod1439.cpp
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

const int N = 5 * 1e5 + 5;

int a[N];

int cnt[N];

bool in[N];

vector<int> fac[N];

LL ans = 0;

int mu[N];
//O(nlog(n))
void getMu() {
	for (int i = 1; i < N; ++i) {
		int target = i == 1 ? 1 : 0;
		int delta = target - mu[i];
		mu[i] = delta;
		for (int j = 2 * i; j < N; j += i)
			mu[j] += delta;
	}
}

//1µÄÇé¿ö
void gao(int id) {
	int x = a[id];
	if(in[id]) {
		if(fac[x].size() == 0) {
			for(int i = 1; i * i <= x; ++i) {
				if(x % i == 0) {
					int tmp = x / i;
					fac[x].push_back(i);
					--cnt[i];
					if(tmp != i) {
						--cnt[tmp];
						fac[x].push_back(tmp);
					}
				}
			}
		} else {
			for(int i = 0; i < fac[x].size(); ++i) {
				int tmp = fac[x][i];
				--cnt[tmp];
			}
		}
	}

	int add = 0;
	if(fac[x].size() == 0) {
		for(int i = 1; i * i <= x; ++i) {
			if(x % i == 0) {
				add += mu[i] * cnt[i];
				int tmp = x / i;
				fac[x].push_back(i);
				if(tmp != i) {
					add += mu[tmp] * cnt[tmp];
					fac[x].push_back(tmp);
				}
			}
		}
	} else {
		for(int i = 0; i < fac[x].size(); ++i) {
			int tmp = fac[x][i];
			add += mu[tmp] * cnt[tmp];
		}
	}

	//cout<<x<<' '<<a[x]<<' '<<add<<endl;
	if(in[id]) {
		ans -= add;
		in[id] = 0;
	} else {
		ans += add;
		if(fac[x].size() == 0) {
			for(int i = 1; i * i <= x; ++i) {
				if(x % i == 0) {
					int tmp = x / i;
					fac[x].push_back(i);
					++cnt[i];
					if(tmp != i) {
						++cnt[tmp];
						fac[x].push_back(tmp);
					}
				}
			}
		} else {
			for(int i = 0; i < fac[x].size(); ++i) {
				int tmp = fac[x][i];
				++cnt[tmp];
			}
		}
		in[id] = 1;
	}
	printf("%I64d\n", ans);
}

int main() {
	int n, q;
	getMu();
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		gao(x);
	}
	return 0;
}


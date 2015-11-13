/*======================================================
# Author: whai
# Last modified: 2015-11-10 14:20
# Filename: uva1521.cpp
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

const int N = 1e5 + 5;

bool is_pri[N];
void get_pri(int n) {
	memset(is_pri, 1, sizeof(is_pri));
	is_pri[0] = is_pri[1] = 0;
	for(int i = 2; i <= n; ++i) {
		if(is_pri[i]) {
			if(n / i < i) break;
			for(int j = i * i; j <= n; j += i) is_pri[j] = false;
		}
	}
}

int pri[N], tot;
bool used[N];
void gao(int n) {
	int ans = 0;
	int j = 0;
	memset(used, 0, sizeof(used));
	for(int i = tot - 1; i >= 0; --i) {
		if(used[i]) {
			break;
		}
		LL tmp = pri[i];
		for(; j < i; ++j) {
			if(tmp * pri[j] <= n) {
				tmp *= pri[j];
				used[j] = 1;
			} else {
				break;
			}
		}
		used[i] = 1;
		++ans;
	}
	cout<<ans<<endl;
}

int main() {
	int n;
	get_pri(N - 1);
	while(scanf("%d", &n) != EOF) {
		tot = 0;
		for(int i = 2; i <= n; ++i) {
			if(is_pri[i]) pri[tot++] = i;
		}
		gao(n);
	}
	return 0;
}

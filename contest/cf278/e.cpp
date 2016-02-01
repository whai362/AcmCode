/*======================================================
# Author: whai
# Last modified: 2015-12-05 19:46
# Filename: e.cpp
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

const int N = 1e5 + 5;

bool is_pri[N];
void get_pri(int n) {
	memset(is_pri, 1, sizeof(bool) * (n + 1));
	is_pri[0] = is_pri[1] = 0;
	for (int i = 2; i <= n; ++i)
		if (is_pri[i]) {
			if (n / i < i) break;
			for (int j = i * i; j <= n; j += i) is_pri[j] = false;
		}
}

LL inv(LL a, LL m) {
	LL p = 1, q = 0, b = m, c, d;
	while (b > 0) {
		c = a / b;
		d = a; a = b; b = d % b;
		d = p; p = q; q = d - c * q;
	}
	return p < 0 ? p + m : p;
}

int ans[N];

int ny[N];

int main() {
	get_pri(N - 1);
	int n;
	while(cin>>n) {
		if(n == 1) {
			puts("YES");
			puts("1");
			continue;
		}
		if(n == 2) {
			puts("YES");
			puts("1");
			puts("2");
			continue;
		}
		if(n == 4) {
			puts("YES");
			puts("1\n3\n2\n4\n");
			continue;
		}
		if(!is_pri[n]) {
			puts("NO");
		} else {
			puts("YES");
			ans[0] = 1;
			ans[n - 1] = n;
			for(int i = 1; i < n - 1; ++i) {
				ny[i] = inv(i, n);
			}
			for(int i = 1; i < n - 1; ++i) {
				ans[i] = (LL)(i + 1) * ny[i] % n;
			}

			for(int i = 0; i < n; ++i) {
				cout<<ans[i]<<endl;
			}
		}
	}
	return 0;
}


/*======================================================
# Author: whai
# Last modified: 2015-10-25 17:32
# Filename: c.cpp
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

void gao(int n) {
	int ans = 0;
	for(int i = 0; i < n - 1; ++i) {
		if(a[i] == 0 && a[i + 1] == 1) {
			int st = i;
			int en = i;
			while(en < n - 1 && a[en] == 0 && a[en + 1] == 1) {
				en += 2;
			}
			--en;

			int cnt = (en - st + 1 - 2) / 2;
			int flag = 1;
			if(en < n - 1 && a[en + 1] == 0) {
				flag = 0;
				++cnt;
			}
			ans = max(ans, cnt);
			int len = en - st + 1;
			for(int j = st; j < st + len / 2; ++j) {
				a[j] = 0;
			}
			for(int j = st + len / 2; j < st + len; ++j) {
				a[j] = flag;
			}
			i = en;
		} else if(a[i] == 1 && a[i + 1] == 0) {
			int st = i;
			int en = i;
			while(en < n - 1 && a[en] == 1 && a[en + 1] == 0) {
				en += 2;
			}
			--en;
			int cnt = (en - st + 1 - 2) / 2;
			int flag = 0;
			if(en < n - 1 && a[en + 1] == 1) {
				flag = 1;
				++cnt;
			}
			ans = max(ans, cnt);
			int len = en - st + 1;
			for(int j = st; j < st + len / 2; ++j) {
				a[j] = 1;
			}
			for(int j = st + len / 2; j < st + len; ++j) {
				a[j] = flag;
			}
			i = en;
		}
	}
	printf("%d\n", ans);
	for(int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	puts("");
}

int main() {
	int n;
	
	int ans = 0;

	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	gao(n);

	return 0;
}

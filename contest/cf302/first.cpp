/*======================================================
# Author: whai
# Last modified: 2015-11-07 19:59
# Filename: first.cpp
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

const int N = 1005;

char str[N];

int used[N];
int index[N];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	int len = strlen(str);
	int cnt = 0;
	for(int i = 0; i < len; ++i) {
		if(cnt < n && used[str[i]] == 0) {
			++cnt;
			used[str[i]] = 1;
			index[i] = 1;
		}
	}
	if(cnt == n) {
		puts("YES");
		for(int i = 0; i < len; ++i) {
			if(index[i]) {
				int p = i;
				putchar(str[p]);
				++p;
				while(p < len && index[p] == 0) {
					putchar(str[p]);
					++p;
				}
				puts("");
				i = p - 1;
			}
		}
	} else {
		puts("NO");
	}
	return 0;
}


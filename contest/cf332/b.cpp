/*======================================================
# Author: whai
# Last modified: 2015-11-23 20:22
# Filename: b.cpp
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

int b[N], a[N];
int tab[N];
int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(tab, 0, sizeof(tab));
		int flag = 1;
		for(int i = 1; i <= n; ++i) {
			int f;
			scanf("%d", &f);
			if(tab[f] == 0) {
				tab[f] = i;
			} else {
				tab[f] = -1;
			}
		}
		for(int i = 1; i <= m; ++i) {
			scanf("%d", &b[i]);
			if(tab[b[i]] > 0)
				a[i] = tab[b[i]];
			else if(tab[b[i]] == -1 && flag !=  -1)
				flag = 0;
			else
				flag = -1;
		}
		if(flag == 1) {
			puts("Possible");
			for(int i = 1; i <= m; ++i) {
				printf("%d%c", a[i], i == m ? '\n':' ');
			}
		} else if(flag == 0){
			puts("Ambiguity");
		} else {
			puts("Impossible");
		}
	}
	return 0;
}


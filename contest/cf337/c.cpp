/*======================================================
# Author: whai
# Last modified: 2015-12-27 19:58
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
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 2005;

int a[N][N];

void deal(int &n) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			a[i + n][j] = a[i][j + n] = a[i][j];
			a[i + n][j + n] = -a[i][j];
		}
	}
	n *= 2;
}

int main() {
	int n;
	while(cin>>n) {
		a[0][0] = a[0][1] = a[1][0] = 1;
		a[1][1] = -1;
		--n;
		int c = 2;
		for(int i = 0; i < n; ++i) {
			deal(c);
		}
		for(int i = 0; i < c; ++i) {
			for(int j = 0; j < c; ++j) {
				if(a[i][j] == 1) {
					putchar('+');
				} else {
					putchar('*');
				}
			}
			puts("");
		}
	}
	return 0;
}


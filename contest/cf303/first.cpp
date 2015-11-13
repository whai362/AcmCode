/*======================================================
# Author: whai
# Last modified: 2015-10-26 19:58
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

const int N = 105;
int a[N][N];

bool ok[N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
			if(a[i][j] == 1) {
				ok[i] = 1;
			} else if(a[i][j] == 2) {
				ok[j] = 1;
			} else if(a[i][j] == 3) {
				ok[i] = ok[j] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(ok[i] == 0) ++cnt;
	}
	cout<<cnt<<endl;
	if(cnt) {
		for(int i = 0; i < n; ++i) {
			if(ok[i] == 0) {
				cout<<i + 1<<' ';
			}

		}
		cout<<endl;
	}
	return 0;
}


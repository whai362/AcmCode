/*======================================================
# Author: whai
# Last modified: 2015-11-09 00:25
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

const int N = 205;
int a[N][N];

int main() {
	int n, m;
	

	while(cin>>n>>m) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < 2 * m; ++j) {
				cin>>a[i][j];
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < 2 * m; j += 2) {
				cnt += a[i][j] | a[i][j + 1];
			}
		}
		cout<<cnt<<endl;
	}

	return 0;
}


/*======================================================
# Author: whai
# Last modified: 2015-10-06 22:58
# Filename: poj2947.cpp
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

string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int get_day(string str) {
	for(int i = 0; i < 7; ++i) {
		if(str == days[i]) return i;
	}
}

const int N = 305;

LL inv(LL a, LL m) {
	LL p = 1, q = 0, b = m, c, d;
	while (b > 0) {
		c = a / b;
		d = a; a = b; b = d % b;
		d = p; p = q; q = d - c * q;
	}
	return p < 0 ? p + m : p;
}

int n, m;
int f[N][N], x[N];
int gauss() {
	int i, c;
	for(i = 0, c = 0; i < m && c < n; ++c) {
		int k = i;
		while(k < m && !f[k][c]) ++k;
		if(f[k][c]) {
			for(int j = c; j <= n; ++j)
				swap(f[i][j], f[k][j]);
			for(int j = 0; j < m; ++j)
				if(i != j && f[j][c]) {
					int tmp1 = f[i][c], tmp2 = f[j][c];
					for(int k = 0; k <= n; ++k) {
						f[j][k] = ((f[j][k] * tmp1 - f[i][k] * tmp2) % 7 + 7) % 7;
					}
				}
			++i;
		}
	}
	for(int j = i; j < m; ++j) if(f[j][n]) return -1;
	if(i < n) return n - i;
	for(int j = n - 1; j >= 0; --j) {
		int tmp = f[j][n];
		for(int k = j + 1; k < n; ++k) {
			tmp = ((tmp - f[j][k] * x[k]) % 7 + 7) % 7;
		}
		while(tmp % f[j][j] != 0) tmp += 7;
		x[j] = (tmp / f[j][j]) % 7;
	}
	for(int i=0; i<n; ++i)
		if(x[i] < 3)
			x[i] += 7;
	return 0;
}

void init() {
	memset(f, 0, sizeof(f));
}

int main() {
	while(cin>>n>>m && (n || m)) {
		init();
		for(int i = 0; i < m; ++i) {
			int k;
			string st, en;
			cin>>k>>st>>en;
			f[i][n] = (get_day(en) - get_day(st) + 1 + 7) % 7;
			for(int j = 0; j < k; ++j) {
				int type;
				scanf("%d", &type);
				++f[i][--type];
			}
			for(int j = 0; j < n; ++j)
				f[i][j] %= 7;
		}
		int flag = gauss();
		if(flag == -1) {
			cout<<"Inconsistent data."<<endl;
		} else if(flag > 0) {
			cout<<"Multiple solutions."<<endl;
		} else {
			for(int i = 0; i < n; ++i) {
				cout<<x[i]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}

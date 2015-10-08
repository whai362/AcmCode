/*======================================================
# Author: whai
#
# Last modified: 2015-10-05 14:04
#
# Filename: poj1836.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e3 + 5;
const double EPS = 1e-8;

double a[N];
double min_v[N];

int ans[2][N];

void LIS(double a[], int n, int id) {
	int len = 1;
	min_v[0] = a[0];
	ans[id][0] = len;
	for(int i = 1; i < n; ++i) {
		if(a[i] > min_v[len - 1]) {
			min_v[len++] = a[i];
		} else {
			int pos = upper_bound(min_v, min_v + len, a[i] - EPS) - min_v;
			min_v[pos] = a[i];
		}
		ans[id][i] = len;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%lf", &a[i]);
	}
	LIS(a, n, 0);
	reverse(a, a + n);
	LIS(a, n, 1);
	int minn = n;
	for(int i = 0; i < n - 1; ++i) {
		minn = min(minn, n - ans[0][i] - ans[1][n - 2 - i]);
	}
	cout<<minn<<endl;
	return 0;
}


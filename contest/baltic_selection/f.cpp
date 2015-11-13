/*======================================================
# Author: whai
# Last modified: 2015-10-28 11:36
# Filename: f.cpp
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


double gao(double x) {
	double ret = x / (x + 1);
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		double l, r;
		scanf("%lf%lf", &l, &r);
		double ans = gao(r) - gao(l - 1);
		printf("%.10f\n", ans);
	}

	return 0;
}


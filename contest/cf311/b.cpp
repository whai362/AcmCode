/*======================================================
# Author: whai
# Last modified: 2015-10-09 22:17
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

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 2 * 1e5 + 5;

double a[N];

int main() {
	int n;
	double w;
	scanf("%d%lf", &n, &w);
	for(int i = 0; i < 2 * n; ++i) {
		scanf("%lf", &a[i]);
	}
	sort(a, a + 2 * n);
	double min2 = a[0], min1 = a[n];
	double tmp = w / n / 1.5;
	double  x = min(min2 * 2, min(tmp, min1));

	printf("%.8f\n", x * 1.5 * n);
	return 0;
}


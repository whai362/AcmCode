/*======================================================
# Author: whai
# Last modified: 2015-11-10 15:20
# Filename: d.cpp
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

const double PI = acos(-1.0);

double sqr(double x) {
	return x * x;
}

bool ok(double x, double r, double v, double d) {
	double zc = 2 * PI * r;
	double round = x / zc;
	double arfa = round * 2 * PI;
	double A = r - r * cos(arfa);
	double B = r * sin(arfa);
	double maxx = sqrt(sqr(A) + sqr(B));
	return x + maxx > d;
}

void gao(double r, double v, double s, double t) {
	double L = 0, R = t - s;
	int b_cnt = 0;
	while(b_cnt < 50) {
		double mid = (L + R) / 2;
		if(ok(mid, r, v, t - s)) {
			R = mid;
		} else {
			L = mid;
		}
		++b_cnt;
	}
	printf("%.10f\n", L / v);
}

int main() {
	int n;
	double r, v;
	scanf("%d%lf%lf", &n, &r, &v);
	for(int i = 0; i < n; ++i) {
		double s, t;
		scanf("%lf%lf", &s, &t);
		gao(r, v, s, t);
	}
	return 0;
}


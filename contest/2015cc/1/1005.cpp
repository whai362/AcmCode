/*======================================================
# Author: whai
# Last modified: 2015-11-01 14:16
# Filename: 1005.cpp
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
#define PDD pair<double, double>

const int N = 10005;
const double PI = acos(-1.0);
const double eps = 1e-12; 

PDD p[N];
double d[N];
double ans_r[N];

double sqr(double x) {
	return x * x;
}

double dis(PDD a, PDD b) {
	return sqrt(sqr(a.X - b.X) + sqr(a.Y - b.Y));
}

double get_area(double r, int n) {
	double ret = 0;
	ans_r[0] = r;
	for(int i = 1; i < n; ++i) {
		ans_r[i] = d[i - 1] - ans_r[i - 1];
	}
	for(int i = 0; i < n; ++i) {
		ret += sqr(ans_r[i]);
	}
	return ret;
}

bool gao(int n) {
	for(int i = 0; i < n; ++i) {
		int nxt = (i + 1) % n;
		d[i] = dis(p[i], p[nxt]);
	}
	if(n & 1) {
		double tmp = 0;
		for(int i = 0; i < n; ++i) {
			if(i & 1) tmp -= d[i];
			else tmp += d[i];
		}
		ans_r[0] = tmp / 2;
		if(tmp < -eps) return false;
		for(int i = 1; i < n; ++i) {
			ans_r[i] = d[i - 1] - ans_r[i - 1];
			if(ans_r[i] < -eps) {
				return false;
			}
		}
		return true;
	} else {
		double tmp = 0;
		for(int i = 0; i < n; ++i) {
			if(i & 1) tmp -= d[i];
			else tmp += d[i];
		}
		if(fabs(tmp) > eps) return false;
		double L = 0, R = d[n - 1];
		tmp = 0;
		for(int i = 0; i < n; ++i) {
			if(i & 1) tmp -= d[i];
			else tmp += d[i];
			if(i & 1) {
				L = max(L, tmp);
			} else {
				R = min(R, tmp);
			}
		}
		//cout<<L<<' '<<R<<endl;
		
		if(R < L - eps) return false;
		
		///int b_cnt = 0;
		while(L + eps < R) {
			double m_l = (L + R) / 2;
			double m_r = (m_l + R) / 2;
			double ans_l = get_area(m_l, n);
			double ans_r = get_area(m_r, n);
			if(ans_l > ans_r) {
				L = m_l;
			} else {
				R = m_r;
			}
			//++b_cnt;
		}
		ans_r[0] = (L + R) / 2;
		for(int i = 1; i < n; ++i) {
			ans_r[i] = d[i - 1] - ans_r[i - 1];
			if(ans_r[i] < -eps) return false;
		}
		return true;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%lf%lf", &p[i].X, &p[i].Y);
		}
		bool flag = gao(n);
		if(flag) {
			double area = 0;
			for(int i = 0; i < n; ++i) {
				area += sqr(ans_r[i]);
			}
			area *= PI;
			printf("%.2f\n", area);
			for(int i = 0; i < n; ++i) {
				printf("%.2f\n", ans_r[i]);
			}
		} else {
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}


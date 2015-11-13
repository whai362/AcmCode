/*======================================================
# Author: whai
# Last modified: 2015-11-10 16:20
# Filename: e.cpp
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

const int N = 1e5 + 5;
const LL INF = 1.5 * 1e18;

struct Pt {
	double x, y;
	int id;
}p0[N], p1[N];

bool cmp0(Pt a, Pt b) {
	return a.x < b.x;
}

bool cmp1(Pt a, Pt b) {
	return a.y < b.y;
}

bool ok(int i0, int i1, int i2, int i3, int n, int k) {
	LL L0 = p0[i0].x;
	LL R0 = p0[n - 1 - i1].x;

	LL L1 = p1[i2].y;
	LL R1 = p1[n - 1 - i3].y;
	if(L0 > R0 || L1 > R1) return false;

	set<int> del;
	for(int i = 0; i < i0; ++i) {
		del.insert(p0[i].id);
	}
	for(int i = n - i1; i < n; ++i) {
		del.insert(p0[i].id);
	}
	for(int i = 0; i < i2; ++i) {
		del.insert(p1[i].id);
	}
	for(int i = n - i3; i < n; ++i) {
		del.insert(p1[i].id);
	}
	//cout<<i0<<' '<<i1<<' '<<i2<<' '<<i3<<' '<<del.size()<<endl;
	if(del.size() <= k) return true;
	else return false;
}

int main() {
	int n, k;

	scanf("%d%d", &n, &k);
	k = min(n - 1, k);
	
	double x[2], y[2];
	for(int i = 0; i < n; ++i) {
		scanf("%lf%lf%lf%lf", &x[0], &y[0], &x[1], &y[1]);
		p0[i].x = p1[i].x = (x[0] + x[1]) / 2;
		p0[i].y = p1[i].y = (y[0] + y[1]) / 2;
		p0[i].id = p1[i].id = i;
	}
	sort(p0, p0 + n, cmp0);
	sort(p1, p1 + n, cmp1);

	LL ans = INF;

	for(int i0 = 0; i0 <= k; ++i0) {
		for(int i1 = 0; i1 <= k; ++i1) {
			for(int i2 = 0; i2 <= k; ++i2) {
				for(int i3 = 0; i3 <= k; ++i3) {
					 if(ok(i0, i1, i2, i3, n, k)) {
						 double L0 = p0[i0].x;
						 double R0 = p0[n - 1 - i1].x;

						 double L1 = p1[i2].y;
						 double R1 = p1[n - 1 - i3].y;
						 LL A = (LL)(R0 - L0 + 0.5);
						 LL B = (LL)(R1 - L1 + 0.5);
						 if(A == 0) ++A;
						 if(B == 0) ++B;
						 //cout<<L0<<' '<<R0<<' '<<L1<<' '<<R1<<endl;
						 ans = min(ans, A * B);
					 }
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

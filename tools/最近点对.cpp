/*poj 3714
  题意：
  给出n个a类点，n个b类点，求a类点到b类点的最近距离。
  限制：
  1 <= n <= 1e5
  0 <= x,y <= 1e9
  思路：
  点分治
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double INF = 1e30;
struct Point {
	double x, y;
	int s;
	Point() {}
	Point(double _x, double _y) { x = _x; y = _y; }
	Point operator - (Point p) { return Point(x - p.x, y - p.y); }
	double dot(Point p) { return x * p.x + y * p.y; }
};
const int N = 1e5 + 5;
Point p[2 * N];
int t[2 * N];
bool cmpxy(Point a, Point b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
bool cmpy(int a, int b) {
	return p[a].y < p[b].y;
}
double dist(Point a, Point b) {
	return sqrt((a - b).dot(a - b));
}
double gao(int l, int r) {
	double ret = INF;
	if (l == r) return ret;
	if (l + 1 == r) {
		if (p[l].s != p[r].s) return dist(p[l], p[r]);
		else return ret;
	}
	int mid = (l + r) >> 1;
	double d = min(gao(l, mid), gao(mid + 1, r));
	int cnt = 0;
	for (int i = l; i < r; ++i) {
		if (fabs(p[mid].x - p[i].x) < d)
			t[cnt++] = i;
	}
	sort(t, t + cnt, cmpy);
	for (int i = 0; i < cnt; ++i)
		for (int j = i + 1; j < cnt && p[t[j]].y - p[t[i]].y < d; ++j)
			if (p[t[i]].s != p[t[j]].s) d = min(d, dist(p[t[i]], p[t[j]]));
	return d;
}
int main() {
	int T;
	scanf("%d", &T);
	int n;
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
			p[i].s = 0;
		}
		for (int i = n; i < 2 * n; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
			p[i].s = 1;
		}
		sort(p, p + 2 * n, cmpxy);
		printf("%.3f\n", gao(0, 2 * n - 1));
	}
	return 0;
}

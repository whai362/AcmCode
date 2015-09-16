/*题意：给出一系列的坐标，要求出这些坐标中组成的三角形中最大的高是多少
  解法：枚举点A，先求得距离他最远的点C，再枚举点B就可以了
*/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
struct point {
	double x, y;
} p[505];
double xmult(point p1, point p2, point p0) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double dis(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
	int i, j, n, p0;
	double ans, _max, tmp;
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		for (i = 0; i < n; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		for (i = 0; i < n; ++i) {
			_max = 0;
			for (j = 0; j < n; ++j) {
				if (j == i) continue;
				tmp = dis(p[i], p[j]);
				if (tmp > _max) _max = tmp, p0 = j;
			}
			for (j = 0; j < n; ++j) {
				if (j == i || j == p0) continue;
				double d = 1e10, s;
				d = min(d, dis(p[i], p[p0]));
				d = min(d, dis(p[i], p[j]));
				d = min(d, dis(p[p0], p[j]));
				s = fabs(xmult(p[i], p[j], p[p0]));
				ans = max(ans, s / d);
			}
		}
		cout << fixed << setprecision(5) << ans << endl;
	}
	return 0;
}

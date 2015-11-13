/*题意：
  平面上给你n个点(xi,yi)，让你求一个点，到这n点的距离和最小。
  限制：
  1 <= n <= 100
  0 <= xi,yi <= 1e4, 为整数
  思路：
  爬山算法
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct Pt {
	double x, y;
} p[105];
double sqr(double x) {
	return x * x;
}
double dis(Pt a, Pt b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
double get_sum(Pt p0, int n) {
	double ret = 0;
	for (int i = 0; i < n; ++i)
		ret += dis(p0, p[i]);
	return ret;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		double x0 = 0, y0 = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
			x0 += p[i].x;
			y0 += p[i].y;
		}
		x0 /= n;
		y0 /= n;
		double ans = get_sum((Pt) {x0, y0}, n);
		double temp = 1e5; //初始温度, 根据题目修改
		while (temp > 0.02) { //0.02为温度的下限, 若温度temp达到下限, 则停止搜索
			double x = 0, y = 0;
			//如果步长没有办法取，就随机 = double(rand() - RAND_MAX / 2) / (RAND_MAX / 2);
			for (int i = 0; i < n; ++i) { //计算步长的规则，根据题目而定，参考模拟退火模板 
				x += (p[i].x - x0) / dis((Pt) {x0, y0}, p[i]);
				y += (p[i].y - y0) / dis((Pt) {x0, y0}, p[i]);
			}
			x0 += x * temp;
			y0 += y * temp;
			double tmp = get_sum((Pt) {x0, y0}, n);
			ans = min(ans, tmp);
			temp *= 0.9;
		}
		printf("%.0f\n", ans);
	}
	return 0;
}

/*poj 2069 Super Star
  题意：
  给定n个点(xi, yi, zi), 要求覆盖这些点的最小球半径。
  限制：
  4 <= n <= 30
  0 <= xi, yi, zi <= 100
  思路：
  模拟退火
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
const double E = exp(1.0);
struct Pt{
	double x, y, z;
}p[35];
double sqr(double x){
	return x * x;
}
double dis(Pt a, Pt b){
	return sqrt(sqr(a.x - b.x) +
				sqr(a.y - b.y) +
				sqr(a.z - b.z));
}
double get_max_r(Pt p0, int n){
	double ret = 0;
	for(int i = 0; i < n; ++i)
		ret = max(ret, dis(p0, p[i]));
	return ret;
}
int main() {
	int n;
	int limit = 100;
	while(scanf("%d", &n) && n){
		double x0 = 0, y0 = 0, z0 = 0;
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
			x0 += p[i].x;
			y0 += p[i].y;
			z0 += p[i].z;
		}
		x0 /= n;
		y0 /= n;
		z0 /= n;
		//cout<<x0<<' '<<y0<<' '<<z0<<endl;
		double ans = get_max_r((Pt){x0, y0, z0}, n);
		double temp = 1e5;
		while(temp > 1e-8){
			//double x = 0, y = 0, z = 0;
			//double max_r = 0;
			//for(int i = 0; i < n; ++i){
			//	double r = dis((Pt){x0, y0, z0}, p[i]);
			//	if(r > max_r){
			//		x = (p[i].x - x0) / r;
			//		y = (p[i].y - y0) / r;
			//		z = (p[i].z - z0) / r;
			//		max_r = r;
			//	}
			//}
			double x = double(rand() - RAND_MAX / 2) / (RAND_MAX / 2);
			double y = double(rand() - RAND_MAX / 2) / (RAND_MAX / 2);
			double z = double(rand() - RAND_MAX / 2) / (RAND_MAX / 2);

			double tmp = get_max_r((Pt){
					x0 + x * temp,
					y0 + y * temp,
					z0 + z * temp}, n);
			if(tmp < ans){
				ans = tmp;
				x0 += x * temp;
				y0 += y * temp;
				z0 += z * temp;
			}
			temp *= 0.999;
		}
		printf("%.5f\n", ans);
	}
	return 0;
}

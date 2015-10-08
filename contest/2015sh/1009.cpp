#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct P {
	double x, y;
}p[4];

double sqr(double x) {
	return x * x;
}

double dis(P a, P b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double cal(P A, P B, P C) {
	double a = dis(B, C);
	double b = dis(A, C);
	double c = dis(A, B);
	return (b + c - a) / (2.0 * sqrt(b * c));
}

int main() {
	int T;
	cin>>T;
	int cas = 0;
	while(T--) {
		for(int i = 0; i < 3; ++i) {
			cin>>p[i].x>>p[i].y;
		}
		p[3].x = (p[1].x + p[2].x) / 2.0;
		p[3].y = (p[1].y + p[2].y) / 2.0;
		
		double l = dis(p[0], p[1]);
		double a = dis(p[1], p[3]);
		double x = sqrt(l * l - a * a);
		double y = a * a / x;
		double r = sqrt(y * y + a * a);
		double cos_t = (2 * r * r - 4 * a * a) / (2 * r * r);
		double t = acos(cos_t);
		double ans = t * r + x;
		printf("Case #%d: %.5f\n", ++cas, ans);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);
void gao(double v, double d) {
	double tmp = d * 9.8 / (v * v);
	//cout<<tmp<<endl;
	double ans = asin(tmp) / PI * 180.0 / 2.0;
	printf("%.8f\n", ans);
}
int main() {
	int T;
	cin>>T;
	int cas = 0;
	while(T--) {
		double v, d;
		cin>>v>>d;
		printf("Case #%d: ", ++cas);
		gao(v, d);
	}
	return 0;
}

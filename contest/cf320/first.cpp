#include <iostream>
#include <cstdio>
using namespace std;

const double INF = 1e30;

int main() {
	int a, b;
	cin>>a>>b;
	int A = a - b;
	double ans = INF;
	if(A >= 0) {
		int tmp = A / b + 10;
		for(; tmp % 2 == 1 || double(A) / tmp < b; --tmp);
		double jie = double(A) / tmp;
		ans = min(jie, ans);
	}
	A = a + b;
	if(A >= 0) {
		int tmp = A / b + 10;
		for(; tmp % 2 == 1 || double(A) / tmp < b; --tmp);
		double jie = double(A) / tmp;
		ans = min(jie, ans);
	}
	if(ans == INF) puts("-1");
	else 
		printf("%.10f\n", ans);
	return 0;
}

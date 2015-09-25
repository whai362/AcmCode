#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
const double E = exp(1.0);
const double INF = 1e8;
const double eps = 1e-11;
double maxx = -INF, minn = INF;

const int N = 200000 + 5;

double x[N];

double fun(double v, int n) {
	double tmp = x[0] - v, ret = x[0] - v;
	//cout<<x[0] - v<<' ';
	bool flag = 0;
	if(x[0] < v) flag = 1;
	for(int i = 1; i < n; ++i) {
		if(x[i] < v) flag = 1;
		tmp += x[i] - v;
		//cout<<x[i] - v<<' ';
		if(tmp < x[i] - v) {
			tmp = x[i] - v;
		}
		ret = max(tmp, ret);
	}
	//cout<<endl;
	//cout<<ret<<endl;
	if(flag) {
		maxx = v - x[0];
		tmp = v - x[0];
		for(int i = 1; i < n; ++i) {
			tmp += v - x[i];
			if(tmp < v - x[i]) {
				tmp = v - x[i];
			}
			maxx = max(tmp, maxx);
		}
	}
	return max(ret, maxx);
}

int main() {
	int n;
	cin>>n;
	double x0 = 0;
	for(int i = 0; i < n; ++i) {
		cin>>x[i];
		maxx = max(x[i], maxx);
		maxx = max(-x[i], maxx);
		minn = min(x[i], minn);
	}

	double L = -INF, R = INF;
	double m_l, m_r;
	while (L + eps < R) {
		double m_l = (2 * L + R) / 3;
		double m_r = (L + 2 * R) / 3;
		double ans_l = fun(m_l, n);
		double ans_r = fun(m_r, n);
		//cout<<ans_l<<' '<<ans_r<<endl;
		if (ans_l > ans_r) {
			L = m_l;
		} else {
			R = m_r;
		}
	}
	double ans = (L + R) / 2;
	printf("%.7f\n", fun(ans, n));
}

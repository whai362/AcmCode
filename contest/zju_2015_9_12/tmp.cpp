#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstdio>

double const pi = acos(-1.0);

double z1, z2;
double delta_sin;

double tmp_f(double x)
{
//	return std::sin(z) * std::sqrt(1 + std::sin(z) * std::sin(z)) + z;
	return sin(x) * sqrt(1 + sin(x) * sin(x)) + log(sin(x) + sqrt(1 + sin(x) * sin(x)));
}


const double eps=1e-10;
double a,b;
double f(double x){	//积分函数
	//return 2 * pi * (2 + cos(x)) * sqrt(1 + sin(x) * sin(x));
	return sqrt(1 + sin(x) * sin(x));
}
//三点simpson法
double simpson(double a,double b){
	double c =  a+(b-a)/2;
	return (f(a) + 4*f(c) + f(b))*(b-a)/6;
}
//自适应Simpson公式(递归过程)。已知整个区间[a,b]上的三点simpson值A 
double asr(double a , double b ,double eps ,double A){
	double c = a+ (b-a)/2;
	double L = simpson(a,c) ,R = simpson(c,b);
	if(fabs(A-L-R)<=15*eps) return L + R +(A-L-R)/15;
	return asr(a,c,eps/2,L) + asr(c,b,eps/2,R);
}
//自适应Simpson公式(主过程) 
double asr(double a, double b, double eps){
	return asr(a, b, eps, simpson(a, b));
}

double calculate(double l, double r, double eps) {
	return asr(l, r, eps);
}

double calc_s(double z1, double z2)
{
	double r = 2.0 + std::cos(z1);
	double s = pi * r * r;
//	s += calculate(z1, z2, eps);
	s += pi * (tmp_f(z2) - tmp_f(z1));
	//s += 4 * pi * calculate(z1, z2, eps);
	int bl = (z2 - z1) / (pi);
	s += bl * 4 * pi * calculate(0, pi, eps);
	double lv = z2 - z1 - bl * pi;
	s += 4 * pi * calculate(z1, z1 + lv, eps);
	return s;
}

double calc_v(double z1, double z2)
{
	double s = 4.0 * pi * (z2 - z1) + 2.0 * pi * delta_sin;
	s += 0.5 * pi * (z2 - z1) - 0.5 * pi * 0.5 * (std::sin(2.0 * z2) - std::sin(2.0 * z1));
	return s;
}

int main()
{
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> z1 >> z2;
		delta_sin = std::sin(z2) - std::sin(z1);
		//std::cout << std::setprecision(2) << std::fixed << calc_v(z1, z2) << ' ' << calc_s(z1, z2) << '\n';
		printf("%.2f %.2f\n",  calc_v(z1, z2), calc_s(z1, z2));
	}
}

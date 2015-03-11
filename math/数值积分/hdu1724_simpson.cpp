#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-6;
double a,b;
double f(double x){	//积分函数
	return 2*b*sqrt(1-x*x/(a*a));
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
int main(){
	int T;
	double l,r;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
		printf("%.3f\n",asr(l,r,eps));
	}
	return 0;
}

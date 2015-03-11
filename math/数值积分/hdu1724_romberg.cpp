#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
#define PB push_back
const double EPS=1e-4;
template<class T>
double romberg(const T &f,double a,double b){
	vector<double> t;
	double h=b-a,last,curr;
	int k=1,i=1;
	t.PB(h*(f(a)+f(b))/2);	//梯形
	do{
		last=t.back();
		curr=0;
		double x=a+h/2;
		for(int j=0;j<k;++j){
			curr+=f(x);
			x+=h;
		}
		curr=(t[0]+h*curr)/2;
		double k1=4.0/3.0,k2=1.0/3.0;
		for(int j=0;j<i;++j){
			double tmp=k1*curr-k2*t[j];
			t[j]=curr;
			curr=tmp;
			k2/=4*k1-k2;
			k1=k2+1;
		}
		t.PB(curr);
		k*=2;
		h/=2;
		++i;
	}while(fabs(last-curr)>EPS);
	return t.back();
}
double a,b;
double f(double x){	//积分函数
	return 2*b*sqrt(1-x*x/(a*a));
}
int main(){
	int T;
	scanf("%d",&T);
	double l,r;
	while(T--){
		scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
		printf("%.3f\n",romberg(f,l,r));
	}
	return 0;
}

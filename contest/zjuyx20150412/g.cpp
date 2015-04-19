#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main(){
	double r,h,d;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf",&r,&h,&d);
		double v=4.0*pi/3.0*d*d*d+r*d*d*pi*pi+pi*(r+d)*(r+d)*h+pi*r*r*2.0*d;
		double s=4.0*pi*d*(pi*r/2+d)+pi*2*(r+d)*h+pi*r*r*2;
		printf("%.12f %.12f\n",v,s);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	//(Vo*sqrt(Vo^2+2gh))/2g
	double g=9.8;
	double h,v;
	double ans;
	int T;
	scanf("%d\n",&T);
	while(T--){
	scanf("%lf%lf",&h,&v);
	ans=v*sqrt(v*v+2*g*h)/g;
	printf("%.2f\n",ans);
	}
	return 0;
}

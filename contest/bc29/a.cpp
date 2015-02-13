#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-10;
int main(){
	double a,b,c,d;
	while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF){
		double t1,t2;
		t1=b*log(a);
		t2=d*log(c);
		if(fabs(t1-t2)<eps) puts("=");
		else if(t1<t2) puts("<");
		else puts(">");
	}
	return 0;
}

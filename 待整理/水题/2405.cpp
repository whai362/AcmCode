//¦Ðh(R^2£«Rr£«r^2)/3
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.1415926
int main(){
	double D,d,V;
	while(scanf("%lf%lf",&D,&V)&&(D||V)){
		d=pow(D*D*D-6*V/pi,1.0/3);
		printf("%.3f\n",d);
	}
	return 0;
}

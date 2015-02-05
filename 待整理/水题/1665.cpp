#include<stdio.h>
#define pi 3.1415927
int main(){
	double d,t,mph;
	int cas=0,r;
	while(scanf("%lf%d%lf",&d,&r,&t)&&r){
		d=d*pi*r/12/5280;
		mph=d*3600/t;
		printf("Trip #%d: %.2f %.2f\n",++cas,d,mph);
	}
	return 0;
}

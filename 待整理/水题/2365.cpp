#include<stdio.h>
#include<math.h>
#define pi 3.1416
int main(){
	int i,n;
	double r,l,x[110],y[110];
	scanf("%d%lf",&n,&r);
	for(i=0;i<n;++i) scanf("%lf%lf",&x[i],&y[i]);
	l=sqrt((x[0]-x[n-1])*(x[0]-x[n-1])+(y[0]-y[n-1])*(y[0]-y[n-1]));
	for(i=1;i<n;++i) l=l+sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
	printf("%.2f\n",l+2*pi*r);
	return 0;
}

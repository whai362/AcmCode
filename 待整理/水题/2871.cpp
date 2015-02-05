#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	double t,t0;
	scanf("%lf",&t0);
	while(scanf("%lf",&t)&&abs(t-999)>1e-10){
		printf("%.2f\n",t-t0);
		t0=t;
	}
	printf("End of Output\n");
	return 0;
}

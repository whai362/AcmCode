#include<stdio.h>
#include<math.h>
int main(){
	double vs,r,c,w,vr;
	int t;
	scanf("%lf%lf%lf%d",&vs,&r,&c,&t);
	while(t--){
		scanf("%lf",&w);
		vr=c*r*w*vs/sqrt(1+c*r*w*c*r*w);
		printf("%.3f\n",vr);
	}
	return 0;
}

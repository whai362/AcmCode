#include<stdio.h>
#include<math.h>
int main(){
	double k,n,p;
	while(scanf("%lf%lf",&n,&p)!=EOF){
		k=pow(p,1/n);
		printf("%.0f\n",k);
	}
	return 0;
}

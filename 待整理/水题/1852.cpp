#include<stdio.h>
int main(){
	int a,amax,amin,l,n,max,min,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&l,&n);
		max=0,min=0;
		while(n--){
			scanf("%d",&a);
			if(a>l-a) amax=a,amin=l-a;
			else amax=l-a,amin=a;
			if(amax>max) max=amax;
			if(amin>min) min=amin;
		}
		printf("%d %d\n",min,max);
	}
	return 0;
}

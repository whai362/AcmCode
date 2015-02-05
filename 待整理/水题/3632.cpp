#include<stdio.h>
int main(){
	int i,n,max,min,t,a[25];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		max=0,min=100;
		for(i=0;i<n;++i){
			scanf("%d",&a[i]);
			if(a[i]>max) max=a[i];
			if(a[i]<min) min=a[i];
		}
		printf("%d\n",2*(max-min));
	}
	return 0;
}

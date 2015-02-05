#include<stdio.h>
int main(){
	int a[50],cas=0,i,n,t;
	a[0]=a[1]=1;
	for(i=2;i<50;++i) a[i]=a[i-1]+a[i-2];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("Scenario #%d:\n%d\n\n",++cas,a[n+1]);
	}
	return 0;
}

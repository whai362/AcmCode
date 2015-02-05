#include<stdio.h>
int main(){
	int cas=0,i,n,d,b,e,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&d,&b,&e);
		printf("Problem set %d: %d / %d, base 7 digits %d through %d: ",++cas,n,d,b,e);
		n=n%d;
		for(i=0;i<b;++i) n=n*7%d;
		for(i=0;i<=e-b;++i){
			printf("%d",n*7/d);
			n=n*7%d;
		}
		printf("\n");
	}
	return 0;
}

#include<stdio.h>
int deal(int n){
	int i,sum=0;
	for(i=1;i<=n/2;++i){
		if(n%i==0) sum=sum+i;
	}
	return sum;
}
int main(){
	int m,n,f=1;
	while(scanf("%d",&n)&&n){
		m=deal(n);
		if(f) printf("PERFECTION OUTPUT\n"),f=0;
		printf("%5d  ",n);
		if(n==m) printf("PERFECT\n");
		else if(n>m) printf("DEFICIENT\n");
		else printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}

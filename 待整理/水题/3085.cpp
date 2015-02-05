#include<stdio.h>
int main(){
	int i,n,t,tmp;
	scanf("%d",&t);
	for(i=1;i<=t;++i){
		scanf("%d",&n);
		tmp=n/25;
		printf("%d %d QUARTER(S), ",i,tmp);
		n=n%25;
		tmp=n/10;
		printf("%d DIME(S), ",tmp);
		n=n%10;
		tmp=n/5;
		printf("%d NICKEL(S), ",tmp);
		n=n%5;
		printf("%d PENNY(S)\n",n);
	}
	return 0;
}

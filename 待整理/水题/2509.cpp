#include<stdio.h>
int main(){
	int n,m,sum;
	while(scanf("%d%d",&n,&m)!=EOF){
		sum=n;
		while(n>=m){
			sum=sum+n/m;
			n=n/m+n%m;
		}
		printf("%d\n",sum);
	}
	return 0;
}

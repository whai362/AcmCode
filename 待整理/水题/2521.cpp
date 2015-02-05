#include<stdio.h>
int main(){
	int n,m,p,c,lose;
	while(scanf("%d%d%d%d",&n,&m,&p,&c)&&(n||m||p||c)){
	lose=n+c-(m+c-p);
	printf("%d\n",lose);
	}
	return 0;
}

#include<stdio.h>
int main(){
	int A,a,B,b,p;
	scanf("%d%d%d%d%d",&A,&a,&B,&b,&p);
	if(A<=p&&B<=a||B<=p&&A<=b||A+B<=p) printf("Yes\n");
	else printf("No\n");
	return 0;
}
//有三种情况，坑死了

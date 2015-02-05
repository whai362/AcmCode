#include<cstdio>
int main(){
	int i,a,b,c,sum=0;
	scanf("%d%d%d",&a,&b,&c);
	for(i=0;i<b;++i){
		sum+=a+i;
	}
	sum=2*sum+(a+b-1)*(c-b-1);
	printf("%d\n",sum);
	return 0;
}

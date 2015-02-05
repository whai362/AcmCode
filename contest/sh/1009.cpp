#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
void gao(LL n){
	if(n){
		gao(n/2);
		printf("%lld",n%2);
	}
}
int main(){
	LL b1,b2,t;
	char n1[1005],n2[1000];
	int i,n,k,nLen1,nLen2,ret;
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		ret=0;
		scanf("%s",szLine1);
		scanf("%s",szLine2);
		nLen1=strlen(szLine1);
		nLen2=strlen(szLine2);
		for(i=0;i<nLen1;i++)
		{
			ret*=2;
			ret+=(szLine1[i]-48);
		}
		B1=ret;
		ret=0;
		for(i=0;i<nLen2;i++)
		{
			ret*=2;
			ret+=(szLine2[i]-48);
		}
		B2=ret;
		if(B1<B2)
		{t=B1;B1=B2;B2=t;}
		while(B2)
		{
			t=B1?;
			B1=B2;
			B2=t;
		}
		fun(B1);
		printf("\n");
	}
	return 0;
}

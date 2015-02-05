#include<stdio.h>

int gcd(int a,int b){
	if(b) return gcd(b,a%b);
	return a;
}
int main(){
	int n,cas,i;
	__int64 ans;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);
		for(i=n/2;i>=1;i--){
			if(gcd(n-i,i)==1){
				ans=n-i;
				ans*=(__int64)(i);
				printf("%I64d\n",ans);
				break;
			}
		}
	}
}


#include<stdio.h>
int main(){
	long long n,k=1,count=0;
	while(scanf("%lld",&n)!=EOF){
		k=1,count=0;
		while(k<=n){
			k=k<<1;
			++count;	
		}
		while(k!=1){
			if(k>n) k=2*(k-n)-1;
			else k=k<<1;
			++count;
		}
		printf("%lld\n",count);
	}
	return 0;
}

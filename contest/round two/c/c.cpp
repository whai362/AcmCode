#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	long long n,k=1,count=0;
	while(scanf("%lld",&n)!=EOF){
		k=1,count=0;
		while(k<=n){
			k=k<<1;
			++count;	
		}
		k=2*n/(2*n+1-k);
		while(k!=1){
			k=k>>1;
			++count;
		}
		printf("%lld\n",count);
	}
	return 0;
}

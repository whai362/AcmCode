#include<stdio.h>
long long gcd(long long a,long long b){
	if(b) return gcd(b,a%b);
	return a;
}
int main(){
	int i,t;
	long long n,tmp,a;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		tmp=1;
		for(i=0;i<n;++i){
			scanf("%lld",&a);
			tmp=tmp*a/gcd(tmp,a);
		}
		printf("%lld\n",tmp);
	}
	return 0;
}

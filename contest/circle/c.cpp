#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;
const LL MAX=100000000000LL;

LL phi(LL n){
	LL x=n,i;
	LL ans=n;
	for(i=2;i*i<=x;i++){
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0)
				x/=i;
		}
	}
	if(x!=1)
		ans=ans/x*(x-1);
	return ans;
}

LL multi(LL a,LL b,LL m){//a*b%m
	LL ret=0;
	while(b>0){
		if(b&1){
			ret+=a;
			if(ret>=m)
				ret-=m;
		}
		a+=a;
		if(a>=m)
			a-=m;
		b>>=1;
	}
	return ret;
}

LL quickmod(LL a,LL n,LL MOD){//a^n%MOD
	LL ans=1;
	ans%=MOD;
	for(;n>0;n>>=1,a=multi(a,a,MOD))
		if(n&1)
			ans=multi(ans,a,MOD);
	return ans;
}

int main(){
	int cas=0;
	LL n,i;
	while(~scanf("%lld",&n)&&n){
		int k=0;
		while(n%2==0){
			n/=2;
			k++;
		}
		if(k>3||n%5==0){
			printf("0\n");
			continue;
		}
		n*=9;
		LL len=phi(n);
		LL ans=MAX;
		for(i=1;i*i<=len;i++){
			if(len%i==0){
				LL f=len/i;
				if(quickmod(10,i,n)==1) ans=min(ans,i);
				if(quickmod(10,f,n)==1) ans=min(ans,f);
			}
		}
		if(ans==MAX) ans=0;
		printf("%lld\n",ans);
	}
	return 0;
}

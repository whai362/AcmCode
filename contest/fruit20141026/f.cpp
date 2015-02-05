#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL long long
LL a4m(LL n,LL m){
	//n(n+1)(2n+1)(3n^2+3n-1)/30
	LL t1=n*(n+1),
	   t2=2*n+1,
	   t3=3*n*n+3*n-1;
	LL a[]={2,3,5};
	bool hash[3]={0,0,0};
	for(int i=0;i<3;++i)
		if(!hash[i] && t1%a[i]==0){
			t1/=a[i];
			hash[i]=true;
		}
	for(int i=0;i<3;++i)
		if(!hash[i] && t2%a[i]==0){
			t2/=a[i];
			hash[i]=true;
		}
	for(int i=0;i<3;++i)
		if(!hash[i] && t3%a[i]==0){
			t3/=a[i];
			hash[i]=true;
		}
	LL ret=t1*t2%m;
	ret=ret*t3%m;
	return ret;
}
int main(){
	int T;
	LL n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		LL lim=sqrt(n);
		LL ans=0;
		for(LL i=1;i<=lim;++i)
			ans=(ans+(n/i)*((a4m(i,m)-a4m(i-1,m)+m)%m)%m)%m;
		//cout<<ans<<endl;
		LL l=lim,r;
		for(LL i=n/lim;i>0;--i){
			r=n/i;
			ans=(ans+i*((a4m(r,m)-a4m(l,m)+m)%m)%m)%m;
			l=r;
		}
		printf("%lld\n",ans);
	}	
	return 0;
}

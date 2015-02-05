#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL long long
int main(){
	LL n,m;
	cin>>n;
	scanf("%lld%lld",&n,&m);
	LL ans=0,tmp;
	int lim=sqrt(n);
	for(LL i=1;i<=lim;++i){
		tmp=1;
		for(int j=0;j<4;++j)
			tmp=tmp*i%m;
		tmp=tmp*(n/i)%m;
		ans=(ans+tmp)%m;
	}
	cout<<ans<<endl;
	for(LL i=lim+1;i<=n;++i){
		tmp=1;
		for(int j=0;j<4;++j)
			tmp=tmp*i%m;
		tmp=tmp*(n/i)%m;
		ans=(ans+tmp)%m;
	}
	cout<<ans<<endl;
}

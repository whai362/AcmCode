//1+(1+n)n/2
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	long long n;
	scanf("%lld",&n);
	if(n==1) cout<<0<<endl;
	else if(n==2) cout<<1<<endl;
	else{
	long long ans,tmp=(n-1)*2;
	tmp=(long long)(sqrt(tmp+0.0)+1.0);
	for(long long i=tmp;i>0;--i){
		if((i+1)*i/2+1<n){
			ans=i+1;
			break;
		}
	}
	cout<<ans<<endl;
	}
	}
	return 0;
}

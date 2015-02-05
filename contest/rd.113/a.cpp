#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,T;
	int i;
	long long ans,a;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	ans=1;
	for(i=0;i<n;++i){
		//scanf("%lld",&a);
		cin>>a;
		ans=ans*a/__gcd(ans,a);
	}
	//printf("%lld\n",ans);
	cout<<ans<<endl;
	}
	return 0;
}

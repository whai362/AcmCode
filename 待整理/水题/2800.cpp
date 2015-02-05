#include<iostream>
using namespace std;
int a[100005];
int main(){
	int i,n,k,cnt=0;
	cin>>n>>k;
	__int64 ans=0;
	for(i=1;k>=i && i<=100000;++i){
		a[cnt++]=k/i;
	}
	//cout<<"cnt"<<cnt<<endl;
	if(n>k) ans+=(__int64)(n-k)*(__int64)k;
	//cout<<"ans"<<ans<<endl;
	for(i=0;i<cnt-1;++i){
		__int64 tmp;
		if(n>k){
			tmp=((__int64)a[i]+(__int64)a[i+1]+1)*(__int64)(a[i]-a[i+1])/2;
			//cout<<"tmp"<<tmp<<endl;
			ans+=(__int64)(a[i]-a[i+1])*(__int64)k-((__int64)i+1)*tmp;
			//cout<<"ans"<<ans<<endl;
		}
		else{
			if(a[i+1]>n) continue;
			if(a[i]>=n && a[i+1]<=n){
				tmp=((__int64)n+(__int64)a[i+1]+1)*(__int64)(n-a[i+1])/2;
				ans+=(__int64)(n-a[i+1])*(__int64)k-((__int64)i+1)*tmp;
			}
			else{
				tmp=((__int64)a[i]+(__int64)a[i+1]+1)*(__int64)(a[i]-a[i+1])/2;
				ans+=(__int64)(a[i]-a[i+1])*(__int64)k-((__int64)i+1)*tmp;
			}
		}
	}
	//cout<<"ans"<<ans<<endl;
	int t=min(n,k/cnt);
	for(i=1;i<=t;++i){
		ans+=(__int64)(k%i);
	}
	cout<<ans<<endl;
	return 0;
}

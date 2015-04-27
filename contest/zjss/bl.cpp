#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
//int a[15];
LL a=1000000000LL;
LL MOD=998244353;
int main(){
//	int n;
//	scanf("%d",&n);
//	int ans=0;
//	for(int i=0;i<n;++i){
//		scanf("%d",&a[i]);
//	}
//	for(int i=0;i<n;++i){
//		for(int j=i+1;j<n;++j){
//			int t=(a[i]^a[j]);
//			if(t>a[i] && t>a[j]){ cout<<a[i]<<' '<<a[j]<<endl; ++ans; }
//		}
//	}
//	cout<<ans<<endl;
	cout<<(a*a/2*4%MOD+a*a*4%MOD)%998244353<<endl;
}

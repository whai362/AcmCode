#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[1005];
int main(){
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		long long ans=0,sum=a[0];
		for(int i=1;i<n;++i){
			ans+=sum;
			sum+=a[i];
		}
		cout<<ans+sum<<endl;
	}
}

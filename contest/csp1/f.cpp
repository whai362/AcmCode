#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[10005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%lld",&a[i]);
		}
		long long ans=a[0];
		for(int i=1;i<n;++i){
			ans=__gcd(ans,a[i]);
		}
		cout<<ans<<endl;
	}
}

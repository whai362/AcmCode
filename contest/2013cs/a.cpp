#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1000005;
LL s[N],p[N],dp[N];
int main(){
	int T;
	int n,m;
	LL q;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			scanf("%lld%lld",&s[i],&p[i]);
		}
		dp[n-1]=s[n-1]*p[n-1];
		for(int i=n-2;i>=0;--i){
			dp[i]=min(s[i]*p[i],dp[i+1]);
		}
		LL ans;
		for(int i=0;i<m;++i){
			scanf("%lld",&q);
			int pos=upper_bound(s,s+n,q)-s;
			if(pos>=0 && pos<n){
				ans=min(q*p[pos-1],dp[pos]);
			}
			else{
				ans=q*p[n-1];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}


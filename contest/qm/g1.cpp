#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=105;
int c[N],w[N],v[N];
int dp[1005][1005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		int n,m,c0,d0;
		scanf("%d%d%d%d",&n,&m,&c0,&d0);
		c[1]=n/c0,w[1]=c0,v[1]=d0;
		for(int i=2;i<=m+1;++i){
			int a,b,cc,d;
			scanf("%d%d%d%d",&a,&b,&cc,&d);
			c[i]=min(n/cc,a/b);
			w[i]=cc;
			v[i]=d;
		}
		//for(int i=1;i<=m+1;++i){
		//	cout<<c[i]<<' '<<w[i]<<' '<<v[i]<<endl;
		//}
		int ans=0;
		for(int i=1;i<=m+1;++i){
			for(int j=n;j>=0;--j){
				for(int k=0;k<=c[i];++k){
					if(j>=k*w[i])
						dp[i][j]=max(dp[i][j],dp[i-1][j-k*w[i]]+k*v[i]);

					ans=max(ans,dp[i][j]);
					//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

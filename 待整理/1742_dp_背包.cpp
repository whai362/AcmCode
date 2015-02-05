#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[105],c[105],cnt[100005],dp[100005],hash[100005];
int main(){
	int ans,i,j,n,m;
	while(scanf("%d%d",&n,&m) && (n||m)){
		ans=0;
		memset(dp,0,sizeof(dp));
		memset(hash,0,sizeof(hash));
		for(i=0;i<n;++i)
		  scanf("%d",&a[i]);
		for(i=0;i<n;++i)
		  scanf("%d",&c[i]);
		for(i=0;i<n;++i){
			memset(cnt,0,sizeof(cnt));
			for(j=a[i];j<=m;++j){
				if(dp[j]<dp[j-a[i]]+a[i] && cnt[j-a[i]]<c[i]){
					dp[j]=dp[j-a[i]]+a[i];
					if(hash[dp[j]]==0) ++ans,cout<<dp[j]<<endl,hash[dp[j]]=1;
					cnt[j]=cnt[j-a[i]]+1;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

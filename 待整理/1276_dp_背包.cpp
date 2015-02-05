#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 100005
int cnt[MAXN],dp[MAXN],n[MAXN],d[MAXN];
int main(){
	int c,N;
	int i,j;
	while(scanf("%d%d",&c,&N)!=EOF){
		memset(dp,0,sizeof(dp));
		for(i=0;i<N;++i){
			scanf("%d%d",&n[i],&d[i]);
		}
		/*DP*/
		for(i=0;i<N;i++){
			memset(cnt,0,sizeof(cnt));
			for(j=d[i];j<=c;++j){
				if(dp[j]<dp[j-d[i]]+d[i] && cnt[j-d[i]]<n[i]){
					dp[j]=dp[j-d[i]]+d[i];
					cnt[j]=cnt[j-d[i]]+1;
				}
			}
		}
		printf("%d\n",dp[c]);
	}
	return 0;
}

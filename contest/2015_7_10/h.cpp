#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
const int N=45;
const int MAXN=((1<<20)+5);
int a[N];
LL dp[N][MAXN];
void gao(int n,int m){
	memset(dp,0,sizeof(dp));
	int maxx=0;
	LL ans=0;
	for(int i=0;i<n;++i){
		dp[i][a[i]]=1;
		//maxx=max(maxx,a[i]);
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<MAXN;++j){
			if(dp[i][j]==0) continue;
			//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			if(j>=m)
				ans+=dp[i][j];
			for(int k=i+1;k<n;++k){
				dp[k][j^a[k]] += dp[i][j];
				//maxx=max(maxx,j^a[k]);
			}
		}
	}
	if(m==0) ans++;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}

		printf("Case #%d: ",++cas);
		gao(n,m);
	}
	return 0;
}

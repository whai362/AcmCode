#include<iostream>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
int b[55][55];
int a[105];
int dp[105][55];
void gao(int n,int m){
	for(int i=0;i<n;++i)
		for(int j=0;j<=m;++j)
			dp[i][j]=-INF;

	if(a[0]==-1)
		for(int i=1;i<=m;++i)
			dp[0][i]=0;
	else
		dp[0][a[0]]=0;

	for(int i=1;i<n;++i){
		if(a[i]!=-1){
			for(int j=1;j<=m;++j){
				dp[i][a[i]]=max(dp[i-1][j]+b[j-1][a[i]-1],dp[i][a[i]]);
			}
		}
		else{
			for(int j=1;j<=m;++j){
				for(int k=1;k<=m;++k){
					dp[i][k]=max(dp[i-1][j]+b[j-1][k-1],dp[i][k]);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;++i)
		ans=max(dp[n-1][i],ans);
	cout<<ans<<endl;
}
int main(){
	int T;
	int n,m;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i){
			for(int j=0;j<m;++j){
				scanf("%d",&b[i][j]);
			}
		}
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		gao(n,m);
	}
	return 0;
}

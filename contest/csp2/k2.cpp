#include<cstdio>
#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;
long long a[105][105],dp[105][105];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=0;i<m;++i)
		dp[0][i]=a[0][i];
	for(int i=1;i<n;++i){
		for(int j=i;j<m;++j){
			long long _max=-INF;
			for(int k=0;k<j;++k){
				_max=max(_max,dp[i-1][k]);
			}
			dp[i][j]=_max+a[i][j];
		}
	}
	long long ans=-INF;
	for(int i=0;i<m;++i){
		ans=max(ans,dp[n-1][i]);
	}
	cout<<ans<<endl;
	}
	return 0;
}

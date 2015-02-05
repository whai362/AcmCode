#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 105
long long dp[N][N];
int main(){
	int n;
	int i,j;
	while(scanf("%d",&n)!=EOF){
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;++i)
		dp[i][0]=1;
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(j<=i){
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
			else break;
		}
	}
	cout<<dp[n][n]<<endl;
	}
	return 0;
}

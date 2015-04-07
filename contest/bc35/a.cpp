#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL __int64
LL dp[30][15][2][15];
LL C[25][25];
int main(){
	int n,m;
	for(int i=0;i<=24;++i)
		C[i][0]=C[i][i]=1;
	for(int i=2;i<=24;++i){
		for(int j=1;j<i;++j){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n+m;++i){
			dp[i][0][0][0]=dp[i][i][1][0]=1;
			for(int j=1;j<i;++j)
				dp[i][j][0][0]=1;
		}
		for(int i=1;i<=n+m;++i){
			for(int j=1;j<=min(i,n);++j){
				for(int k=1;k<=min(n,m);++k){
					dp[i][j][0][k]=dp[i-1][j][1][k]+dp[i-1][j][0][k];
					dp[i][j][1][k]=dp[i-1][j-1][1][k]+dp[i-1][j-1][0][k-1];
				}
			}
		}
		LL A=0,B=C[n+m][n];
		for(int i=1;i<=min(n,m);++i){
			A+=(dp[n+m][n][0][i]+dp[n+m][n][1][i])*i;
		}
		//cout<<A<<' '<<B<<endl;
		LL tmp=__gcd(A,B);
		A/=tmp;
		B/=tmp;
		printf("%I64d/%I64d\n",A,B);
	}
	return 0;
}

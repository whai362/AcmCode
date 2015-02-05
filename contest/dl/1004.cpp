#include<cstdio>
#include<iostream>
using namespace std;
#define N 1005
bool map[N][N];
int n,m,dp[N][N];
bool check(int len){
	int i,j;
	for(i=len;i<=n;++i)
	  for(j=len;j<=n;++j){
		  if(dp[i][j]-dp[i-len][j]-dp[i][j-len]+dp[i-len][j-len]==0) return 1;
	  }
	return 0;
}
int main(){
	int i,j,x,y;
	while(~scanf("%d%d",&n,&m)) {
		for(i=1;i<=n;++i)
		  for(j=1;j<=n;++j){
			  map[i][j]=0;
		  }
		for(i=0;i<m;++i){
			scanf("%d%d",&x,&y);
			map[x][y]=1;
		}
		for(i=1;i<=n;++i)
		  for(j=1;j<=n;++j){
			  dp[i][j]=map[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		  }
		if(dp[n][n]==n*n) printf("0\n");
		else {
			int mid,lower=1,upper=n;
			while(lower<upper){
				mid=(lower+upper)/2;
				if(check(mid +1)) lower=mid+1;
				else upper=mid;
			}
			printf("%d\n",lower*lower);
		}
	}
	return 0;
}

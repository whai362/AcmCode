#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

double dp[2][260];
int main(){
	int n,m,l,r;
	while (~scanf("%d%d%d%d",&n,&m,&l,&r)){
		if (n==0&&m==0&&l==0&&r==0) break;
		memset(dp,0,sizeof(dp));
		dp[0][1]=1;
		int side=0;
		int x;
		for (int i=1;i<=m;i++){
			scanf("%d",&x);
			for (int j=1;j<=n;j++){
				dp[1-side][j]=dp[side][(j+x)%n==0? n:((j+x)%n)]/2+dp[side][(j-x+n)%n==0?n:((j-x+n)%n)]/2;
				//dp[1-side][j]=0.5*dp[side][(j+x)%n==0? n:((j+x)%n)]+0.5*dp[side][(j-x+n)%n==0?n:((j-x+n)%n)];
				//dp[1-side][(j+x)%n]+=dp[side][j]/2;
				//dp[1-side][(j-x+n)%n]+=dp[side][j]/2;
			}
			side=1-side;
		}
		double ans=0;
		for (int i=l;i<=r;i++){
			ans+=dp[side][i];
		}
		printf("%.4f\n",ans);
	}
	return 0;
}

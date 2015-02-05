#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

double dp[10050][150];
double p[150][150];
int a[150];
int main(){
	int m,n,top;
	while (~scanf("%d",&m)){
		int top=(m)*(m-1)*(m-2)/6;
		for (int i=0;i<top;i++){
			for (int j=0;j<top;j++){
				scanf("%lf",&p[i][j]);
			}
		}
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		memset(dp,0,sizeof(dp));
		for (int i=0;i<top;i++){
			dp[0][i]=max(dp[0][i],p[i][a[0]]);
			dp[0][a[0]]=max(dp[0][a[0]],p[i][a[0]]);
		}
		for (int i=1;i<n;i++){
			for (int j=0;j<top;j++){
				dp[i][j]=max(dp[i][j],dp[i-1][j]*p[j][a[i]]);
				dp[i][a[i]]=max(dp[i][a[i]],dp[i-1][j]*p[j][a[i]]);
			}
		}

		double Max=0;
		for (int i=0;i<top;i++)
			if (dp[n-1][i]>Max) Max=dp[n-1][i];
		printf("%.6f\n",Max);
	}
	return 0;
}

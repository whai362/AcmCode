#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005;
double dp[N][N];
int main(){
	int n,t;
	double p;
	scanf("%d%lf%d",&n,&p,&t);
	dp[0][0]=1;
	for(int i=1;i<=t;++i){
		for(int j=0;j<=min(n,i);++j){
			if(j<n) dp[i][j]=dp[i-1][j]*(1-p);
			else dp[i][j]=dp[i-1][j];
			if(j)
				dp[i][j]+=dp[i-1][j-1]*p;
		}
	}
	double ans=0;
	for(int i=0;i<=t;++i)
		ans+=dp[t][i]*i;
	printf("%.7f\n",ans);
	return 0;
}

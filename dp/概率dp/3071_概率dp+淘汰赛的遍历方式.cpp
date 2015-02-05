#include<iostream>
#include<cstdio>
using namespace std;
double p[130][130];
double dp[130][8];
int main(){
	int ans,i,j,k,n,m;
	double sum;
	while(scanf("%d",&n) && n!=-1){
		m=(1<<n);
		for(i=0;i<m;++i){
			for(j=0;j<m;++j){
				scanf("%lf",&p[i][j]);
			}
			dp[i][0]=1;
		}
		for(i=0;i<n;++i){
			ans=0;
			for(j=0;j<m;++j){
				sum=0;
				for(k=(1<<i);k<(1<<(i+1));++k){	//¾«ÃîÖ®´¦
					sum+=dp[k^j][i]*p[j][k^j];
				}
				// 00
				// 01
				// 10
				// 11
				dp[j][i+1]=dp[j][i]*sum;
				if(dp[j][i+1]>dp[ans][i+1]) ans=j;
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}

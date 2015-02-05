#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=5005;
double dp[N][N];
double pi[N];
int ti[N];
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i){
		scanf("%lf%d",&pi[i],&ti[i]);
		pi[i]/=100;
	}
	double sum,bei,tmp;
	double ans=0;
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		bei=pow(1-pi[i],ti[i]-1);
		sum=0;
		for(int j=1;j<=t;++j){
			sum=sum*(1-pi[i])+dp[i-1][j-1]*pi[i];
			if(j>=ti[i]){
				sum-=dp[i-1][j-ti[i]]*pi[i]*bei;
				tmp=sum+dp[i-1][j-ti[i]]*bei;
			}
			else tmp=sum;
			dp[i][j]+=tmp;
			ans+=dp[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
double pi[N];
int ti[N];
double dp[N][N][2];
double sc[N];
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i){
		scanf("%lf%d",&pi[i],&ti[i]);
		if(ti[i]==1) pi[i]=100;
		pi[i]/=100;
		double tmp=pi[i];
		double sp=tmp;
		for(int j=2;j<ti[i];++j){
			tmp=tmp*(1-pi[i]);
			sp+=tmp;
		}
		sc[i]=1-sp;
	}
	dp[0][0][0]=1;
	//dp[1][ti[1]][0]+=sc[1];
	for(int i=1;i<=n;++i){
		cout<<sc[i]<<' ';
	}
	cout<<endl;
	for(int i=1;i<=min(t,ti[1]-1);++i){
		dp[0][i][1]+=(dp[0][i-1][0]+dp[0][i-1][1])*(1-pi[1]);
	}
	int ts=ti[1];
	for(int i=1;i<=n;++i){
		ts+=ti[i+1];
		for(int j=i;j<=min(t,ts-1);++j){
			dp[i][j][0]+=(dp[i-1][j-1][0]+dp[i-1][j-1][1])*pi[i];
			dp[i][j][1]+=(dp[i][j-1][0]+dp[i][j-1][1])*(1-pi[i+1]);
			//dp[i+1][j+ti[i+1]][0]+=dp[i][j][0]*sc[i+1];
		}
	}

	for(int i=0;i<=n;++i){
		for(int j=1;j<=t;++j)
			cout<<dp[i][j][0]<<'|'<<dp[i][j][1]<<' ';
		cout<<endl;
	}
	double ans=0;
	for(int i=1;i<=n;++i)
		ans+=(dp[i][t][0]+dp[i][t][1])*i;
	printf("%.10f\n",ans);
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5005;
double dp[N][N],p[N],f[N];
double eps=1e-30;
int main(){
	dp[0][0]=1.0;
	int n,t;
	scanf("%d%d",&n,&t);
	double pi;
	int ti;
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		scanf("%lf%d",&pi,&ti);
		pi/=100;
		if(ti==1) pi=1.0-eps;
		if(pi==0) pi=eps;
		p[1]=pi;
		double sum=p[1];
		for(int j=2;j<ti;++j){
			p[j]=p[j-1]*(1-pi);
			sum+=p[j];
		}
		if(ti!=1) p[ti]=1-sum;
		for(int j=1;j<=t;++j)
			f[j]=eps;
		for(int j=i;j<=t;++j){
			if(j+ti>t+1) f[j]=p[t-j+1]/pi*(1-pi);
		}
		
		cout<<'p'<<endl;
		for(int j=1;j<=ti;++j){
			cout<<p[j]<<' ';
		}
		cout<<endl;

		cout<<'f'<<endl;
		for(int j=1;j<=t;++j){
			cout<<f[j]<<' ';
		}
		cout<<endl;

		double s=dp[i-1][i-1]*pi,
			   fs=dp[i-1][i-1]*f[i];
		dp[i][i]=s;
		if(i==t) dp[i-1][t]+=fs;
		if(i==1)
			for(int j=i+1;j<=min(i+ti-1,t);++j){
				s=p[j];
				dp[i][j]=s;
			}
		else
			for(int j=i+1;j<=min(i+ti-1,t);++j){
				s=s*p[j-i+1]/p[j-i]+dp[i-1][j-1]*pi;
				fs+=dp[i-1][j-1]*f[j];
				dp[i][j]=s;
				if(j==t){
					dp[i-1][t]+=fs;
				}
			}

		cout<<"dp"<<endl;
		for(int j=1;j<=t;++j){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	double ans=0;
	for(int i=1;i<=n;++i){
		ans+=dp[i][t]*i;
	}
	printf("%.9f\n",ans);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define Min(x,y) (((x)<(y))?(x):(y))
#define inf 1000
int m,n,dp[105],p[105][105];
int main(){
	int i,j,k,max,u,v,c;
	scanf("%d%d",&n,&m);
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j) p[i][j]=inf;
		p[i][i]=inf;
	}
	for(i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		p[u][v]=0;
	}
	dp[1]=1;
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(i==j) continue;
			if(p[i][j]<inf) dp[j]+=dp[i];
			cout<<i<<' '<<j<<' '<<dp[j]<<endl;
			for(k=1;k<=n;++k){
				if(p[i][k]+p[k][j]<inf) dp[j]+=dp[i];
				cout<<i<<' '<<j<<' '<<dp[j]<<endl;
			}
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}


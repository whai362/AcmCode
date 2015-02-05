#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1505
struct road{
	short n,to[N];
}r[N];

int dp[N][2];

void DP(int root){
	int i,dp0=0,dp1=0;
	if(!r[root].n){
		dp[root][0]=0;
		dp[root][1]=1;
		return ;
	}
	for(i=0;i<r[root].n;++i){
		DP(r[root].to[i]);
		dp0+=dp[r[root].to[i]][1];
		dp1+=min(dp[r[root].to[i]][0],dp[r[root].to[i]][1]);
	}
	dp[root][0]=dp0;
	dp[root][1]=dp1+1;
	return ;
}

int main(){
	int from,i,j,n,root;
	while(~scanf("%d",&n)){
		root=-1;
		memset(r,0,sizeof(r));
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;++i){
			scanf("%d",&from);
			scanf(":(%d)",&r[from].n);
			if(root==-1) root=from;
			for(j=0;j<r[from].n;++j){
				scanf("%d",&r[from].to[j]);
				if(r[from].to[j]==root) root=from;
			}
		}
		DP(root);
		printf("%d\n",min(dp[root][0],dp[root][1]));
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 205
char name1[N][105],name2[N][105];
int flag,n,r[N],dp[N][2];
int check(char name[]){ for(int i=0;i<n;++i) if(!strcmp(name,name1[i])) return i; }
void DP(int root){
	int i,dp0=0,dp1=0;
	for(i=1;i<n;++i)
		if(r[i]==root){
			DP(i);
			dp0+=max(dp[i][0],dp[i][1]);
			dp1+=dp[i][0];
		}
	dp[root][0]=dp0;
	dp[root][1]=dp1+1;
	return ;
}

bool unique(int root){
	int i,tmp_flag;
	if(flag!=1){
		if(dp[root][0]==dp[root][1]) return 0;
		else if(dp[root][0]>dp[root][1]) flag=0;
		else flag=1;
	}
	else flag=0;
	for(i=1;i<n;++i){
	  if(r[i]==root){
		  tmp_flag=flag;
		  if(!unique(i)) return 0;
		  else flag=tmp_flag;
	  }
	}
	return 1;
}

int main(){
	int ans,i;
	while(scanf("%d",&n)&&n){
		memset(dp,0,sizeof(dp));
		scanf("%s",name1[0]);
		for(i=1;i<n;++i)
			scanf("%s%s",name1[i],name2[i]);
		for(i=1;i<n;++i)
			r[check(name1[i])]=check(name2[i]);
		DP(0);
		ans=max(dp[0][0],dp[0][1]);
		flag=-1;
		if(unique(0)) printf("%d Yes\n",ans);
		else printf("%d No\n",ans);
	}
	return 0;
}

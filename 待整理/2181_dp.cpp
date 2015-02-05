#include<cstdio>
#include<iostream>
using namespace std;
#define N 150005
int dp[N][2],s[N];
int main(){
	int p;
	int i;
	scanf("%d",&p);
	for(i=0;i<p;++i){
		scanf("%d",&s[i]);
	}
	dp[0][0]=s[0];
	dp[0][1]=0;
	for(i=1;i<p;++i){
		dp[i][0]=max(dp[i-1][1]+s[i],dp[i-1][0]);
		dp[i][1]=max(dp[i-1][0]-s[i],dp[i-1][1]);
	}
	printf("%d\n",max(dp[p-1][0],dp[p-1][1]));
	return 0;
}

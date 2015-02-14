/*cf 509F Progress Monitoring
  题意：
  used[1 ... n] = {0, ..., 0};

  procedure dfs(v):
	print v;
	used[v] = 1;
	for i = 1, 2, ..., n:
		if (a[v][i] == 1 and used[i] == 0):
			dfs(i);

  dfs(1);
  给出一个深搜序, 求符合这个深搜序的树有多少种。
  限制：
  1 <= n <= 500
  思路：
  分治
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=505;
const int MOD=1e9+7;
LL dp[N][N];
int a[N];
LL gao(int l,int r){
	if(l==r){
		//cout<<l<<' '<<r<<' '<<dp[l][r]<<endl;
		return dp[l][r]=1;
	}
	if(dp[l][r]>=0) return dp[l][r];
	dp[l][r]=gao(l+1,r);
	for(int i=r-1;i>=l+1;--i){
		if(a[l+1]<a[i+1])
			dp[l][r]=(dp[l][r]+gao(l+1,i)*gao(i,r))%MOD;
	}
	//cout<<l<<' '<<r<<' '<<dp[l][r]<<endl;
	return dp[l][r];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	memset(dp,-1,sizeof(dp));
	printf("%I64d\n",gao(1,n));
	return 0;
}

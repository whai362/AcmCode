/*poj1221
  题意：
  整数拆分，对称拆分
  例如：4: (4), (1 2 1), (2 2), (1 1 1 1) 
  对于一个整数n，求拆分的种类数。
  限制：
  0 <= n < 250
  思路：
  由于数据较小，可以考虑 n^2 乃至 n^3 的dp
  令dp[i][j]表示拆分整数 i 时，最大的数小于 j 的方法有多少种。
  不难得出：
  dp[i][j]=dp[i][j-1] + dp[i-j][min(j,i-j)];
  一个 n^2 的dp。
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=250;
LL dp[N][N];
void predo(){
	dp[0][0]=dp[1][1]=1;
	for(int i=2;i<N;++i){
		for(int j=1;j<=i;++j){
			dp[i][j]=dp[i][j-1]+dp[i-j][min(j,i-j)];
		}
	}
}
int n;
void gao(){
	LL ans=0;
	if(n&1){
		for(int i=1;i<=n;i+=2){
			int m=(n-i)/2;
			ans+=dp[m][min(i,m)];
		}
	}
	else{
		ans+=dp[n/2][n/2];
		for(int i=2;i<=n;i+=2){
			int m=(n-i)/2;
			ans+=dp[m][min(i,m)];
		}
	}
	printf("%d %I64d\n",n,ans);
}
int main(){
	predo();
	while(scanf("%d",&n) && n){
		gao();
	}
	return 0;
}

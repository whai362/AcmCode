/*hdu1028
  题意：整数拆分，例如4的情况
  4 = 4;
  4 = 3 + 1;
  4 = 2 + 2;
  4 = 2 + 1 + 1;
  4 = 1 + 1 + 1 + 1;
  限制：1 <= n <= 120
  思路：dp
  dp[i][j]表示数字i，拆成以j为结尾的方式有多少种
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
LL dp[205][205];
LL ans[205];
int main(){
	dp[1][1]=1;
	for(int i=2;i<=120;++i){
		for(int j=1;j<=i;++j){
			for(int k=j;k<=i-j;++k){
				dp[i][j]+=dp[i-j][k];
			}
		}
		dp[i][i]=1;
	}
	for(int i=1;i<=120;++i)
		for(int j=1;j<=i;++j)
			ans[i]+=dp[i][j];
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%I64d\n",ans[n]);
	}
	return 0;

}


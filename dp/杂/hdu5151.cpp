/*bc24b
  题意：在一个XX大学中有N张椅子排成一排，椅子上都没有人，每张椅子都有颜色，分别为蓝色或者红色。 接下来依次来了N个学生，标号依次为1,2,3,...,N。 对于每个学生，他会找一张还没有人坐的椅子坐下来。但是如果这张椅子满足以下三个条件他就不会去坐。
  1. 这张椅子左右两边都有相邻的椅子
  2. 这张椅子左右两边相邻的椅子都不是空的，也就是有人坐下了
  3. 这张椅子左右两边相邻的椅子的颜色不同
  如果当前的学生找不到椅子坐下，那他就会走掉。
  对于当前的某个学生，他可能有很多种椅子的选择来坐。你的任务是计算有多少种不同的全部的学生都坐下来的情况。结果可能很大，输出答案对1000000007(109+7) 取模。
  限制：1 <= N <= 100
  思路：
  设dp[0][i][j]表示前i个位置已经确定了被坐的相对次序的合法情况数，并且第i个位置为当中第j个被坐的，第i个位置在第i-1个位置之后被坐。
  同理dp[1][i][j]表示前i个位置已经确定了被坐的相对次序的合法情况数，并且第i个位置为当中第j个被坐的，第i个位置在第i-1个位置之前被坐。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=105;
const LL MOD=1000000007;
int a[N];
LL dp[2][N][N];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		dp[0][1][1]=1;
		dp[1][1][1]=0;
		dp[0][2][1]=0;
		dp[0][2][2]=1;
		dp[1][2][1]=1;
		dp[1][2][2]=0;
		for(int i=3;i<=n;++i){
			LL s=0;
			for(int j=1;j<=i;++j){
				dp[0][i][j]=s;
				s=(s+dp[0][i-1][j]+dp[1][i-1][j])%MOD;
			}
			s=0;
			for(int j=i;j>=1;--j){
				dp[1][i][j]=s;
				s=(s+dp[1][i-1][j-1])%MOD;
			}
			if(a[i]==a[i-2]){
				s=0;
				for(int j=i;j>=1;--j){
					dp[1][i][j]=(dp[1][i][j]+s)%MOD;
					s=(s+dp[0][i-1][j-1])%MOD;
				}
			}
		}
		LL ans=0;
		for(int i=1;i<=n;++i){
			ans=(ans+dp[0][n][i]+dp[1][n][i])%MOD;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

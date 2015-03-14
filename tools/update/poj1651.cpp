/*poj 1651
  题意：
  给出n个整数a1,a2,...,an，要求从中取出中间的n-2个数(两端的数不能取)，取出每个数的代价为它两边的数和它的乘积，问取出这n-2个数的最小代价为多少？
  限制：
  3 <= n <= 100; 1 <= ai <= 100
  思路：
  dp 记忆化搜索
  对于每个过程其实就是，枚举最后取的数a[i]，然后把区间[l,r]分割成[l,i]和[i,r]两部分。
  dp[l][r]=min(gao(l,i)+a[left]*a[i]*a[right]+gao(i,r))
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=105;
const int INF=0x3f3f3f3f;
int a[N];
LL dp[N][N];
int gao(int l,int r){
	if(dp[l][r]!=-1) return dp[l][r];
	int ret=INF;
	if(l+1==r) return dp[l][r]=0;
	for(int i=l+1;i<r;++i)
		ret=min(ret,gao(l,i)+gao(i,r)+a[l]*a[i]*a[r]);
	//cout<<l<<' '<<r<<' '<<ret<<endl;
	return dp[l][r]=ret;
}
int main(){
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	printf("%d\n",gao(0,n-1));
	return 0;
}

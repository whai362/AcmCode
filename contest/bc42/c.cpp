/*hdu 5234 Happy birthday
  题意：
  今天是Gorwin的生日。所以她的妈妈要实现她的一个愿望。Gorwin说她想吃很多蛋糕。所以他妈妈带她来到了蛋糕园。
  这个园子被分成了n*m个方格子。在每一个格子里面，有一个蛋糕。第i行，第j列的格子中有一个重量为w[i][j]千克的蛋糕，Gorwin从左上角(1,1)的格子开始走，走到右下角(n,m)的格子。在每一步中，Gorwin可以向右或者向下走，即是：Gorwin站在(i,j)的时候，她可以走向(i+1,j)或者(i,j+1) (然而她不能走出这个花园)。
  当Gorwin到达一个格子的时候，她可以把那个格子里面的蛋糕吃完或者不吃。但是，她不能只吃一部分。她的胃不是那么大，所以她最多只能吃K千克的蛋糕。现在，Gorwin站在左上角，她在看蛋糕园的地图，想要找出一条路，能够使得她吃到的蛋糕最多的一条路。请你来帮帮忙。
  限制：
  0 < n,m,k,w[i][j] <= 100
  思路：
  01背包
  处理好一维，二维就行了。
  复杂度O(n^3)
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
int a[N][N];
int dp[N][N][N];
void init(){
	memset(dp,0,sizeof(dp));
}
void gao(int n,int m,int v){
	for(int i=a[0][0];i<=v;++i){
		dp[0][0][i]=a[0][0];
	}
	for(int i=1;i<n;++i){
		for(int j=0;j<=v;++j){
			if(j<a[i][0])
				dp[i][0][j]=dp[i-1][0][j];
			else
				dp[i][0][j]=max(dp[i-1][0][j],dp[i-1][0][j-a[i][0]]+a[i][0]);
		}
	}
	for(int i=1;i<m;++i){
		for(int j=0;j<=v;++j){
			if(j<a[0][i])
				dp[0][i][j]=dp[0][i-1][j];
			else
				dp[0][i][j]=max(dp[0][i-1][j],dp[0][i-1][j-a[0][i]]+a[0][i]);
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			for(int k=0;k<=v;++k){
				if(k<a[i][j])
					dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k]);
				else
					dp[i][j][k]=max(max(dp[i-1][j][k],dp[i-1][j][k-a[i][j]]+a[i][j]),max(dp[i][j-1][k],dp[i][j-1][k-a[i][j]]+a[i][j]));
			}
		}
	}
	printf("%d\n",dp[n-1][m-1][v]);
}
int main(){
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		init();
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&a[i][j]);
		gao(n,m,k);
	}
	return 0;
}

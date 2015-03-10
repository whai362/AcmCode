/*hdu 5185
  题目：
  x[1]+x[2]+x[3]+...+x[n]=n, 这里 
  0 <= x[i] <= n && 1 <= i <= n
  x[i] <= x[i+1] <= x[i]+1 && 1 <= i <= n-1
  对于一个给定的n,Gorwin想要知道有多少xi的组合满足上述等式。由于结果比较大，输出答案对m取余的结果就行。
  限制：
  T组数据：1 <= T <=20
  1 <= n <= 50000
  1 <= m <= 1e9
  思路：
  类似背包的dp，只是稍微变一下而已。
  dp[i][j] 表示装满容量为i的背包，背包中体积最大的物品为j的方法数
  dp[i][j]=dp[i-j][j-1]+dp[i-j][j]

  需要注意的一点是由于题目限制，设最大的物品的体积为x，则有：
  (x+1)*x/2=n，所以x最大值小于sqrt(2*n)。
  所以每组数据时空复杂度都为O(50000*320)。
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL __int64
int MOD;
const int N=50005;
int dp[N][320];
void gao(int n,int m){
	MOD=m;
	int lim=sqrt(2*n);
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=min(i,lim);++j){
			dp[i][j]=((LL)dp[i-j][j-1]+dp[i-j][j])%MOD;
		}
	}
	//for(int i=0;i<=n;++i){
	//	for(int j=1;j<=lim;++j)
	//		cout<<dp[i][j]<<' ';
	//	cout<<endl;
	//}
	LL ans=0;
	for(int i=1;i<=lim;++i){
		ans=(ans+dp[n][i])%MOD;
	}
	printf("%I64d\n",ans);
}
int main(){
	int T,cas=0;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		printf("Case #%d: ",++cas);
		gao(n,m);
	}
	return 0;
}

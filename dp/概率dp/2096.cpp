/*
   题意：
   一个软件有s个子系统，会产生n种bug。 某人一天发现一个bug，这个bug属于某种bug，发生在某个子系统中。求找到所有的n种bug，且每个子系统都找到bug，这样所要的天数的期望。需要注意的是：bug的数量是无穷大的，所以发现一个bug，出现在某个子系统的概率是1/s，属于某种类型的概率是1/n。
   题解：
   dp[i][j]=dp[i][j]*i/n*j/m + dp[i+1][j]*(n-i)/n*j/m + dp[i][j+1]*i/n*(m-j)/m+dp[i+1][j+1]*(n-i)/n*(m-j)/m
   化简即可。
 */
#include<cstdio>
#include<iostream>
#include<iomanip>
using namespace std;
const int N=1005;
double dp[N][N];
int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	dp[n][s]=0;
	for(int i=n;i>=0;--i){
		for(int j=s;j>=0;--j){
			if(i!=n || j!=s)
				dp[i][j]=(dp[i+1][j]*(n-i)*j+dp[i][j+1]*i*(s-j)+dp[i+1][j+1]*(n-i)*(s-j)+n*s)/(n*s-i*j);
		}
	}
	cout<<fixed<<setprecision(4)<<dp[0][0]<<endl;
	return 0;
}

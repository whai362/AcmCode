/*poj 2411
  题目意思：给一个n*m的矩形区域，将1*2和2*1的小矩形填满方格，问一共有多少种填法。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
int n,m;
LL dp[12*12][1<<12];
int main(){
	while(scanf("%d%d",&n,&m) && (n||m)){
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		int cur,next;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cur=i*m+j,next=i*m+j+1;
				for(int k=0;k<(1<<m);++k){
					// 如果已经放了，那就直接转移
					if((k>>j) & 1){
						dp[next][k &~ (1<<j)] += dp[cur][k];
					}
					else{
						//　尝试横放
						if(j+1<m && !(k>>(j+1) & 1)){
							dp[next][k | 1<<(j+1)]+=dp[cur][k];
						}
						// 尝试竖放
						if(i+1<n){
							dp[next][k | 1<<j]+=dp[cur][k];
						}
					}
				}
			}
		}
		printf("%lld\n",dp[next][0]);
	}
	return 0;
}

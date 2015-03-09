/*hdu 5180
  表1：
  tab[a][b]表示a*b的棋盘王的放置情况的种数。
  由于只有15*15，所以可以用状态压缩dp来解决。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int MOD=1000000007;
LL dp[20][1<<16];
int a[1<<16],cnt;
int tab[20][20];
int main(){
	for(int i=1;i<=15;++i){
		cnt=0;
		for(int j=0;j<(1<<i);++j){
			if((j & (j<<1))==0)
				a[cnt++]=j;
		}
		memset(dp,0,sizeof(dp));
		for(int j=0;j<cnt;++j){
			dp[0][a[j]]=1;
		}
		tab[1][i]=cnt;
		for(int j=1;j<15;++j){
			LL sum=0;
			for(int k=0;k<cnt;++k){
				for(int l=0;l<cnt;++l){
					if((a[k] & a[l]) || (a[k] & (a[l]<<1)) || (a[k] & (a[l]>>1))) continue;

					dp[j][a[k]]=(dp[j][a[k]]+dp[j-1][a[l]])%MOD;
				}
				sum=(sum+dp[j][a[k]])%MOD;
			}
			tab[j+1][i]=sum;
		}
	}
	for(int i=0;i<=15;++i){
		for(int j=0;j<=15;++j)
			cout<<tab[i][j]<<',';
		cout<<endl;
	}
	return 0;
}


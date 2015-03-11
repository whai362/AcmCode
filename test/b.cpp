#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=1e5+5;
const int MOD=100000007;
char str[N];
LL dp[N][10][3];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		scanf("%s",str);
		int len=strlen(str);
		LL ans=0;
		for(int i=1;i<10;++i){
			if(i<str[0]-'0') dp[0][i][0]=1;
			else if(i==str[0]-'0') dp[0][i][1]=1;
			else dp[0][i][2]=1;
			//cout<<dp[0][i][0]<<' '<<dp[0][i][1]<<endl;
			ans+=dp[0][i][0]+dp[0][i][1];
			//cout<<ans<<endl;
			if(len!=1) ans+=dp[0][i][2];
		}
		for(int i=1;i<len;++i){
			for(int j=1;j<10;++j){
				for(int k=1;k<=j;++k){
					if(j%k!=0) continue;
					dp[i][j][0]=(dp[i][j][0]+dp[i-1][k][0])%MOD;
					if(j<str[i]-'0') dp[i][j][0]=(dp[i][j][0]+dp[i-1][k][1])%MOD;
					if(j==str[i]-'0') dp[i][j][1]=(dp[i][j][1]+dp[i-1][k][1])%MOD;
					dp[i][j][2]=(dp[i][j][2]+dp[i-1][k][2])%MOD;
					if(j>str[i]-'0') dp[i][j][2]=(dp[i][j][2]+dp[i-1][k][1])%MOD;
				}
				ans=(ans+dp[i][j][0]+dp[i][j][1])%MOD;
				if(i!=len-1) ans=(ans+dp[i][j][2])%MOD;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

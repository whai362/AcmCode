#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005,
	  MOD=1000000007;
#define LL __int64
LL dp[N],sum[N],ss[N];
char s[N],t[N];
bool cmp(int b,int e){
	for(int i=b;i<=e;++i){
		if(s[i]!=t[i-b]) return false;
	}
	return true;
}
int main(){
	scanf("%s%s",s,t);
	int S=strlen(s);
	int T=strlen(t);
	for(int i=0;i<S;++i){
		if(i<T-1){
			if(i==0)
				dp[i]=0;
			else
				dp[i]=dp[i-1];
		}
		else{
			if(cmp(i-T+1,i)){
				if(i==0 || i==T-1)
					dp[i]=i-T+2;
				else
					dp[i]=ss[i-T]+i-T+2;
			}
			else{
				if(i==0)
					dp[i]=0;
				else
					dp[i]=dp[i-1];
			}
		}
		if(i==0){
			sum[i]=dp[i];
			ss[i]=dp[i];
		}
		else{
			sum[i]=(sum[i-1]+dp[i])%MOD;
			ss[i]=(ss[i-1]+sum[i])%MOD;
		}
		//cout<<dp[i]<<' '<<sum[i]<<' '<<ss[i]<<endl;
	}
	printf("%I64d\n",sum[S-1]);
	return 0;
}

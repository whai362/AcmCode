#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
const int MOD=100007;
const int N=1005;
char str[N];
LL dp[N];
void gao(){
	int len=strlen(str);
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<len;++i){
		LL sum=0,pre=0;
		for(int j=i-1;j>=0;--j){
			sum=(sum+dp[j])%MOD;
			if(str[j]==str[i]){
				dp[j]=(dp[j]+pre+1)%MOD;
			}
			pre=sum;
		}
		dp[i]=1;
		//for(int j=0;j<=i;++j){
		//	cout<<dp[j]<<' ';
		//}
		//cout<<endl;
	}
	LL ans=0;
	for(int i=0;i<len;++i){
		ans=(ans+dp[i])%MOD;
	}
	printf("%d\n",(int)ans);
}
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		scanf("%s",str);
		printf("Case #%d: ",++cas);
		gao();
	}
	return 0;
}

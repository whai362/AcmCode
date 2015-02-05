#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=1505;
LL n,x,y,z,t,
   ans,
   dp[N][N];
void init(){
	ans=0;
	memset(dp,0,sizeof(dp));
}
LL cal(int n1,int n2){
	LL dam=n1*y,
	   tim=t+n2*z;
	ans=max(ans,dp[n1][n2]+(n-n1-n2)*tim*(x+dam));
}
int main(){
	int cas=0,T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%I64d %I64d %I64d %I64d %I64d",&n,&x,&y,&z,&t);
		dp[0][0]=0;
		cal(0,0);
		dp[1][0]=0;
		cal(1,0);
		dp[0][1]=0;
		cal(0,1);
		LL dam,tim;
		for(int i=1;i<=n;++i){
			dp[i][0]=dp[i-1][0]+(i-1)*y * t;
			cal(i,0);
		}
		for(int i=1;i<=n;++i){
			dp[0][i]=dp[0][i-1];
			cal(0,i);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j+i<=n;++j){
				dp[i][j]=max(dp[i-1][j]+ (i-1)*y * (j*z+t) ,
						dp[i][j-1]+ i*y * ((j-1)*z+t));
				cal(i,j);
			}
		}
		printf("Case #%d: %I64d\n",++cas,ans);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const LL INF=10000000000LL;
const int N=205;
int a[N];
int b[N];
LL dp[N][N];
LL gao(int L,int R){
	LL ret=INF;
	if(L+1>R-1) return 0;
	if(dp[L][R]!=-1) return dp[L][R];
	//if(L+1==R-1) return dp[L][R]=a[L+1]+b[L]+b[R];
	for(int i=L+1;i<=R-1;++i){
		LL tmp=a[i];
		tmp+=b[L];
		tmp+=b[R];
		tmp+=gao(L,i)+gao(i,R);
		ret=min(ret,tmp);
	}
	return dp[L][R]=ret;
}
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n;
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		a[0]=a[n+1]=0;
		for(int i=1;i<=n;++i)
			scanf("%d",&b[i]);
		b[0]=b[n+1]=0;
		printf("Case #%d: %d\n",++cas,gao(0,n+1));
	}
	return 0;
}

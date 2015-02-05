#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int MOD=1000000007;
int dp[55][55][2505];
void Egcd(LL a,LL b,LL &x,LL &y){	//扩展欧几里德
	if(b==0){
		x=1;
		y=0;
		return ;  
	}
	Egcd(b,a%b,x,y);  
	LL tmp=x;
	x=y;
	y=tmp-a/b*y;  
}
int main(){
	int n,m;
	//for(n=0;n<=50;++n){
	//	for(m=0;m<=50;++m){
	while(scanf("%d%d",&n,&m)!=EOF){
			//cin>>n>>m;
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					if(i==1 && j==1){
						dp[1][1][1]=n*m;
						continue;
					}
					for(int k=max(i,j);k<=i*j;++k){
						LL tmp=((LL)dp[i-1][j-1][k-1]*(n-i+1)*(m-j+1)%MOD + 
								(LL)dp[i-1][j][k-1]*(n-i+1)*j%MOD + 
								(LL)dp[i][j-1][k-1]*i*(m-j+1)%MOD + 
								(LL)dp[i][j][k-1]*(i*j-k+1))%MOD;
						LL x,y;
						Egcd(k,MOD,x,y);
						dp[i][j][k]=tmp*(x%MOD+MOD)%MOD;
					}
				}
			}
			LL ans=0;
			for(int i=0;i<=n*m;++i){
				ans=(ans+dp[n][m][i])%MOD;
			}
			//cerr<<n<<' '<<m<<endl;
			printf("%I64d\n",ans);
	//	}
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef __int64 LL;
const int N=55,M=10005,mod=1e9+7;
LL c[N][N],dp[N][N],bt[N];
void read(int &x){
    #define CH getchar()
    char ch;x=0;for(ch=CH;ch<'0'||ch>'9';ch=CH) ;
    for(;ch>='0'&&ch<='9';x=x*10+ch-48,ch=CH);
}    
int main(){
    int hd,tl,i,j,n,T,x,y,k,s,t,l,r,m;
    LL ans;
    for(bt[0]=i=1;i<51;i++) bt[i]=bt[i-1]*2%mod;
    for(c[0][0]=i=1;i<51;i++)
        for(c[i][0]=j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    n=m=51;
    for(i=1;i<n;i++) dp[i][1]=dp[1][i]=1;
    for(i=2;i<n;i++){
        for(j=2;j<m;j++){
            dp[i][j]=dp[i][j-1]*(bt[i]-1)%mod;
            for(k=1;k<i;k++)
                dp[i][j]=(dp[i][j]+(dp[i-k][j-1]*bt[i-k]%mod*c[i][i-k]%mod))%mod;
        }
    }
    while(~scanf("%d%d",&n,&m)){
        printf("%I64d\n",dp[n][m]);
    }
    return 0;
}

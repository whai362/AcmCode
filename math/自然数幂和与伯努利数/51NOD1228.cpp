/*51NOD 1228
  题意：
  S(k,n)=1^k+2^k+...+n^k
  求自然数幂和对1e9+7取模。
  限制：
  1<= n <= 10^18; 1 <= k <= 2000
  思路：
  伯努利数
  S(k,n)=S(k,n)=1/(k+1) * ( C(k+1,k)*B[k]*(n+1)^1 + C(k+1,k-1)*B[k-1]*(n+1)^2 + ... + C(k+1,0)*B[0]*(n+1)^(k+1) )	(B[i]为伯努利数)
  而B[n]有：
  B[n]=-1/(n+1) * ( C(n+1,0)*B[0] + C(n+1,1)*B[1] + ... + C(n+1,n-1)*B[n-1] )
  所以B[0]...B[k]可以O(k^2)预处理出来，然后对于每个S(k,n)可以O(k)算出来。
   */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int MOD=1000000007;
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= Ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

LL Inv(LL a,int m){   //求逆元
    LL d,x,y,t= (LL)m;
    d= Ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

const int N=2005;

LL B[N],C[N][N];

void init(){
	for(int i=0;i<N;++i)
		C[i][0]=C[i][i]=1;
	for(int i=2;i<N;++i)
		for(int j=1;j<N;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	B[0]=1;
	for(int i=1;i<N;++i){
		LL tmp=0;
		for(int j=0;j<i;++j)
			tmp=(tmp+C[i+1][j]*B[j])%MOD;
		B[i]=(tmp*-(Inv(i+1,MOD))%MOD+MOD)%MOD;
	}
}

LL p[N];

void gao(LL n,LL k){
	p[0]=1;
	for(int i=1;i<=k+1;++i)
		p[i]=(p[i-1]*((n+1)%MOD))%MOD;
	LL ans=0;
	for(int i=0;i<=k;++i)
		ans=(ans+C[k+1][i]*B[i]%MOD*p[k+1-i])%MOD;
	ans=(ans*Inv(k+1,MOD)%MOD+MOD)%MOD;
	printf("%I64d\n",ans);
}

int main(){
	init();
	int T;
	LL n,k;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&k);
		gao(n,k);
	}
	return 0;
}

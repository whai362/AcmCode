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

LL Inv(LL a,int m){   //ÇóÄæÔª
    LL d,x,y,t= (LL)m;
    d= Ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

const int N=50005;

LL B[N],C[N];

void init(){
	B[0]=1;
	C[0]=1;
	for(int i=1;i<N;++i){
		LL tmp=0;
		for(int j=0;j<i;++j){
			if(j)
				C[j]=(C[j-1]*(i+1-(j-1))%MOD*Inv(j,MOD)%MOD+MOD)%MOD;
			tmp=(tmp+C[j]*B[j])%MOD;
		}
		B[i]=(tmp*-(Inv(i+1,MOD))%MOD+MOD)%MOD;
		cerr<<i<<endl;
		printf("%I64d,",B[i]);
	}
}

//LL p[N];
//
//void gao(LL n,LL k){
//	p[0]=1;
//	for(int i=1;i<=k+1;++i)
//		p[i]=(p[i-1]*((n+1)%MOD))%MOD;
//	LL ans=0;
//	for(int i=0;i<=k;++i)
//		ans=(ans+C[k+1][i]*B[i]%MOD*p[k+1-i])%MOD;
//	ans=(ans*Inv(k+1,MOD)%MOD+MOD)%MOD;
//	printf("%I64d\n",ans);
//}

int main(){
	init();
	//for(int i=0;i<20;++i){
	//	cout<<B[i]<<endl;
	//}
	//int T;
	//LL n,k;
	//scanf("%d",&T);
	//while(T--){
	//	scanf("%I64d%I64d",&n,&k);
	//	gao(n,k);
	//}
	return 0;
}

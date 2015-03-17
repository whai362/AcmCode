#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
LL mul(LL a,LL b,LL m){
    LL ret = 0;
    a %= m;
    while(b){
        if(b & 1) ret = (ret + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return ret;
}
//LL a_b_MOD_c(LL a,LL b,LL mod){
//	LL ret = 1;
//	a %= mod;
//	while(b){
//		if(b & 1) ret = ret * a % mod;
//		a = a * a % mod;
//		b >>= 1;
//	}
//	return ret;
//}

LL a_b_MOD_c(LL a,LL b,LL m){
    LL ret = 1;
    a %= m;
    while(b){
        if(b&1) ret = mul(ret,a,m);
        a = mul(a,a,m);
        b >>= 1;
    }
    return ret;
}
double a=2*1e18;
int main(){
	LL n,p;
	//cout<<(LL)(a)<<endl;
	while(scanf("%I64d%I64d",&n,&p)!=EOF){
		if(n==1){
			printf("%I64d\n",1%p);
			continue;
		}
		LL ans=(a_b_MOD_c(2,n,p)-2+p)%p;
		printf("%I64d\n",ans);
	}
	return 0;
}

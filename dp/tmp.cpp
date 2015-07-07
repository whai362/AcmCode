#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int MOD=1000000007;
const int N=50005;
int f[N],cnt[N],tot;
LL a_b_MOD_c(LL a,LL b,LL mod){
	LL ret = 1;
	a %= mod;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
//等比数列求和
//留意a=0的情况
LL dbsum(LL a,LL b,LL mod){
	if(b==0)
		return 1;
	if(b&1)
		return (a_b_MOD_c(a,(b+1)/2,MOD)+1)*dbsum(a,b/2,MOD)%MOD;
	else
		return ((a_b_MOD_c(a,b/2,MOD)+1)*dbsum(a,(b-1)/2,MOD)%MOD + a_b_MOD_c(a,b,MOD))%MOD;
}
void gao(int n,int m){
	//if(n==0){ puts("0"); return ; }
	tot=0;
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			f[tot]=i;
			cnt[tot]=0;
			while(n%i==0){
				++cnt[tot];
				n/=i;
			}
			++tot;
		}
	}
	if(n>1){
		f[tot]=n;
		cnt[tot]=1;
		++tot;
	}
	for(int i=0;i<tot;++i){
		cnt[i]*=m;
	}
	LL ans=1;
	for(int i=0;i<tot;++i){
		//cout<<f[i]<<' '<<cnt[i]/23<<endl;
		//cout<<dbsum(i)<<endl;
		ans=ans*dbsum(f[i],cnt[i],MOD)%MOD;
	}
	printf("%lld\n",ans);
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		gao(n,m);
	}
	return 0;
}

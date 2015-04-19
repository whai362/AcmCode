#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define LL long long
const int MOD=998244353;
const int N=2*1e6+5;
int cnt[N];
int n,k;
int lim;
int mu[N];
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

//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}
void cai(int x){
	int lim=sqrt(x);
	for(int i=1;i<=lim;++i){
		if(x%i==0){
			++cnt[i];
			if(x/i!=i) ++cnt[x/i];
		}
	}
}
LL f(int x){
	LL ret=0;
	for(int i=0;i*x<=lim;++i){
		ret=(ret+mu[i]*cnt[i*x]%MOD+MOD)%MOD;
	}
	return ret;
}
void gao(){
	LL ans=0;
	for(int i=1;i<=lim;++i){
		ans=(ans+f(i)*a_b_MOD_c(i,k,MOD)%MOD)%MOD;
	}
	printf("%lld\n",ans);
}
void predo(){
	for(int i=1;i<=lim;++i){
		cnt[i]=(a_b_MOD_c(2,cnt[i],MOD)-1+MOD)%MOD;
	}
}
int main(){
	int T;
	getMu();
	scanf("%d",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		lim=0;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;++i){
			int a;
			scanf("%d",&a);
			lim=max(lim,a);
			cai(a);
		}
		predo();
		//for(int i=1;i<=lim;++i){
		//	cout<<cnt[i]<<' ';
		//}
		//cout<<endl;
		gao();
	}
	return 0;
}

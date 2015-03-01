#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int N=1e5+5;
int mu[N];
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
int sum[N];
LL gao(int n,int m){
	LL ret=0;
	if(n>m) swap(n,m);
	for(int i=1,last=0;i<=n;i=last+1){
		last=min(n/(n/i),m/(m/i));
		ret+=(LL)(sum[last]-sum[i-1])*(n/i)*(m/i);
	}
	return ret;
}
void predo(){
	sum[0]=0;
	for(int i=1;i<N;++i)
		sum[i]=sum[i-1]+mu[i];
}
int main(){
	getMu();
	predo();
	int T;
	int a,b,c,d,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		LL ans=gao(b/k,d/k)-gao((a-1)/k,d/k)-gao(b/k,(c-1)/k)+gao((a-1)/k,(c-1)/k);
		printf("%lld\n",ans);
	}
	return 0;
}

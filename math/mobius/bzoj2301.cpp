/*bzoj 2301
  题意：
  给出a,b,c,d, 求符合条件a <= x <= b && c <= y <= d && gcd(x,y)=k 的数对(x,y)的数目。
  限制：
  1 <= n,a,b,c,d,k <= 5*10^5
  思路：
  这道题可以化为：求 1 <= x <= t1 && 1 <= y <= t2 && gcd(x,y)=k 的数对(x,y)的数目。
  这个问题可以用莫比乌斯反演解决。
  设f(k)为gcd(x,y)=k的数对(x,y)的数目，
  设F(k)为gcd(x,y)为k的倍数的数对(x,y)的数目，显然F(k)=floor(t1/k)*floor(t2/k)，由于这道题case数比较多，所以暴力会超时，所以要通过分段来解决这个问题，复杂度为O(sqrt(n))。
 */
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

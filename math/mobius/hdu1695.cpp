/*hdu 1695
  题意：
  给出a,b,c,d,k, 求满足a <= x <= b && c <= y <= d && gcd(x,y)=k 的数对(x,y)的对数。
  限制：
  a=c=1; 0 < b,c <= 1e5; (n1,n2) 和 (n2,n1) 算为同种情况
  思路：
  其实是求满足1 <= x <= b/k && 1 <= y <= d/k && gcd(x,y)=1 的 数对(x,y)的对数。
  莫比乌斯反演入门题
  设f(k)为gcd(x,y)=k的数对(x,y)的对数，我们要求的是f(1)
  设F(k)为gcd(x,y)为k的倍数的数对(x,y)的对数，可以想到F(k)=floor(b/k)*floor(d/k)，
  由莫比乌斯反演得：
  令lim=min(b/k,d/k)
  f(1)=mu[1]*F(1) + mu[2]*F[2] + ... + mu[lim]*F(lim)
  因为(n1,n2)和(n2,n1)算为同一种情况，所以最后结果还要减掉重复的情况。
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
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

int main(){
	int T,cas=0;
	int a,b,c,d,k;
	getMu();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("Case %d: ",++cas);
		if(k==0){
			puts("0");
			continue;
		}
		b/=k;
		d/=k;
		if(b>d) swap(b,d);
		LL ans1=0;
		for(int i=1;i<=b;++i)
			ans1+=(LL)mu[i]*(b/i)*(d/i);
		LL ans2=0;
		for(int i=1;i<=b;++i)
			ans2+=(LL)mu[i]*(b/i)*(b/i);
		ans1-=ans2/2;
		printf("%I64d\n",ans1);
	}
	return 0;
}

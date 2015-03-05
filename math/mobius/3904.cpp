/*poj 3904
  题目：
  给出n个数字a1,a2,...an, 求从中选出一个四元组(a,b,c,d), 使得gcd(a,b,c,d)=1，求符合条件的四元组的数目。
  限制：
  1 <= n <= 1e4; 1 <= ai <= 1e4
  思路：
  莫比乌斯反演入门题
  设f(k)为gcd(a,b,c,d)=k的四元组的数目，
  设F(k)为gcd(a,b,c,d)为k的倍数的四元组的数目，
  F(k)可以通过这个方式得到：
  先通过对每个ai分解因数预处理处理出来，对于每个k，有多少个ai是它的倍数，假设为m，然后F(k)=C(m,4)。
  令lim=max(a1,a2,...,an)
  最后f(1)=mu[1]*F(1) + mu[2]*F(2) + ... + mu[lim]*F(lim)
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define LL __int64
const int N=100005;
int cnt[N];
int mu[N];
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}
LL C(int n,int m){
	if(n<m) return 0;
	LL ret=1;
	for(int i=n;i>n-m;--i)
		ret*=(LL)i;
	for(int i=2;i<=m;++i)
		ret/=i;
	return ret;
}
LL gao(int x,int c){
	LL ret=C(c,4);
	return mu[x]*ret;
}
int main(){
	getMu();
	int n,a,_max;
	while(scanf("%d",&n)!=EOF){
		_max=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			_max=max(_max,a);
			++cnt[a];
			int lim=sqrt(a);
			for(int j=2;j<=lim;++j){
				if(a%j==0){
					++cnt[j];
					if(a/j!=j) ++cnt[a/j];
				}
			}
		}
		LL ans=C(n,4);
		for(int i=2;i<=_max;++i){
			if(cnt[i]>=4)
				ans+=gao(i,cnt[i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

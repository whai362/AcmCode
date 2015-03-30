/*spoj 4491
  题意：
  给出a,b，求gcd(x,y)=prime的方案数，其中：1 <= x <= a && 1 <= y <= b
  限制：
  1 <= a,b <= 1e7
  思路：
  先把问题拆成一个一个来考虑，然后问题就变成gcd(x,y)=k的方案数。
  设f(k)为gcd(x,y)=k的方案数，
  设F(k)为gcd(x,y)为k的倍数的方案数，显然F(k)=floor(a/k)*floor(b/k)。
  由莫比乌斯反演得：
  f(k)=mu[1]*F[k]+mu[2]*F[2*k]+...
  所以：
  ans=f(prime[1])+f(prime[2])+...	---1式

  把"1式"展开后发现，对于每个F(k)，和它相乘的莫比乌斯系数有：mu[i]，其中i<k && k%i=0 && k/i=prime。
  令cnt[k]=sigma(mu[i])，其中i<k && k%i=0 && k/i=prime。
  现在要预处理出cnt[]，暴力预处理会超时，所以要利用莫比乌斯函数的性质，
  有三种情况：
  1. cnt[k]=1 其中k为质数
  2. cnt[i*prime]=-cnt[i]+mu[i] 其中i%prime!=0
  3. cnt[i*prime]=mu[i] 其中i%prime=0

  解释下第2点：
  不妨设i由且仅由奇数个不同的prime组成，因为i%prime!=0，所以i*prime由偶数个prime组成，所以cnt[i]里面的组合都因为多了一个不同质数prime而变成了自己的相反数，然后加上mu[i]。
  如：
  cnt[6]=mu[2]+mu[3]
  cnt[30]=cnt[6*5]=mu[10]+mu[15]+mu[6]=mu[2*5]+mu[3*5]+mu[6]=(-mu[2])+(-mu[3])+mu[6]

  对于第3点：
  因为i%prime==0，所以i中已经含有prime，所以i*prime里面含有两个prime，所以cnt[i]中的组合都因为多了一个相同的质数然后变成0，所以最后cnt[i]=mu[i]。
  如：
  cnt[6]=mu[2]+mu[3]
  cnt[18]=mu[6*3]=mu[6]+mu[9]=mu[6]+mu[3*3]=mu[6]+0

  最后，剩下的就只有分块的问题了。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
#define LL long long
const int N=1e7+5;
const int MOD=1000000007; 
int mu[N],pri[N],pcnt;
bool vis[N];
int cnt[N];
void getMu(){
	memset(vis,0,sizeof(vis));
	mu[1]=1;
	pcnt=0;
	for(int i=2;i<N;++i){
		if(!vis[i]){
			pri[pcnt++]=i;
			mu[i]=-1;
			//cnt[i]=1;
		}
		for(int j=0;j<pcnt && i*pri[j]<N;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]){
			   mu[i*pri[j]]=-mu[i];
			   //cnt[i*pri[j]]=-cnt[i]+mu[i];
			}
			else{
				mu[i*pri[j]]=0;
				//cnt[i*pri[j]]=mu[i];
				break;
			}
		}
	}
}
LL sum[N];
//0 1 1 -1 1 -2 1 0 -1 -2
void predo(){
	for(int i=2;i<N;++i){
		if(!vis[i]) cnt[i]=1;
		for(int j=0;j<pcnt && pri[j]<=i && i*pri[j]<N;++j){
			if(i%pri[j]) cnt[i*pri[j]]=-cnt[i]+mu[i];
			else{ cnt[i*pri[j]]=mu[i]; break; }
		}
	}
	//for(int i=0;i<pcnt;++i){
	//	int lim=N/pri[i];
	//	for(int j=1;j<lim;++j){
	//		cnt[j*pri[i]]+=mu[j];
	//	}
	//}
	for(int i=1;i<=N;++i)
		sum[i]=sum[i-1]+cnt[i];
}
int main(){
	getMu();
	predo();
	int T;
	int a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		LL ans=0;
		for(int i=1,ls=0;i<=min(a,b);i=ls+1){	//分块
			ls=min(a/(a/i),b/(b/i));
			ans+=((LL)sum[ls]-sum[i-1])*(a/i)*(b/i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

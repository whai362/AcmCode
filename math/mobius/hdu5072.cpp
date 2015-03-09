/*hdu 5072
  题意：
  给出n个数a1,a2,...,an, 从中选出三个数a,b,c,且这三个数符合[(a,b)=(b,c)=(a,c)=1] || [(a,b)!=1 && (b,c)!=1 && (a,c)!=1] 其中(x,y)表示x,y的最大公约数。求符合这个条件的三元组的个数。
  限制：
  3 <= n <= 1e5; 1 <= ai <= 1e5
  思路：
  设bi为与ai互质的数的个数，则符合条件 !(((a,b)=(b,c)=(a,c)=1) || ((a,b)!=1 && (b,c)!=1 && (a,c)!=1)) 的三元组的个数为：
  t=(sigma(1~n)bi*(n-1-bi))/2
  可以看到C(n,3)-t即为答案。
  下面证明上面式子的由来：
  对于任意符合条件的a,b,c有以下6种情况：
  1. (a,b)=1 && (a,c)!=1 && (b,c)=1
  2. (a,b)=1 && (a,c)!=1 && (b,c)!=1
  3. (a,b)!=1 && (a,c)=1 && (b,c)=1
  4. (a,b)!=1 && (a,c)=1 && (b,c)!=1
  5. (a,b)=1 && (a,c)=1 && (b,c)!=1
  6. (a,b)!=1 && (a,c)!=1 && (b,c)=1
  我们可以发现bi*(n-1-bi)只覆盖了上面的1~4的情况，但我们又发现剩下两种情况可以由b或c来覆盖
  其实对于1~6的情况，每种情况都被覆盖了两遍
  1. 被a,c覆盖
  2. 被a,b覆盖
  ...
  所以是所有的加起来/2

  然后问题就被化简为对于每个数，在复杂度内求和它互质的数的个数，这个可以用容斥做，也可以用莫比乌斯反演来做
  对于一个给定的数x0
  设f(k)为gcd(x0,x)=k的x的数目
  设F(k)为gcd(x0,x)为k的倍数的x的数目，然后发现F(k)为拥有因子k的ai的数目，这个可以用O(sqrt(ai))枚举因子预处理出来。
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
#define LL __int64
#define PB push_back
const int N=1e5+5;
vector<int> fac[N];
int tab[N];
int cnt[N];
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
void gao(int n){
	for(int i=0;i<n;++i){
		cnt[i]=n;
		if(fac[i][0]==1){ --cnt[i]; continue; }
		for(int j=0;j<fac[i].size();++j){
			//cout<<fac[i][j]<<' ';
			cnt[i]+=mu[fac[i][j]]*tab[fac[i][j]];
		}
		//cout<<endl;
	}
	LL ans=(LL)n*(n-1)*(n-2)/6,tmp=0;
	for(int i=0;i<n;++i){
		tmp+=(LL)cnt[i]*(n-1-cnt[i]);
	}
	ans=ans-tmp/2;
	printf("%I64d\n",ans);
	//for(int i=0;i<n;++i)
	//	cout<<cnt[i]<<' ';
	//cout<<endl;
}
void init(int n){
	memset(tab,0,sizeof(tab));
	for(int i=0;i<n;++i) fac[i].clear();
}
int main(){
	getMu();
	int T;
	int n,a;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init(n);
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			int lim=sqrt(a);
			++tab[a];
			fac[i].PB(a);
			for(int j=2;j<=lim;++j){
				if(a%j==0){
					int tmp=a/j;
					++tab[j];
					fac[i].PB(j);
					if(tmp!=j){
						++tab[tmp];
						fac[i].PB(tmp);
					}
				}
			}
		}
		gao(n);
	}
	return 0;
}

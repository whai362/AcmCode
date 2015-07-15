#include<stdio.h>   
#include<string.h>   
#include <cmath>
#include<algorithm>   
#include<iostream>
#define fr(i,s,n) for(int i=s;i<n;i++)
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=44721;
ll k;
bool flag[maxn+1];
int prime[maxn+1];
int t;

void getpri(){
	int i,j;t=0;
	int n=maxn;
	for(i=2;i<=n;++i) {
		if(!flag[i]) prime[t++]=i; 
		for(j=0;j<t&&i*prime[j]<=n;++j){ 
			flag[i*prime[j]]=1; 
			if(i%prime[j]==0) break; 
		} 
	} 
}

ll powMod(ll a, ll b, ll m){
	ll r = 1ll, d = a;
	while (b){
		if (b & 1ll){
			r *= d;
			r %= m;
		}
		d *= d;
		d %= m;
		b >>= 1;
	}
	return r;
}

int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
bool isPrime(ll x){   //判一个数是否为素
	if (x < 2ll) return false;
	if (x == 2ll) return true;
	if (!(x & 1ll)) return false;
	long long kk = 0, i, j, m, a;
	m = x - 1ll;
	while ((m & 1ll) == 0){
		m >>= 1;
		kk += 1;
	}
	for (i = 0;i < 10;i++){
		if (pri[i] >= x) return true;
		a = powMod(pri[i], m, x);
		if (a == 1ll) continue;
		for (j = 0;j < kk;j++){
			if (a == x - 1ll) break;
			a *= a;
			a %= x;
		}
		if (j < kk) continue;
		return false;
	}
	return true;
}

int totf=0;
ll prifac[100];
ll prifaccnt[100];

void  getfac_prepare(ll x){   //分解质因数
	fr(i,0,t){
		if (x<prime[i]) break;
		if (x%prime[i]==0){
			prifac[totf]=prime[i];
			while(x%prime[i]==0){
				x/=prime[i];
				prifaccnt[totf]++;
			}totf++;
		}
	}
	if (x!=1ll) {prifaccnt[totf]=1;prifac[totf++]=x;}
}
ll fac[100000];
int tf=0;
void getfac(int pos,int x){  //求出所有的约数
	fac[tf++]=x;
	if (pos>=totf) return ;
	ll cur=x;
	fr(i,0,prifaccnt[pos]+1){	
		getfac(pos+1,cur);
		cur*=prifac[pos];
	}
}

ll ans[1000000],cc=0;
void dfs(int pos,ll k,ll n){
	//if (n>=ans||n*k>=ans*2ll) return;
	if (k==1ll){
		ans[cc++]=n;
		//ans=n;return ;
	}
	if (pos<0) return;
	if (k%fac[pos]==0){
		ll tmpk=k/fac[pos];
		ll tmpn=n*(fac[pos]+1ll);
		while(tmpk%(fac[pos]+1ll)==0){
			tmpk/=(fac[pos]+1ll);tmpn*=(fac[pos]+1ll);
		}
		dfs(pos-1,tmpk,tmpn);
	}
	dfs(pos-1,k,n);
}

void solve(){
	int totprif=0;
	fr(i,0,tf){
		if (isPrime(fac[i] + 1ll)) {
			fac[totprif++]=fac[i];
		}
	}
	sort(fac,fac+totprif);
	totprif=unique(fac,fac+totprif)-fac;
	dfs(totprif-1,k,1);
	for(int i=0;i<cc;++i){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	cc=0;
	//if (ans<1ll<<60){	
	//	printf("%lld\n",ans);
	//}
	//else printf("0\n");
}

int main(){
	getpri();
	while(scanf("%lld",&k)!=EOF){
		totf=0;
		getfac_prepare(k); 
		tf=0;
		getfac(0,1);
		solve();
	}
	return 0;
}


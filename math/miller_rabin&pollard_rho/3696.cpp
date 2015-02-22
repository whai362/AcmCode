/*poj 3696
  题意：
  给出一个数字L,求出最短的888...8能被L整除，输出最短的长度。
  限制：
  1 <= L <= 2*10^9
  思路：
  设x为最小长度
  888...8=(10^x-1)/9*8
  由题意得：
  (10^x-1)/9*8 % L=0
  -> (10^x-1)*8 % (9L) = 0
  -> (10^x-1) % (9L/gcd(L,8)) = 0
  -> 10^x % (9L/gcd(L,8)) = 1
  这个是一个离散对数的问题，第一个想到的是用拓展BSGS做，但超时了。
  因为余数为1
  可以想到欧拉定理：a^phi(m) % m = 1 , 在a与m互质的条件下。
  回到这道题：
  在10 与 9L/gcd(L,8) 不互质的条件下，无解
  在10 与 9L/gcd(L,8) 互质的条件下
  求出tmp=phi(9L/gcd(L,8))，然后O(sqrt(tmp))枚举tmp的因子，选出最小的符合条件的因子就行了。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
LL a_b_MOD_c(LL a, LL b, LL m){
	LL ret = 1;
	a %= m;
	while(b){
		if(b & 1) ret = mul(ret, a, m);
		a = mul(a, a, m);
		b >>= 1;
	}
	return ret;
}
bool test(LL n, LL a, LL d){
	if(n == 2) return true;
	if(n == a) return true;
	if((n & 1) == 0) return false;
	while(!(d & 1)) d = d >> 1;
	LL t = a_b_MOD_c(a, d, n);
	while((d != n-1) && (t != 1) && (t != n-1)){
		t = mul(t, t, n);
		d = d << 1;
	}
	return (t == n-1 || (d & 1) == 1);
}
//要注意1的情况
const int Times=10;
bool Miller_Rabin(LL n){
	if(n < 2) return false;
	for(int i = 0; i <= Times; ++i){
		LL a=rand()%(n-1)+1;
		if(!test(n, a, n-1)) return false;
	}
	return true;
}
LL pollard_rho(LL n,LL c){
	LL i=1,k=2;
	LL x=rand()%(n-1)+1;
	LL y=x;
	while(1){
		++i;
		x=(mul(x,x,n)+c)%n;
		LL d=__gcd((y-x+n)%n,n);
		if(1<d && d<n) return d;
		if(y==x) return n;
		if(i==k){
			y=x;
			k<<=1;
		}
	}
}
//要注意1的情况
//LL ans;
LL fac[105];
int tot;
void find_fac(LL n,int c){
	if(n==1) return ;
	if(Miller_Rabin(n)){
		//ans=min(ans,n);
		fac[tot++]=n;
		return ;
	}
	LL p=n;
	LL k=c;
	while(p>=n) p=pollard_rho(p,c--);
	find_fac(p,k);
	find_fac(n/p,k);
}
void init(){
	//ans=n;
	tot=0;
}
//小心1的情况
LL get_phi(LL x){
	init();
	find_fac(x,12345);
	sort(fac,fac+tot);
	LL ret=1;
	for(int i=0;i<tot;++i){
		LL sqr=fac[i]*fac[i];
		if(x%sqr) ret*=fac[i]-1;
		else ret*=fac[i];
		x/=fac[i];
	}
	return ret;
}
int main(){
	LL L;
	int cas=0;
	int t;
	srand(12345);
	while(scanf("%I64d",&L) && L){
		LL m=L*9/__gcd(L,(LL)8);
		//cout<<m<<endl;
		printf("Case %d: ",++cas);
		if(__gcd(m,(LL)10)!=1) puts("0");
		else{
			LL phi=get_phi(m);
			//cout<<phi<<endl;
			int lim=sqrt(phi);
			LL ans=phi;
			for(int i=1;i<=lim;++i){
				if(phi%i==0){
					if(a_b_MOD_c(10,i,m)==1)
						ans=min((LL)i,ans);
					else if(a_b_MOD_c(10,phi/i,m)==1)
						ans=min(phi/i,ans);
				}
			}
			printf("%I64d\n",ans);
		}
	}
	return 0;
}

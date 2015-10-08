/*hdu 4767
  题意：
  求第n个bell数，模95041567输出。
  限制：
  1 <= n <= 2^31
  思路：
  模比较特别，我们先把他分解质因数，然后发现：
  95041567 = 31 x 37 x 41 x 43 x 47
  我们利用bell数的同余性质:
  (mB[n] + B[n+1]) % p = B[p^m + n] % p , 其中p为任意质数
  可以分别求B[n]%31, B[n]%37, B[n]%41, B[n]%43, B[n]%47的结果
  然后用中国剩余定理合并即可。
 */
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
#define LL __int64
const int MOD=95041567;
LL T[55],B[55];
void get_bell(int n,int mod){
    B[0]=1;
    B[1]=1;
    T[0]=1;
    for(int i=2;i<=n;++i){
        T[i-1]=B[i-1];
        for(int j=i-2;j>=0;--j)
            T[j]=(T[j]+T[j+1])%mod;
        B[i]=T[0];
    }
}
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret=Ext_gcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}
LL CRT(LL a[],LL m[],int n){
	LL M=1;
	for(int i=0;i<n;++i) M*=m[i];
	LL ret=0;
	for(int i=0;i<n;++i){
		LL x,y;
		LL tm=M/m[i];
		Ext_gcd(tm,m[i],x,y);
		ret=(ret+tm*x*a[i])%M;
	}
	return (ret+M)%M;
}
map<int,LL> vis;
LL bell_mod(int n,int mod){
	LL ret=vis[n];
	if(ret) return ret;
	if(n<=50) return B[n];
	LL k=0;
	LL P=1;
	while(P<n){
		P=P*mod;
		++k;
	}
	P/=mod;
	--k;
	return vis[n]=(k*bell_mod(n-P,mod)+bell_mod(n-P+1,mod))%mod;
}
LL fac[10],a[10];
int cnt;
void gao(int n,int mod){
	cnt=0;
	int x=mod;
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			fac[cnt++]=i;
			while(x%i==0) x/=i;
		}
	}
	if(x>1) fac[cnt++]=x;

	for(int i=0;i<cnt;++i){
		get_bell(50,fac[i]);
		vis.clear();
		a[i]=bell_mod(n,fac[i]);
		//cout<<fac[i]<<' '<<a[i]<<endl;
	}
	LL ans=CRT(a,fac,cnt);
	printf("%I64d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		gao(n,MOD);
	}
	return 0;
}

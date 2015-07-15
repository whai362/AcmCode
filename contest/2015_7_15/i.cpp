/*hdu 3304 Interesting Yang Yui Triangle
  题意：
  给出P,N，问第N行的斐波那契数模P不等于0的有多少个？
  限制：
  P < 1000，N <= 10^9
  思路：
  lucas定理，
  如果：
  n = a[k]*p^k + a[k-1]*p^(k-1) + ... + a[1]*p + a[0]
  m = b[k]*p^k + b[k-1]*p^(k-1) + ... + b[1]*p + b[0]
  则：
  C(n,m) = pe(i=0~k,C(a[i],b[i]))%p 其中pe表示连乘符号。

  由于n已经确定，所以a[i] (0 <= i <= k)已经确定，所以我们只需要找出每个a[i]有多少种b[i]，使得C(a[i],b[i])%P!=0，暴力一遍就可以了。
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long
const int MOD=10000;
const int N=105;
int a[N];
int cnt=0;
int ny[N];
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}

void predo(int p){
	ny[0]=1;
	for(int i=1;i<p;++i){
		ny[i]=inv(i,p);
	}
}
LL deal(int x,int p){
	LL ret=0;
	LL cur=1%p;
	if(cur) ++ret;
	for(int i=1;i<=x;++i){
		cur=cur*ny[i]%p*(x-i+1)%p;
		if(cur) ++ret;
	}
	return ret;
}
void gao(int p, int n){
	cnt=0;
	while(n){
		a[cnt++]=n%p;
		n/=p;
	}
	LL ans=1;
	for(int i=0;i<cnt;++i){
		ans=ans*deal(a[i],p)%MOD;
	}
	printf("%04lld\n",ans);
}
int main(){
	int p, n;
	int cas=0;
	while(scanf("%d%d", &p, &n) && (p||n)){
		predo(p);
		printf("Case %d: ",++cas);
		gao(p, n);
	}
	return 0;
}

/*hdu 5230 ZCC loves hacking
  题意：
  对[l,r]之间的数进行整数拆分，拆出来的数不能重复。问有多少种拆法。结果模998244353。
  限制：
  0 <= l <= r <= 1e5;
  思路：
  母函数，整数拆分。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define LL __int64
const int N=100005;
const int MOD=998244353;
int p[N],Q[N];
int five(int x){ return (3*x*x-x)/2; }
int PY;
void wbxs(){
	p[0]=1;
	PY=sqrt(N)+1;
	for(int i=-PY;i<=PY;++i)
		Q[i+PY]=five(i);
	for(int i=1;i<=100000;++i){
		int flag=1;
		for(int j=1;;++j){
			int a=Q[j+PY],b=Q[-j+PY];
			if(a>i && b>i) break;
			if(a<=i) p[i]=(p[i]+p[i-a]*flag)%MOD;
			if(b<=i) p[i]=(p[i]+p[i-b]*flag)%MOD;
			flag*=-1;
		}
		if(p[i]<0) p[i]=(p[i]+MOD)%MOD;
	}
}
LL deal(int n){
	LL ret=p[n];
	int flag=-1;
	for(int i=1;;++i){
		int a=Q[i+PY],b=Q[-i+PY];
		if(a*2>n && b*2>n) break;
		if(a*2<=n) ret=(ret+p[n-a*2]*flag)%MOD;
		if(b*2<=n) ret=(ret+p[n-b*2]*flag)%MOD;
		flag*=-1;
	}
	ret=(ret+MOD)%MOD;
	return ret;
}
void gao(int l,int r){
	LL ans=0;
	for(int i=l;i<=r;++i){
		ans=(ans+deal(i))%MOD;
	}
	printf("%I64d\n",ans);
}
int main(){
	wbxs();
	int T;
	scanf("%d",&T);
	while(T--){
		int n,c,l,r;
		scanf("%d%d%d%d",&n,&c,&l,&r);
		--n;
		l-=c;
		r-=c;
		gao(l,r);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
const int N=1e4+5;
LL f[N];
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}
LL predo(int m,int MOD){
	f[0]=1;
	for(int i=1;i<=min(m,MOD);++i)
		f[i]=f[i-1]*i%MOD;
}
LL C(int n,int m,int MOD){
	LL ret=1;
	for(int i=0;i<m;++i)
		ret=ret*(n-i)%MOD;
	return ret*inv(f[m],MOD)%MOD;
}
LL lucas(int n,int m,int MOD){
	if(n<m) return 0;	//зЂвт
	LL ret=1;
	while(n && m){
		LL a=n%MOD,b=m%MOD;
		if(a<b) return 0;
		ret=ret*C(a,b,MOD)%MOD;
		n/=MOD;
		m/=MOD;
	}
	return ret;
}
void gao(int n,int m,int MOD){
	LL ans=lucas(n-m+1,m,MOD);
	printf("%lld\n",ans);
}
int main(){
	int n,m,p;
	while(scanf("%d%d%d",&n,&m,&p)!=EOF){
		predo(m,p);
		gao(n,m,p);
	}
	return 0;
}

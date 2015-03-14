#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL __int64
const int N=1e5+5;
const int MOD=1000000007;
LL fac[2*N],ny[2*N];
//ÄæÔª·ÇµÝ¹éÐ´·¨
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}
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
void init(){
	fac[0]=1;
	ny[0]=inv(fac[0],MOD);
	for(int i=1;i<2*N;++i){
		fac[i]=fac[i-1]*i%MOD;
		ny[i]=inv(fac[i],MOD);
	}
}
int f[N],cnt;
LL fcs(int n,int m){
	n-=m;
	if(n<0) return 0;
	return fac[n+m-1]*ny[n]%MOD*ny[m-1]%MOD;
}
void gao(int n,int m){
	cnt=0;
	int lim=sqrt(n);
	for(int i=2;i<=lim;++i){
		if(n%i==0){
			f[cnt++]=i;
			if(n/i!=i) f[cnt++]=n/i;
		}
	}
	LL ans=fcs(n,m);
	for(int i=0;i<cnt;++i){
		ans=(ans+mu[f[i]]*fcs(n/f[i],m))%MOD;
	}
	ans=(ans+MOD)%MOD;
	printf("%d\n",ans);
}
int main(){
	getMu();
	init();
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(m==1){
			if(n==1) puts("1");
			else puts("0");
			continue;
		}
		gao(n,m);
		//cout<<fcs(n,m)<<endl;
	}
	return 0;
}

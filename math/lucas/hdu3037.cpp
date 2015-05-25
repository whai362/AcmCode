#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=1e5+5;
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
void predo(int MOD){
    f[0]=1;
    for(int i=1;i<MOD;++i){
        f[i]=f[i-1]*i%MOD;
    }
}
LL C(int n,int m,int MOD){
	if(m>n) return 0;
	return f[n]*inv(f[m]*f[n-m]%MOD,MOD)%MOD;
}
LL lucas(int n,int m,int MOD){
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
	printf("%I64d\n",lucas(n+m,n,MOD));
}
void In(int &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}
int main(){
	int T;
	//scanf("%d",&T);
	In(T);
	while(T--){
		int n,m,p;
		//scanf("%d%d%d",&n,&m,&p);
		In(n);
		In(m);
		In(p);
		predo(p);
		gao(n,m,p);
	}
	return 0;
}

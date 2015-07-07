#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=1050;
const int MOD=1000000007;
LL f[N],ny[N];
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}
void predo(){
	f[0]=ny[0]=1;
	for(int i=1;i<N;++i){
		f[i]=f[i-1]*i%MOD;
		ny[i]=inv(f[i],MOD);
	}
}
LL C(int n,int m){
	return f[n]*ny[m]%MOD*ny[n-m]%MOD;
}
LL gao(int a,int b){
	int n=a+b-1;
	int m=a;
	return C(n,m);
}

int main(){
	int n;
	predo();
	scanf("%d",&n);
	LL ans=1;
	int sum=0;
	for(int i=0;i<n;++i){
		int a;
		scanf("%d",&a);
		ans=ans*gao(sum,a)%MOD;
		sum+=a;
	}
	printf("%I64d\n",ans);
	return 0;
}

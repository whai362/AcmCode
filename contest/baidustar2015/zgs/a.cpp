#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=1e6+5;
const int MOD=1000000007;
LL f[N];
LL ny[N];
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
	f[0]=1;
	ny[0]=1;
	for(int i=1;i<N;++i){
		f[i]=f[i-1]*i%MOD;
		ny[i]=inv(f[i],MOD);
	}
}
LL C(int n,int m){
	return f[n]*ny[m]%MOD*ny[n-m]%MOD;
}
LL gao(int n){
	LL ans=1,tmp=1;
	for(int i=2;i<=n;i+=2){
		tmp=tmp*C(i,2)%MOD;
		//cout<<tmp<<endl;
		ans=(ans+C(n,i)*tmp%MOD*ny[i/2]%MOD)%MOD;
	}
	printf("%I64d\n",ans);
}
int main(){
	int T;
	int n;
	scanf("%d",&T);
	predo();
	while(T--){
		scanf("%d",&n);
		gao(n);
	}
	return 0;
}

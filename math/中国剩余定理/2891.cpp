#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
	if(b==0){ x=1,y=0; return a; }
	LL ret=Ext_gcd(b,a%b,y,x);
	y-=a/b*x;
	return ret;
}
int n;
LL a[100005],m[100005];
LL CRT(){
	LL M=m[0];
	LL ret=a[0];
	for(int i=1;i<n;++i){
		LL x,y,d;
		d=__gcd(M,m[i]);
		if((a[i]-ret)%d) return -1;
		Ext_gcd(M,m[i],x,y);
		x=(a[i]-ret)/d*x%(m[i]/d);
		ret+=x*M;
		M=M/d*m[i];
		ret%=M;
	}
	return (ret+M)%M;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i)
			scanf("%I64d%I64d",&m[i],&a[i]);
		printf("%I64d\n",CRT());
	}
	return 0;
}

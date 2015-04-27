#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const LL p1=99991;
const LL p2=99989;
const LL p3=1;
const LL p=95041567;
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}
LL deal(LL a[],LL t[],LL M[]){
	LL m=p2*p3;
	LL T=0,A=0;
	for(int i=0;i<3;++i){
		LL t1=(a[i]*t[i]/m)%p1;
		LL a1=a[i]*t[i]%m;
		t1=(t1*M[i]%p1+a1*M[i]/m)%p1;
		a1=a1*M[i]%m;
		T=(T+t1+(A+a1)/m)%p1;
		A=(A+a1)%m;
	}
	LL ret=(T*m%p+A)%p;
	return ret;
}
void gao(int n){
	LL a[3],M[3],t[3];
	a[0]=94608;
	a[1]=61532;
	a[2]=0;
	//a[0]=n%p1;
	//a[1]=n%p2;
	//a[2]=n%p3;
	M[0]=p2*p3;
	M[1]=p1*p3;
	M[2]=p1*p2;
	t[0]=inv(M[0],p1);
	t[1]=inv(M[1],p2);
	t[2]=inv(M[2],p3);
	//cout<<t1<<' '<<t2<<' '<<t3<<endl;
	//LL M=p1*p2*p3;
	//LL ans=(a1*t1*M1+a2*t2*M2+a3*t3*M3)%M;
	LL ans=deal(a,t,M);
	cout<<ans%p<<endl;
}
int main(){
	LL n;
	//cin>>n;
	//cout<<n%p<<endl;
	gao(n);
}

/*poj 1006
  题意：
  现在有三条式子：
  x%23=a1
  x%28=a2
  x%33=a3
  现在求最小的整数(x-d)
  限制：
  0 <= d <= 365
  思路：
  中国剩余定理

  条件：
  x%m_1=a_1
  x%m_2=a_2
  ...
  x%m_n=a_n
  m_1,m_2,...,m_n两两互质
  证明：
  设M=m_1*m_2*m_3*...*m_n
  M_i=M/m_i
  因为gcd(M_i,m_i)=1，所以M_ix+m_iy=1
  (t_i*M_i)%m_i=1	//由Ext_gcd(M_i,m_i,x,y)求出,t_i=x
  方程组的解：x=a_1*t_1*M_1+...+a_n*t_n*M_n
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
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
int main(){
	LL a[3],m[3],d;
	m[0]=23,m[1]=28,m[2]=33;
	LL M=m[0]*m[1]*m[2];
	int cas=0;
	while(scanf("%I64d%I64d%I64d%I64d",&a[0],&a[1],&a[2],&d)){
		if(a[0]==-1 && a[1]==-1 && a[2]==-1 && d==-1) break;
		LL ans;
		ans=CRT(a,m,3)-d;
		if(ans==0) ans=M;
		else ans=(ans+M)%M;
		printf("Case %d: the next triple peak occurs in %I64d days.\n",++cas,ans);
	}
	return 0;
}

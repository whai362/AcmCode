/*hdu4658
  题意：
  整数n进行拆分，拆分过程中一个数重复次数要小于k
  限制：
  0 <= n <= 1e5
  思路：
  母函数，五边形数定理
  可以得出该题的母函数为：
  G[x]=( 1 + x + x^2 +...+ x^(k-1) ) * ( 1 + x^2 + x^4 +...+ x^((k-1)*2) ) *...
      =(1-x^k)/(1-x) * (1-x^(k*2))/(1-x^2) * ...
	  =( (1-x^k) * (1-(x^k)^2) *... ) / ( (1-x) * (1-x^2) *... )
	  =Q(x^k)/Q(x)			(根据五边形数定理得)
	  =Q(x^k)*P(x)
	  =( 1 - x^k - (x^k)^2 + (x^k)^5 + (x^k)^7 -... ) * ( 1 + x + 2*x^2 + 3*x^3 + 5*x^4 + 7*x^5 + ... )
  接下来就是按照幂的对应关系算一下就行了。
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL __int64
const int N=100005;
const int MOD=1000000007;
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
int n,k;
void gao(){
	int ans=p[n];
	int flag=-1;
	for(int i=1;;++i){
		int a=Q[i+PY],b=Q[-i+PY];
		if(a*k>n && b*k>n) break;
		//cout<<a<<' '<<b<<endl;
		if(a*k<=n) ans=(ans+p[n-a*k]*flag)%MOD;
		if(b*k<=n) ans=(ans+p[n-b*k]*flag)%MOD;
		flag*=-1;
	}
	ans=(ans+MOD)%MOD;
	printf("%d\n",ans);
}
int main(){
	wbxs();
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		gao();
	}
	return 0;
}

/*cf493e
  题意：
  P(x)=a0+a1*x^1+a2*x^2+...+an*x^n
  给出t,a,b;
  求有多少种P(x)，使得P(t)=a，P(a)=b;
  解法：
  乱搞。
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL __int64
const int N=105;
LL f[N];
LL pow(LL a,int n){
	LL ret=1;
	for(int i=0;i<n;++i)
		ret*=a;
	return ret;
}
int solve(LL a,LL b){
	if(a==1) return 0;
	int ret=0;
	while(b){
		f[ret++]=b%a;
		b/=a;
	}
	return ret;
}
int main(){
	LL a,b,t;
	scanf("%I64d%I64d%I64d",&t,&a,&b);
	if(t==a && a==b){
		if(a==1) puts("inf");
		else puts("2");
	}
	else if(a==b) puts("1");
	else if(a>b) puts("0");
	else{
		if(t==1){
			int p=(log(b)/log(a)+eps);
			if(pow(a,p)==b){
				puts("1");
				return 0;
			}
		}
		int cnt=solve(a,b);
		LL sum=0;
		for(int i=0;i<cnt;++i)
			sum+=f[i]*pow(t,i);	
		if(sum!=a) puts("0");
		else puts("1");
	}
	return 0;
}

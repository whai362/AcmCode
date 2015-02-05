/*zoj3841
  题意：
  给出一副扑克牌
  先定义扑克牌的优先级
  A < 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < 10 < J < Q < K
  给出 一个已知的扑克牌排列
  问 剩下的扑克牌 能排出多少种比 给出的扑克牌序列 字典序小的方案。
  思路：
  dfs+组合数学
  从前到后搜
  每到一位，根据前面相等和不相等的情况分别处理
  如果相等，继续往下搜
  如果不相等，直接用组合数计算答案，如：
  1 1 1 2 2 3 3
  种数 = C(7,3)*C(4,2)*C(2,2)
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=1000000007;
#define LL long long
char str[105];
int a[105];
int tab[20];
int len;
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
	if(b==0) { x=1, y=0; return a; }
	LL ret= Ext_gcd(b,a%b,y,x);
	y-= a/b*x;
	return ret;
}

LL Inv(LL a,int m){
	LL d,x,y,t= (LL)m;
	d= Ext_gcd(a,t,x,y);
	if(d==1) return (x%t+t)%t;
	return -1;
}

LL Cm(LL n, LL m, LL p){
	LL a=1, b=1;
	if(m>n) return 0;
	while(m){
		a=(a*n)%p;
		b=(b*m)%p;
		m--;
		n--;
	}
	return (LL)a*Inv(b,p)%p;
}
int tran(char c){
	if(c=='A') return 0;
	else if(c=='0') return 9;
	else if(c>='2' && c<='9') return c-'1';
	else if(c=='J') return 10;
	else if(c=='Q') return 11;
	else if(c=='K') return 12;
}
LL gao(int p,int eq,int _sum,int tab[]){	//p表示第几位,eq前面表示是否相等,0表示不等,1表示相等,
											//_sum表示剩下多少张扑克牌,tab[]表示每种扑克牌剩下几张
	LL ret=0;
	if(p==len){
		if(eq==1) return 0;
	}
	if(_sum==0 && p){
		return 1;
	}
	if(eq==0){
		ret=1;
		for(int i=0;i<=12;++i){
			ret=(ret*Cm(_sum,tab[i],MOD))%MOD;
			_sum-=tab[i];
		}
		return ret;
	}
	else{
		for(int i=0;i<a[p];++i){
			if(tab[i]){
				--tab[i];
				ret=(ret+gao(p+1,0,_sum-1,tab))%MOD;
				++tab[i];
			}
		}
		if(tab[a[p]]){
			--tab[a[p]];
			ret=(ret+gao(p+1,1,_sum-1,tab))%MOD;
			++tab[a[p]];
		}
		return ret;
	}
}
int main(){
	while(scanf("%s",str)!=EOF){
		memset(a,-1,sizeof(a));
		memset(tab,0,sizeof(tab));
		len=0;
		int l=strlen(str);
		for(int i=0;i<l;++i){
			if(str[i+1]=='0'){
				a[len++]=tran('0');
				++i;
			}
			else{
				a[len++]=tran(str[i]);
			}
			++tab[a[len-1]];
		}
		int _sum=0;
		for(int i=0;i<=12;++i){
			tab[i]=4-tab[i];
			_sum+=tab[i];
		}
		printf("%lld\n",gao(0,1,_sum,tab));
	}
	return 0;
}

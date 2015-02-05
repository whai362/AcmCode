/*求原根模板
  关于原根的知识点：http://blog.csdn.net/whai362/article/details/43525015
 */
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define LL __int64
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= Ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

LL Inv(LL a,int m){   //求逆元
    LL d,x,y,t= (LL)m;
    d= Ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

LL a_b_MOD_c(LL a,LL b,LL mod){
	LL ret = 1;
	a %= mod;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

vector<LL> a;
bool g_test(LL g,LL p){
	for(LL i=0;i<a.size();++i)
		if(a_b_MOD_c(g,(p-1)/a[i],p)==1)
			return 0;
	return 1;
}
LL pri_root(LL p){
	LL tmp=p-1;
	for(LL i=2;i<=tmp/i;++i)
		if(tmp%i==0){
			a.push_back(i);
			while(tmp%i==0)
				tmp/=i;
		}
	if(tmp!=1)
		a.push_back(tmp);
	LL g=1;
	while(true){
		if(g_test(g,p))
			return g;
		++g;
	}
}
int main(){
	LL p=(479<<21)+1;
	cout<<p<<endl;
	LL g=pri_root(p);
	cout<<g<<endl;
	return 0;
}

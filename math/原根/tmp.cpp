#include<map>
#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll>f,as;
ll pow(ll a,ll b,ll mod){
	ll as=1;
	while(b){
		if(b&1)as=(as*a)%mod;
		a=(a*a)%mod;b>>=1;
	}
	return as;
}
bool g_test(ll g,ll p){
	for(ll i=0;i<f.size();i++)
	    if(pow(g,(p-1)/f[i],p)==1)
	        return 0;
	return 1;
}
ll yuangen(ll p){
	f.clear();
	ll tmp=p-1;
	for(ll i=2;i<=tmp/i;i++)
	    if(tmp%i==0){
	        f.push_back(i);
			while(tmp%i==0)
		    	tmp/=i;
		}
	if(tmp!=1)f.push_back(tmp);
	ll g=0;
	while(++g)
	    if(g_test(g,p))
	        return g;
}
ll discrete_log(ll x,ll n,ll m){//x^y=n (mod m) Çó y
	map<ll,int>rec;
	ll s=(ll)(sqrt(m)+0.5);
	ll cur=1;
	for(int i=0;i<s;i++){
		rec[cur]=i;
		cur=cur*x%m;
	}
	ll mul=cur;
	cur=1;
	for(int i=0;i<s;i++){
		ll more=n*pow(cur,m-2,m)%m;
		if(rec.count(more))return i*s+rec[more];
		cur=cur*mul%m;
	}
	return -1;
}
ll ex_gcd(ll a,ll b,ll& x,ll& y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	else{
		ll r=ex_gcd(b,a%b,y,x);
		y-=x*(a/b);
		return r;
	}
}
void line_mod_equation(ll a,ll b,ll n){//ax=b (mod n) Çóx
	ll x,y,d;as.clear();
	d=ex_gcd(a,n,x,y);
	if(b%d==0){
		x%=n;x+=n;x%=n;
		as.push_back(x*(b/d)%(n/d));
		for(ll i=1;i<d;i++)
		    as.push_back((as[0]+i*n/d)%n);
	}
}
int main(){
	cout<<g_test(2,998244353)<<endl;
	cout<<yuangen(998244353)<<endl;
	return 0;
}

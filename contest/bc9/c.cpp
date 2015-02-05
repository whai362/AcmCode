#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=10005,
	  MOD=123456789;
struct node{
	int l,r,cnt,m;
}v[N*3];
LL a[N],b[N];
void build(int l,int r,int n){
	int mid=(l+r)>>1;
	v[n].l=l,v[n].r=r,v[n].m=mid;
	if(l==r) return;
	build(l,mid,2*n);
	build(mid+1,r,2*n+1);
}
void insert(int x,int n){
	++v[n].cnt;
	if(v[n].l==v[n].r && v[n].l==x)
		return;
	if(x<=v[n].m)
		insert(x,2*n);
	else
		insert(x,2*n+1);
}

int _count(int l,int r,int n){
	if(v[n].l==l && v[n].r==r)
		return v[n].cnt;
	else{
		int sum=0;
		if(r<=v[n].m)
			sum+=_count(l,r,2*n);
		else if(l>v[n].m)
			sum+=_count(l,r,2*n+1);
		else
			sum+=_count(l,v[n].m,2*n)+_count(v[n].m+1,r,2*n+1);
		return sum;
	}
}

LL Ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= Ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

LL Inv(LL a,int m){   ///求逆元
    LL d,x,y,t= (LL)m;
    d= Ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

LL Cm(LL n, LL m, LL p)  ///组合数学
{
     LL a=1, b=1;
	 if(m>n) return 0;
     while(m)
     {
         a=(a*n)%p;
         b=(b*m)%p;
         m--;
         n--;
     }
     return (LL)a*Inv(b,p)%p;  ///（a/b）%p 等价于 a*（b，p）的逆元
}

int main(){
	int n,m;
	LL ans;
	scanf("%d%d",&n,&m);
	ans=0;
	for(int i=0;i<n;++i){
		scanf("%I64d",&a[i]);
		b[i]=a[i];
	}
	sort(b,b+n);
	int cnt=unique(b,b+n)-b;
	for(int i=0;i<n;++i){
		a[i]=(LL)(lower_bound(b,b+cnt,a[i])-b)+1;
	}
	build(0,cnt,1);
	for(int i=0;i<n;++i){
		int co=_count(0,(int)(a[i]-1),1);
		cout<<co<<endl;
		if(co>=m-1){
			ans=(ans+Cm((LL)co,(LL)(m-1),(LL)MOD))%MOD;
		}
		cout<<"!:"<<ans<<endl;
		insert((int)a[i],1);
	}
	cout<<ans<<endl;
	return 0;
}

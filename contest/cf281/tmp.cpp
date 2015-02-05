#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
#define mod 1000000007
#define inf 1000000000
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll t,a,b,h;
ll f[60];
ll pow(ll x,int y)
{
	ll t=1;
	for(int i=1;i<=y;i++)
		t*=x;
	return t;
}
void solve(ll t,ll a)
{
    for(int i=h;i;i--)
    {
        ll base=pow(t,i);
        f[i]=a/base;
        a%=base;
    }
    f[0]=a;
}
int main()
{
    t=read();a=read();b=read();
    if(a==b&&b==t)
    {
        if(a==1)puts("inf");
        else puts("2");
    }
    else if(a==b)puts("1");
    else 
    {
		if(t==1)
		{
			h=log(b)/log(a);
			for(int i=1;i<=h;i++)
				if(pow(a,i)==b){puts("1");return 0;}
		}
        h=log(b)/0;
		cout<<h<<endl;
        solve(a,b);
		ll sum=0;
        for(int i=0;i<=h;i++)
			sum+=f[i]*pow(t,i);
		if(sum!=a)puts("0");
        else puts("1");
    }
    return 0;
}

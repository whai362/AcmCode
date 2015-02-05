#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<bitset>
#include<ctime>

using namespace std;

int get()
{
	char c;
	while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
	bool flag=(c=='-');
	if(flag)
		c=getchar();
	int x=0;
	while(c>='0'&&c<='9')
	{
		x=x*10+c-48;
		c=getchar();
	}
	return flag?-x:x;
}

void output(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	int len=0,data[10];
	while(x)
	{
		data[len++]=x%10;
		x/=10;
	}
	if(!len)
		data[len++]=0;
	while(len--)
		putchar(data[len]+48);
	putchar('\n');
}

const int maxn=100;
const int maxm=maxn*2+1;
const long double eps=1e-10;

int child[maxm][2];
int flag[maxm],q[maxm],fail[maxm];
long double g[maxm][maxm+1];

int newnode(int x)
{
	child[x][0]=child[x][1]=flag[x]=-1;
	return x;
}

bool bigger(long long a0,long long a1,long long b0,long long b1)
{
	return (a1==b1)?(a0>b0):(a1>b1);
}

void subtract(long long &a0,long long &a1,long long b0,long long b1)
{
	a0-=b0;
	a1-=b1;
	if(a0<0)
	{
		a0+=1LL<<50;
		a1--;
	}
}

int main()
{
	int test=get();
	while(test--)
	{
		string s,t;
		cin>>s>>t;
		int n=s.size(),m=t.size();
		long long a0=0,a1=0,b0=0,b1=0,c0=0,c1=0,d0=0,d1=0;
		for(int i=1;i<=n;i++)
		{
			bool same=true;
			for(int j=0;same&&j<i;j++)
				same=(s[j]==s[n-i+j]);
			if(same)
			{
				if(i<50)
					a0|=1LL<<i;
				else
					a1|=1LL<<(i-50);
			}
			same=(i<=m);
			for(int j=0;same&&j<i;j++)
				same=(s[j]==t[m-i+j]);
			if(same)
			{
				if(i<50)
					b0|=1LL<<i;
				else
					b1|=1LL<<(i-50);
			}
		}
		for(int i=1;i<=m;i++)
		{
			bool same=true;
			for(int j=0;same&&j<i;j++)
				same=(t[j]==t[m-i+j]);
			if(same)
			{
				if(i<50)
					d0|=1LL<<i;
				else
					d1|=1LL<<(i-50);
			}
			same=(i<=n);
			for(int j=0;same&&j<i;j++)
				same=(t[j]==s[n-i+j]);
			if(same)
			{
				if(i<50)
					c0|=1LL<<i;
				else
					c1|=1LL<<(i-50);
			}
		}
		if(bigger(a0,a1,c0,c1))
		{
			subtract(a0,a1,c0,c1);
			subtract(d0,d1,b0,b1);
			b0=d0;b1=d1;
		}
		else
		{
			subtract(c0,c1,a0,a1);
			subtract(b0,b1,d0,d1);
			a0=c0;a1=c1;
		}
		if(a0==b0&&a1==b1)
			printf("Fair\n");
		else if(bigger(a0,a1,b0,b1))
			printf("B\n");
		else
			printf("A\n");
	}
	return 0;
}

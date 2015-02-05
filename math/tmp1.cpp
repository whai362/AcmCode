#include<iostream>
#include<cmath>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<string>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<ctime>
#include<bitset>
#include<cmath>
#define eps 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define ll __int64
#define LL long long
#define lson l,m,(rt<<1)
#define rson m+1,r,(rt<<1)|1
#define M 1000000007
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define Maxn 25
ll C[Maxn][Maxn];
struct PP
{
	ll a,b;
}B[Maxn],ans[Maxn];

ll k;

ll gcd(ll a,ll b)
{
	if(a%b==0)
	{
		if(b>0)
			return b;
		return -b;
	}

	return gcd(b,a%b);
}

PP add(PP a,PP b) //模拟两个分数的加法
{
	if(!a.a) //如果有一个为0
		return b;
	if(!b.a)
		return a;

	ll temp=a.b/gcd(a.b,b.b)*b.b; //求出分母的最小公倍数
	//printf("%I64d\n",temp);
	PP res;
	res.a=temp/a.b*a.a+temp/b.b*b.a; //分子相加
	res.b=temp;

	if(res.a)  //约掉最大公约数
	{
		ll tt=gcd(res.a,res.b);
		res.b/=tt;
		res.a/=tt;
	}
	return res;

}

void init()
{
	memset(C,0,sizeof(C));

	for(int i=0;i<=25;i++)
	{
		C[i][0]=1;
		for(int j=1;j<i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		C[i][i]=1;
	}
	B[0].a=1,B[0].b=1;  //求伯努利数

	for(int i=1;i<=20;i++)  //用递推关系求
	{
		PP temp;
		temp.a=0;
		temp.b=0;

		for(int j=0;j<i;j++)
		{
			PP tt=B[j];

			tt.a=tt.a*C[i+1][j];
			//printf("::::%I64d %I64d:\n",tt.a,tt.b);
			if(tt.a)
			{
				ll te=gcd(tt.a,tt.b);
				tt.a/=te;
				tt.b/=te;
			}

			temp=add(temp,tt);

			//printf("i:%d j:%d %I64d %I64d:\n",i,j,temp.a,temp.b);
			//system("pause");
		}

		temp.a=-temp.a;
		temp.b*=C[i+1][i];
		//printf("%I64d %I64d\n",temp.a,temp.b);
		//system("pause");

		//printf("%I64d\n",gcd(temp.a,temp.b));
		if(temp.a)
		{
			ll te=gcd(temp.a,temp.b);
			temp.a/=te;
			temp.b/=te;
		}
		else
			temp.b=0;
		B[i]=temp;
		//printf("i:%d %I64d %I64d\n",i,B[i].a,B[i].b);
		//system("pause");
	}
}



int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	//printf("%I64d\n",gcd(-6,12));

	init();
	while(~scanf("%I64d",&k))
	{

		ll cur=1;

		for(int i=0;i<=k;i++)
		{
			if(i==1)
			{
				ans[i].a=k+1;  //B[1]=-1/2要加上后面多出来的n^k
				ans[i].b=2;
			}
			else
			{
				ans[i]=B[i];
				ans[i].a*=C[k+1][i];
			}

			if(ans[i].a) //约分
			{
				ll temp=gcd(ans[i].a,ans[i].b);
				ans[i].a/=temp;
				ans[i].b/=temp;
			}
			else
				ans[i].b=0;
			if(ans[i].b) //求分母的最小公倍数
				cur=cur/gcd(cur,ans[i].b)*ans[i].b;

		}
		printf("%I64d ",cur*(k+1));
		//printf("->%I64d %I64d %I64d\n",cur,ans[0].a,ans[0].b);
		for(int i=0;i<=k;i++) //求出通分后每一个系数
		{
			if(ans[i].b)
				ans[i].a=cur/ans[i].b*ans[i].a;
			//printf("i:%d %I64d\n",i,ans[i].a);
		}
		for(int i=0;i<=k;i++)
			printf("%I64d ",ans[i].a);
		printf("0\n"); //最后一个肯定是0
	}
	return 0;
}

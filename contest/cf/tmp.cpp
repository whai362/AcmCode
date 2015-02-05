#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define ls l,mid,x<<1
#define rs mid+1,r,x<<1|1
using namespace std;
typedef long long Int;
const int Maxn=100002;
int color[Maxn<<2];
Int sum[Maxn<<2],add[Maxn<<2];
void build(int l,int r,int x)
{
	if(l==r)
	{
		color[x]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(ls),build(rs);
}
void down(int l,int r,int x)
{
	int mid=(l+r)>>1;
	color[x<<1]=color[x<<1|1]=color[x];
	if(!add[x])return;
	add[x<<1]+=add[x];
	add[x<<1|1]+=add[x];
	sum[x<<1]+=add[x]*(mid-l+1);
	sum[x<<1|1]+=add[x]*(r-mid);
	add[x]=0;
}
void merge(int l,int r,int x)
{
	color[x]=color[x<<1]==color[x<<1|1]?color[x<<1]:0;
	sum[x]=sum[x<<1]+sum[x<<1|1];
}
void up(int L,int R,int w,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(L<=l&&R>=r)
	{
		if(color[x])
		{
			sum[x]+=(r-l+((Int)1))*abs(w-color[x]);
			add[x]+=abs(w-color[x]);
			color[x]=w;
		}
		else
		{
			up(L,R,w,ls),up(L,R,w,rs);
			merge(l,r,x);
		}
		return;
	}
	if(color[x])down(l,r,x);
	if(L<=mid)up(L,R,w,ls);
	if(R>mid)up(L,R,w,rs);
	merge(l,r,x);
}
Int query(int L,int R,int l,int r,int x)
{
	if(L<=l&&R>=r)return sum[x];
	if(color[x])down(l,r,x);
	Int ret=0;
	int mid=(l+r)>>1;
	if(L<=mid)ret+=query(L,R,ls);
	if(R>mid)ret+=query(L,R,rs);
	return ret;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while(m--)
	{
		int a,b,c,d;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			scanf("%d",&d);
			up(b,c,d,1,n,1);
		}
		else
			printf("%I64d\n",query(b,c,1,n,1));
	}
} 


#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#define inf 1000000000
#define maxn 40000+100
#define maxm 200+50
#define eps 1e-10
#define ll long long
#define pa pair<int,int>
#define for0(i,n) for(int i=0;i<=n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define for2(i,x,y) for(int i=x;i<=y;i++)  
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,ans=0,block,a[maxn],c[maxn],d[maxn],pos[maxn],sum[maxn],f[maxm][maxn],g[maxm][maxm];
struct rec{int x,id;}b[maxn];
inline bool cmp(rec a,rec b)
{
	return a.x<b.x;
}
void ask(int x,int y)
{
	x=(x+ans-1)%n+1;y=(y+ans-1)%n+1;
	if(x>y)swap(x,y);
	cout<<x<<' '<<y<<endl;
	int bx=pos[x],by=pos[y],cnt=0,tmp=0,xx=0;
	if(by-bx<=1)
	{
		for2(i,x,y)d[++cnt]=a[i];
		sort(d+1,d+cnt+1);
		for1(i,cnt)
		{
			tmp++;
			if(i==cnt||d[i]!=d[i+1])
			{
				if(tmp>xx||(tmp==xx&&d[i]<ans))xx=tmp,ans=d[i];
				tmp=0;
			}
		}
	}
	else
	{
		for2(i,x,bx*block)d[++cnt]=a[i];
		for2(i,(by-1)*block+1,y)d[++cnt]=a[i];
		sort(d+1,d+cnt+1);
		ans=g[bx+1][by-1];xx=f[by-1][ans]-f[bx][ans];
		for1(i,cnt)
		{
			tmp++;
			if(i==cnt||d[i]!=d[i+1])
			{
				tmp+=f[by-1][d[i]]-f[bx][d[i]];
				if(tmp>xx||(tmp==xx&&d[i]<ans))xx=tmp,ans=d[i];
				tmp=0;
			}
		}
	}
	ans=c[ans];
	printf("%d\n",ans);
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	n=read();m=read();
	for1(i,n)b[i].x=read(),b[i].id=i;
	sort(b+1,b+n+1,cmp);
	int tot=0;
	for1(i,n)
	{
		if(i==1||b[i].x!=b[i-1].x)tot++;
		a[b[i].id]=tot;
		c[tot]=b[i].x;
	}
	block=floor(sqrt(n));
	for1(i,n)
	{
		pos[i]=(i-1)/block+1;
		sum[a[i]]++;
		if(i==n||i==pos[i]*block)for1(j,tot)f[pos[i]][j]=sum[j];
	}
	for1(i,pos[n])
		for2(j,i,pos[n])
		{
			ans=g[i][j-1];
			for2(k,(j-1)*block+1,min(j*block,n))
				if(f[j][a[k]]-f[i-1][a[k]]>f[j][ans]-f[i-1][ans]||
						(f[j][a[k]]-f[i-1][a[k]]==f[j][ans]-f[i-1][ans]&&a[k]<ans))ans=a[k];
			g[i][j]=ans;   
		}
	ans=0;  
	while(m--)ask(read(),read());
	return 0;
}

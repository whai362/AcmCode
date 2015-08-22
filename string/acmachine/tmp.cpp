#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 10007
using namespace std;
int n,m,sz=1,ans1,ans2=1;
int a[6001][27],point[6001],q[6001],f[101][6001];
char s[101];
bool danger[6001];
void ins()
{
	int now=1,c;
	for(int i=0;i<strlen(s);i++)
	{
		c=s[i]-'A'+1;
		if(a[now][c])now=a[now][c];
		else now=a[now][c]=++sz;
	}
	danger[now]=1;
}
void acmach()
{
	int t=0,w=1,now;
	q[0]=1;point[1]=0;
	while(t<w)
	{
		now=q[t++];
		for(int i=1;i<=26;i++)
		{
			if(!a[now][i])continue;
			int k=point[now];
			while(!a[k][i])k=point[k];
			point[a[now][i]]=a[k][i];
			if(danger[a[k][i]])
			   danger[a[now][i]]=1;
            q[w++]=a[now][i];
		}
	}
}
void dp(int x)
{
	for(int i=1;i<=sz;i++)
	{
		if(danger[i]||!f[x-1][i])continue;
		for(int j=1;j<=26;j++)
		{
			int k=i;
			while(!a[k][j])k=point[k];
			f[x][a[k][j]]=(f[x][a[k][j]]+f[x-1][i])%mod;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=26;i++)a[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		ins();
	}
	acmach();
	f[0][1]=1;
	for(int i=1;i<=m;i++)dp(i);
	for(int i=1;i<=m;i++)
	   ans2=(ans2*26)%mod;
    for(int i=1;i<=sz;i++)
       if(!danger[i])ans1=(ans1+f[m][i])%mod;
    printf("%d",(ans2-ans1+mod)%mod);
	return 0;
}

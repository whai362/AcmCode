#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1005
struct data{
	int cnt,id;
}d[N];
int mp[N][N];
int path[N],visit[N];
int n,flag;
void dfs(int x,int step)
{
	path[step]=x;
	if(step==n)
	{
		flag=1;
		return;
	}
	if(flag)
	  return ;
	for(int i=1;i<=n;i++)
	{
		if(mp[x][i]==1 && visit[i]==0)
		{
			visit[i]=1;
			dfs(i,step+1);
			if(flag)
			  return ;
			visit[i]=0;
		}
	}
}
bool cmp(data d1,data d2){
	return d1.cnt<d2.cnt;
}
int main()
{
	int t,a,b;
	while(scanf("%d",&n)!=EOF){
	flag=0;
	memset(d,0,sizeof(d));
	memset(mp,0,sizeof(mp));
	memset(path,0,sizeof(path));
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=n;++i){
		d[i].id=i;
		for(int j=1;j<=n;++j){
			scanf("%d",&mp[i][j]);
			if(mp[i][j]) ++d[i].cnt;
		}
	}
	sort(d+1,d+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		visit[d[i].id]=1;
		dfs(d[i].id,1);
		if(flag)
		{
			for(int j=1;j<n;j++)
			  printf("%d ",path[j]);
			printf("%d\n",path[n]);
			break;
		}
		visit[d[i].id]=0;
	}
	}
	return 0;
}


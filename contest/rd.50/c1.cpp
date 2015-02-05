#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,g[100100][5],v[100100];
bool vis[100100];
bool dfs(int a,int b,int k)
{
  	v[k-1]=a,v[k]=b;
  	if(k==n) return 1==b;
	vis[b]=1;
	for(int i=0;i<4;++i)
	{
  		int c=g[b][i];
  		if(vis[c])continue;
  		if((g[a][0]==c||g[a][1]==c||g[a][2]==c||g[a][3]==c) && dfs(b,c,k+1))	return 1;
    }
    vis[b]=0;
    return 0;
}
int main() 
{
  	cin>>n;
  	int num[100100];
  	memset(num,0,sizeof(num));
  	int a,b;
  	for(int i=0;i<2*n;i++)
  	{
  		scanf("%d%d",&a,&b);
    	g[a][num[a]++]=b;
    	g[b][num[b]++]=a;
    	if(num[a]>4||num[b]>4)
    	{
    		puts("-1");
    		return 0;
    	}
  	}
  	for(int i=0;i<4;++i)
  	{
    	if(dfs(1,g[1][i],1))
    	{
      		for(int j=0;j<n;++j)	cout<<v[j]<<" ";
      		printf("\n");
      		return 0;
    	}
  	}
  	puts("-1");
  	return 0;
}


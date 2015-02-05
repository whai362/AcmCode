#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXINT 10000000
int a[209][209];
int dis[209],s[209];
int n;

void dijkstral(int v0)
{
	memset(s,0,sizeof(s));
	memset(dis,0,sizeof(dis));
	for(int i=0;i<n;i++)
		dis[i]=a[v0][i];
	s[v0]=1;
	int w=MAXINT;
	int m=0;
	do
	{
		w=MAXINT;
		m=0;
		int i;
		for(i=0;i<n;i++)
		{
			if(s[i]==0 && dis[i]<w) 
			{
				m=i;
				w=dis[i];
			}
		}
		if(m!=i) s[m]=1;
		else return ;
		for(int i=0;i<n;i++)
		{
			if(s[i]==0 && dis[m]+a[m][i]<dis[i]) 
			{
				dis[i]=dis[m]+a[m][i];
			}
		}
	}while(m!=0);
}

int main()
{
	while(cin>>n)
	{
		n++;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
				if(i == j) a[i][j]=MAXINT;
			}
		dijkstral(0);
		for(int i=1;i<n;i++)
			cout<<dis[i]<<' ';
		cout<<endl;
	}
	return 0;
}
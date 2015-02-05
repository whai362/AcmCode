/*Dijkstra最短路*/
/*人口参数:a[][],s,t,n*/
/*a[][]为邻接矩阵,s为起点,t为终点,n为点的数目*/
/*出口参数最短路*/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define Min(x,y) ((x)<(y)?(x):(y))
#define inf 0x3f3f3f3f
#define N 1005
int a[N][N],dis[N];		//a[][]为邻接矩阵,dis[]存最短/长路
bool vis[N];	//访问过的点
int n;
int dij(){
	int i,j,k,tmp;
	int s=1;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;++i) dis[i]=a[s][i];
	vis[s]=1;
	for(i=1;i<n;++i){
		tmp=inf,k=s;	//tmp=0时为最长路
		for(j=1;j<=n;++j){
			if(!a[j][i]||vis[j]) continue;
			if(tmp>dis[j]){		//<时为最长路
				tmp=dis[j];
				k=j;
			}
		}
		vis[k]=1;
		//if(k==t) return tmp;	//返回最短/长路
		for(j=1;j<=n;++j){
			if(vis[j]) continue;
			dis[j]=Min(dis[j],dis[k]+a[k][j]);
		}
	}
}
int main(){
	int c,d,i,m,t,u,v;
	int cnt=1;
	while(scanf("%d",&n)!=EOF){
		++n;
		memset(a,0x3f,sizeof(a));
		/*求最短路时要memset(a,0x3f,sizeof(a)),最长路要memset(a,0,sizeof(a))*/
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&a[i][j]);
		dij();
		if(cnt==62){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j)
					cout<<a[i][j]<<' ';
				cout<<endl;
			}
			printf("%d",dis[2]);
			for(int i=3;i<=n;++i){
				printf(" %d",dis[i]);
			}
			puts(" ");
		}
		++cnt;
	}
	return 0;
}

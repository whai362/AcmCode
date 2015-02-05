#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1005
int d[N],vis[N],t[N][3],flag;
int dfs(int i){
	if(!i || vis[i])
		return 0;
	vis[i]=1;
	if(!flag && (d[i]==1 || d[i]==2)){
		return 1;
	}
	if(flag) flag=0;
	return dfs(t[i][0])+dfs(t[i][1])+dfs(t[i][2])+1;
}
int main(){
	int n,u,v,T;
	int i,l;
	scanf("%d",&T);
	for(l=1;l<=T;++l){
	scanf("%d",&n);
	memset(d,0,sizeof(d));
	memset(t,0,sizeof(t));
	for(i=0;i<n-1;++i){
		scanf("%d%d",&u,&v);
		++d[u];
		++d[v];
		if(t[u][0]==0) t[u][0]=v;
		else if(t[u][1]==0) t[u][1]=v;
		else t[u][2]=v;
		if(t[v][0]==0) t[v][0]=u;
		else if(t[v][1]==0) t[v][1]=u;
		else t[v][2]=u;
	}
	int ans=0;
	for(i=1;i<=n;++i){
		if(d[i]){
			flag=1;
			memset(vis,0,sizeof(vis));
			ans=max(ans,dfs(i));
		}
	}
	cout<<"Case #"<<l<<": "<<n-ans<<endl;
	}
	return 0;
}

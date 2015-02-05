#include<iostream>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
#define N 105
struct Path{
	int cnt,path[N];
};
int n,m;
bool vis[N];
int dis[N],_map[N][N];
Path p[N];
int dij(int s,int t){
	int i,j,k,l,tmp;
	memset(vis,0,sizeof(vis));
	for(i=0;i<=n;++i) dis[i]=_map[s][i];
	vis[s]=true;
	for(i=1;i<n;++i){
		tmp=INF;
		k=s;
		for(j=1;j<=n;++j){
			if(vis[j]) continue;
			if(dis[j]<tmp){
				tmp=dis[j];
				k=j;
			}
		}
		vis[k]=1;
		if(k==t) return tmp;
		for(j=1;j<=n;++j){
			if(vis[j]) continue;
			if(dis[j]>dis[k]+_map[k][j]){
				dis[j]=dis[k]+_map[k][j];
				for(l=0;l<p[k].cnt;++l)
					p[j].path[l]=p[k].path[l];
				p[j].cnt=p[k].cnt;
				p[j].path[p[j].cnt++]=k;
			}
		}
	}
	return 0;
}
int main(){
	int u,v,c;
	int i;
	cin>>n>>m;
	memset(_map,0x3f,sizeof(_map));
	for(i=0;i<m;++i){
		cin>>u>>v>>c;
		_map[u][v]=c;
	}
	int s=1,t=5;
	cout<<dij(s,t)<<endl;
	cout<<s<<"->";
	for(i=0;i<p[t].cnt;++i)
		cout<<p[t].path[i]<<"->";
	cout<<t<<endl;
	return 0;
}

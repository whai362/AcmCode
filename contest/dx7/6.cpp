#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=205,
	  INF=0x3f3f3f3f;
int n,m,
	des[N][N],
	bui[N][N];
bool vis[N];
void init(){
	memset(des,0,sizeof(des));
	memset(bui,0,sizeof(bui));
	memset(vis,0,sizeof(vis));
}
int main(){
	int cas=0,T,
		u,v,d,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i){
			scanf("%d%d%d%d",&u,&v,&d,&b);
			des[u][v]=d;
			bui[u][v]=b;
		}
	}
	int nx=0,ny=0;
	for(int i=0;i<n;++i){
		int tmpj=0,minx=0,miny=INF;
		for(int j=1;j<=n;++j){
			if(!vis[j]){
				tmpx=nx,
			}
		}
	}
}

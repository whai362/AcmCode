#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define pb push_back
const int N=50005,
	  INF=0x3f3f3f3f;
struct Edge{
	int to,next;
}edge[2*N];
int n,tot,
	sum[N],
	_max[N],
	head[N],
	du[N];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
	memset(du,0,sizeof(du));
}
void addEdge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;  
}
int dfs(int u,int fa){
	sum[u]=1;
	_max[u]=0;
	for(int i=head[u];i!=-1;i=edge[i].next){
		int to=edge[i].to;
		if(to!=fa){
			int tmp=dfs(to,u);
			sum[u]+=tmp;
			_max[u]=max(_max[u],tmp);
		}
	}
	return sum[u];
}
void gao(){
	int st;
	for(st=1;st<=n;++st){
		if(du[st]==1) break;
	}
	dfs(st,0);
	int ans=INF;
	for(int i=1;i<=n;++i){
		_max[i]=max(_max[i],n-sum[i]);
		ans=min(ans,_max[i]);
	}
	for(int i=1;i<=n;++i){
		if(_max[i]==ans)
			printf("%d ",i);
	}
	puts("");
}
int main(){
	int u,v;
	scanf("%d",&n);
	init();
	for(int i=0;i<n-1;++i){
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		addEdge(v,u);
		++du[u];
		++du[v];
	}
	gao();
	return 0;
}

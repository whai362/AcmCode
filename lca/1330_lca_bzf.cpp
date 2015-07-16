#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define pb push_back
using namespace std;
const int N=100005,
	  LOGN=22;
int root,n;
int ind[N],
	depth[N],
	fa[N][LOGN];
vector<int> tree[N];

void dfs(int u,int p,int d){
	depth[u]=d;
	fa[u][0]=p;
	for(int i=0;i<tree[u].size();++i){
		if(tree[u][i]!=p)
			dfs(tree[u][i],u,d+1);
	}
}
int lca(int u,int v){
	if(depth[u]>depth[v]) swap(u,v);
	for(int i=0;i<LOGN;++i)
		if(((depth[v]-depth[u]) >> i) & 1)
			v=fa[v][i];
	if(u==v) return u;
	for(int i=LOGN-1;i>=0;--i)
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
void init(){
	for(int i=1;i<=n;++i)
		if(!ind[i]){
			root=i;
			break;
		}
	dfs(root,-1,0);
	for(int k=0;k+1<LOGN;++k)
		for(int i=1;i<=n;++i){
			if(fa[i][k]<0) fa[i][k+1]=-1;
			else fa[i][k+1]=fa[fa[i][k]][k];
		}
}
int main(){
	int T;
	int a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(ind,0,sizeof(ind));
		for(int i=0;i<=n;++i)
			tree[i].clear();
		for(int i=0;i<n-1;++i){
			scanf("%d%d",&a,&b);
			tree[a].pb(b);
			++ind[b];
		}
		init();
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}

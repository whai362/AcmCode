#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N=10005;
int f[N],r[N],indeg[N];
bool vis[N];
vector<int> tree[N],qes[N];
int ancestor[N];
int n;
void init(){
	memset(indeg,0,sizeof(indeg));
	memset(vis,0,sizeof(vis));
	memset(ancestor,0,sizeof(ancestor));
	for(int i=1;i<=n;++i){
		r[i]=1;
		f[i]=i;
		tree[i].clear();
		qes[i].clear();
	}
}

int find(int x){
	if(f[x]!=x) return f[x]=find(f[x]);
	return x;
}

void merge(int a,int b){
	int fa=find(a),
		fb=find(b);
	if(fa==fb) return ;
	if(r[fa]<=r[fb]){
		f[fa]=fb;
		r[fb]+=r[fa];
	} else {
		f[fb]=fa;
		r[fa]+=r[fb];
	}
}
void LCA(int u){
	ancestor[u]=u;
	for(int i=0;i<tree[u].size();++i){
		LCA(tree[u][i]);
		merge(u,tree[u][i]);
		ancestor[find(u)]=u;
	}
	vis[u]=true;
	for(int i=0;i<qes[u].size();++i){
		if(vis[qes[u][i]]){
			printf("%d\n",ancestor[find(qes[u][i])]);
			return ;
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		int u,v;
		for(int i=0;i<n-1;++i){
			scanf("%d%d",&u,&v);
			tree[u].push_back(v);
			++indeg[v];
		}
		scanf("%d%d",&u,&v);
		qes[u].push_back(v);
		qes[v].push_back(u);
		for(int i=1;i<=n;++i){
			if(indeg[i]==0){
				LCA(i);
				break;
			}
		}
	}
	return 0;
}

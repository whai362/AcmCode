#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define PB push_back
const int MAX_V=1005;
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
void add_edge(int u,int v){
	G[u].PB(v);
	G[v].PB(u);
}
bool dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();++i){
		int u=G[v][i];
		int w=match[u];
		if(w<0 || !used[w] && dfs(w)){
			match[v]=u;
			match[u]=v;
			return true;
		}
	}
	return false;
}
int bi_match(){
	int res=0;
	memset(match,-1,sizeof(match));
	for(int v=0;v<V;++v){
		if(match[v]<0){
			memset(used,0,sizeof(used));
			if(dfs(v)) ++res;
		}
	}
	return res;
}

int mp[205][205];
void init(){
	memset(mp,0,sizeof(mp));
	for(int i=0;i<MAX_V;++i)
		G[i].clear();
}
int main(){
	int n,m,k;
	int cas=0;
	while(scanf("%d%d%d",&n,&m,&k) && (n || m || k)){
		init();
		V=n+m;
		int u,v;
		for(int i=0;i<k;++i){
			scanf("%d%d",&u,&v);
			--u,--v;
			mp[u][v]=1;
		}
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(mp[i][j]==0) add_edge(i,j+n);
		//for(int i=0;i<V;++i){
		//	cout<<i<<':'<<endl;
		//	for(int j=0;j<G[i].size();++j)
		//		cout<<G[i][j]<<' ';
		//	cout<<endl;
		//}
		printf("Case %d: ",++cas);
		int ans=V-bi_match();
		printf("%d\n",ans);
	}
	return 0;
}

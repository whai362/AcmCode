#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define K 105
#define N 1005
bool vis[N];
int g[K],cnt[N];
vector<int> _map[N];
void dfs(int pa){
	vis[pa]=true;
	++cnt[pa];
	int sz=_map[pa].size();
	for(int i=0;i<sz;++i){
		if(!vis[_map[pa][i]])
			dfs(_map[pa][i]);
	}
}
int main(){
	int n,m,k;
	int i,j;
	scanf("%d%d%d",&k,&n,&m);
	for(i=0;i<k;++i){
		scanf("%d",&g[i]);
	}
	for(i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		_map[u].push_back(v);
	}
	for(i=0;i<k;++i){
		memset(vis,0,sizeof(vis));
		dfs(g[i]);
	}
	int ans=0;
	for(i=1;i<=n;++i){
		if(cnt[i]==k){
			//cout<<i<<endl;
			++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}

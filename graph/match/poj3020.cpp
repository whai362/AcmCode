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
void init(){
	for(int i=0;i<MAX_V;++i)
		G[i].clear();
}
const int N=45;
char str[N][N];
int mp[N][N];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int h,w;
bool ok(int x,int y){
	if(x>=0 && x<h && y>=0 && y<w && str[x][y]=='*')
		return true;
	return false;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&h,&w);
		for(int i=0;i<h;++i)
			scanf("%s",str[i]);
		V=0;
		for(int i=0;i<h;++i)
			for(int j=0;j<w;++j){
				if(str[i][j]=='*') mp[i][j]=V++;
				else mp[i][j]=-1;
			}
		for(int i=0;i<h;++i)
			for(int j=0;j<w;++j){
				if(mp[i][j]!=-1){
					int u=mp[i][j],v;
					for(int k=0;k<4;++k){
						int tmpx=i+dx[k];
						int tmpy=j+dy[k];
						if(ok(tmpx,tmpy)){
							v=mp[tmpx][tmpy];
							add_edge(u,v+V);
						}
					}
				}
			}
		//for(int i=0;i<V;++i){
		//	cout<<i<<':'<<endl;
		//	for(int j=0;j<G[i].size();++j){
		//		cout<<G[i][j]<<' ';
		//	}
		//	cout<<endl;
		//}
		int ans=bi_match();
		ans=V-ans/2;
		printf("%d\n",ans);
	}
	return 0;
}

#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 105
void dfs(int k,int n,int _map[][MAXN],int vis[]){
	int i;
	vis[k-1]=1;
	cout<<k<<endl;
	for(i=0;i<n;++i){
		if(_map[k-1][i] && !vis[i]){
			dfs(i+1,n,_map,vis);
		}
	}
}
int main(){
	int i,n,e,u,v;
	int _map[MAXN][MAXN],vis[MAXN];
	cout<<"ÊäÈëÍ¼: "<<endl;
	cin>>n>>e;
	memset(_map,0,sizeof(_map));
	memset(vis,0,sizeof(vis));
	for(i=0;i<e;++i){
		cin>>u>>v;
		_map[u-1][v-1]=_map[v-1][u-1]=1;
	}
	cout<<"ÉîËÑ±éÀú: "<<endl;
	dfs(1,n,_map,vis);
	return 0;
}



#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define PB push_back
const int N=200005;
vector<int> G[N];
int vis[N];
int in[N];
void bfs(int s){
	vis[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		int pre=vis[now];
		for(int i=0;i<G[now].size();++i){
			int ch=G[now][i];
			if(vis[ch]==0){
				vis[ch]=pre%2+1;
				q.push(ch);
			}
		}
	}
}
bool gao(int n){
	for(int i=1;i<=n;++i){
		if(in[i]==0) return false;
		if(vis[i]==0){
			bfs(i);
		}
	}
	return true;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		G[u].PB(v);
		G[v].PB(u);
		++in[u];
		++in[v];
	}
	if(!gao(n)) puts("NIE");
	else{
		puts("TAK");
		for(int i=1;i<=n;++i){
			if(vis[i]==1) puts("K");
			else puts("S");
		}
	}
	return 0;
}

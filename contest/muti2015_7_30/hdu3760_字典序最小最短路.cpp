#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int N=100005;
#define PB push_back
struct E{
	int v;
	int c;
};
vector<E> G[N];
int level[N];
int path[N];
int minn[N];
void bfs(int end){
	memset(level,0,sizeof(level));
	queue<int> q;
	q.push(end);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<G[now].size();++i){
			int ch=G[now][i].v;
			if(level[ch]==0 && ch!=end){
				level[ch]=level[now]+1;
				q.push(ch);
			}
		}
	}
}
void dij(){
	memset(path,0x3f,sizeof(path));
	memset(minn,0x3f,sizeof(minn));
	queue<E> q;
	q.push((E){1,0});
	while(!q.empty()){
		E now=q.front();
		q.pop();
		int now_level=level[now.v];
		if(now.c>path[now_level])
			continue;
		for(int i=0;i<G[now.v].size();++i){
			E ch=G[now.v][i];
			if(level[ch.v]==now_level-1 && ch.c<=path[now_level-1]){
				path[now_level-1]=ch.c;
				if(ch.c<minn[ch.v]){
					minn[ch.v]=ch.c;
					q.push(ch);
				}
			}
		}
	}
}
void init(int n){
	for(int i=1;i<=n;++i)
		G[i].clear();
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		init(n);
		for(int i=0;i<m;++i){
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			G[u].PB((E){v,c});
			G[v].PB((E){u,c});
		}
		bfs(n);
		dij();
		printf("%d\n",level[1]);
		for(int i=level[1]-1;i>=0;--i)
			printf("%d%c",path[i],i==0?'\n':' ');
	}
	return 0;
}

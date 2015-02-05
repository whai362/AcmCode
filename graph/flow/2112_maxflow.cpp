#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N=250;
int K,C,M;

struct Edge{
	int to,cap,rev;
};
const int MAX_V=405,
	  INF=0x3f3f3f3f;
vector<Edge> G[MAX_V];
int level[MAX_V];	//顶点到源点的距离标号
int iter[MAX_V];	//当前弧，在其之前的边已经没有用了
void addEdge(int from,int to,int cap){
	G[from].push_back((Edge){to,cap,G[to].size()});
	G[to].push_back((Edge){from,0,G[from].size()-1});
}
//通过bfs计算从源点出发的距离标号
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();++i){
			Edge &e=G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
//通过dfs寻找增广路
int dfs(int v,int t,int f){
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();++i){
		Edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
//求解从s到t的最大流
int maxFlow(int s,int t){
	int flow=0;
	while(1){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
	return flow;
}

int _map[250][250];
void init(){
	for(int i=0;i<=K+C+1;++i){
		G[i].clear();
	}
}
void build(int dis){
	init();
	for(int i=K+1;i<=K+C;++i){
		addEdge(0,i,1);
		for(int j=1;j<=K;++j){
			if(_map[i][j]<=dis){
				addEdge(i,j,1);
			}
		}
	}
	for(int i=1;i<=K;++i){
		addEdge(i,K+C+1,M);
	}
}
void gao(){
	int l=1,r=200*(K+C),mid;
	while(l<r){
		mid=(l+r)>>1;
		build(mid);
		if(maxFlow(0,K+C+1)==C) r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
}
int main(){
	scanf("%d%d%d",&K,&C,&M);
	for(int i=1;i<=K+C;++i){
		for(int j=1;j<=K+C;++j){
			scanf("%d",&_map[i][j]);
			if(_map[i][j]==0) _map[i][j]=INF;
		}
	}
	for(int k=1;k<=K+C;++k)
		for(int i=1;i<=K+C;++i)
			for(int j=1;j<=K+C;++j)
				_map[i][j]=min(_map[i][j],_map[i][k]+_map[k][j]);
	gao();
	return 0;
}

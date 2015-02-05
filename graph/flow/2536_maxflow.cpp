#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int n,m;

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

void init(){
	for(int i=0;i<=n+m+1;++i){
		G[i].clear();
	}
}

struct Point{
	double x,y;
}g[MAX_V],h[MAX_V];
double dis(Point a,Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
	double s,v;
	while(~scanf("%d%d%lf%lf",&n,&m,&s,&v)){
		init();
		for(int i=1;i<=n;++i){
			scanf("%lf%lf",&g[i].x,&g[i].y);
		}
		for(int i=1;i<=m;++i){
			scanf("%lf%lf",&h[i].x,&h[i].y);
		}
		for(int i=1;i<=n;++i){
			addEdge(0,i,1);
			for(int j=1;j<=m;++j){
				if(dis(g[i],h[j])<=s*s*v*v)
					addEdge(i,n+j,1);
			}
		}
		for(int i=1;i<=m;++i){
			addEdge(n+i,n+m+1,1);
		}
		printf("%d\n",n-maxFlow(0,n+m+1));
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
int n,f,d;

struct Edge{
	int to,cap,rev;
};
const int MAX_V=1005,
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
	for(int i=0;i<=2*n+f+d+1;++i)
		G[i].clear();
}
int main(){
	while(scanf("%d%d%d",&n,&f,&d)!=EOF){
		init();
		for(int i=1;i<=f;++i)
			addEdge(0,i,1);
		for(int i=1;i<=n;++i)
			addEdge(f+i,f+n+i,1);
		for(int i=1;i<=d;++i){
			addEdge(f+2*n+i,f+2*n+d+1,1);
		}
		for(int i=1;i<=n;++i){
			int fn,dn,fo,dr;
			scanf("%d%d",&fn,&dn);
			for(int j=0;j<fn;++j){
				scanf("%d",&fo);
				addEdge(fo,f+i,1);
			}
			for(int j=0;j<dn;++j){
				scanf("%d",&dr);
				addEdge(f+n+i,f+2*n+dr,1);
			}
		}
		/*for(int i=0;i<=2*n+f+d+1;++i){
			cout<<i<<':';
			for(int j=0;j<G[i].size();++j){
				if(G[i][j].cap) cout<<G[i][j].to<<' ';
			}
			cout<<endl;
		}*/
		printf("%d\n",maxFlow(0,f+2*n+d+1));
	}
	return 0;
}

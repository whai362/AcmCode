#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int n,T;

struct Edge{
	int to,cap,rev;
};
const int MAX_V=505,
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

int _abs(int x){
	if(x<0) return -x;
	else return x;
}
struct Data{
	int hei;
	char sex[105],mus[105],spo[105];
}d[505];
bool judge(Data d1,Data d2){
	if(_abs(d1.hei-d2.hei)<=40 && strcmp(d1.mus,d2.mus)==0 && strcmp(d1.spo,d2.spo)!=0)
		return true;
	return false;
}

void init(){
	for(int i=0;i<=n+1;++i){
		G[i].clear();
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		init();
		for(int i=0;i<n;++i){
			scanf("%d%s%s%s",&d[i].hei,d[i].sex,d[i].mus,d[i].spo);
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(strcmp(d[i].sex,"M")==0 && strcmp(d[j].sex,"F")==0 && judge(d[i],d[j])){
					addEdge(i+1,j+1,1);
				}
			}
		}
		for(int i=0;i<n;++i){
			if(strcmp(d[i].sex,"M")==0)
				addEdge(0,i+1,1);
			else
				addEdge(i+1,n+1,1);
		}
		printf("%d\n",n-maxFlow(0,n+1));
	}
	return 0;
}

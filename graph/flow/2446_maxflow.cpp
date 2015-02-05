#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

struct Edge{
	int to,cap,rev;
};
const int MAX_V=2005,
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

int m,n,k;
bool _map[35][35];
int id[35][35];
void init(){
	int cnt=1;
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			id[i][j]=cnt++;
		}
	}
	memset(_map,0,sizeof(_map));
	for(int i=0;i<=m*n+1;++i){
		G[i].clear();
	}
}
int dx[]={-1,1,0,0},
	dy[]={0,0,-1,1};
bool ok(int x,int y){
	if(x>=0 && x<m && y>=0 && y<n && _map[x][y]!=1)
		return true;
	return false;
}
int main(){
	while(~scanf("%d%d%d",&m,&n,&k)){
		init();
		int x,y;
		for(int i=0;i<k;++i){
			scanf("%d%d",&x,&y);
			_map[y-1][x-1]=1;
		}
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j){
				if(_map[i][j] == 1) continue;
				if((i + j + 1) & 1){
					addEdge(0,id[i][j],1);
					for(int k=0;k<4;++k){
						int tmpx=i+dx[k],
							tmpy=j+dy[k];
						if(ok(tmpx,tmpy)){
							addEdge(id[i][j],id[tmpx][tmpy],1);
						}
					}
				}
				else {
					addEdge(id[i][j],m*n+1,1);
				}
			}
		
		/*int cnt=1;
		  for(int i=0;i<4;++i){
		  for(int j=0;j<4;++j){
		  cout<<cnt++<<' ';
		  }
		  cout<<endl;
		  }
		  for(int i=0;i<1=m*n+1;++i){
		  cout<<i<<':';
		  for(int j=0;j<G[i].size();++j){
		  if(G[i][j].cap) cout<<G[i][j].to<<' ';
		  }
		  cout<<endl;
		  }*/
		//cout<<maxFlow(0,m*n+1)<<endl;
		if(2*maxFlow(0,m*n+1)==m*n-k) puts("YES");
		else puts("NO");
	}
	//cout<<maxFlow(0,m*n+1)<<endl;
	return 0;
}

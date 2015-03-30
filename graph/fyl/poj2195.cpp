#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define PB push_back
const int INF=0x3f3f3f3f;
const int MAX_V=205;
//终点，容量，费用，反向边
struct edge{ int to,cap,cost,rev; };
int V;	//顶点数
vector<edge> G[MAX_V];
int dist[MAX_V];	//最短距离
int prevv[MAX_V],preve[MAX_V];	//最短路中的前驱节点和对应的边
void add_edge(int fr,int to,int cap,int cost){
	G[fr].PB((edge){to,cap,cost,G[to].size()});
	G[to].PB((edge){fr,0,-cost,G[fr].size()-1});
}
//求解从s到t流量为f的最小费用流
//如果不能再增广则返回-1
int min_cost_flow(int s,int t,int f){
	int res=0;
	while(f>0){
		//利用bellman-ford求s到t的最短路
		fill(dist,dist+V,INF);
		dist[s]=0;
		bool update=true;
		while(update){
			update=false;
			for(int v=0;v<V;++v){
				if(dist[v]==INF) continue;
				for(int i=0;i<G[v].size();++i){
					edge &e=G[v][i];
					if(e.cap>0 && dist[e.to]>dist[v]+e.cost){
						dist[e.to]=dist[v]+e.cost;
						prevv[e.to]=v;
						preve[e.to]=i;
						update=true;
					}
				}
			}
		}
		//不能再增广
		if(dist[t]==INF) return -1;
		//沿s到t的最短路尽量增广
		int d=f;
		for(int v=t;v!=s;v=prevv[v]) d=min(d,G[prevv[v]][preve[v]].cap);
		f-=d;
		res+=d*dist[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}
const int N=105;
int px[N],py[N],hx[N],hy[N];
int cntp,cnth;
char str[N][N];
int abs(int x){
	if(x<0) return -x;
	return x;
}
int dis(int i,int j){
	return abs(px[i]-hx[j])+abs(py[i]-hy[j]);
}
void init(){
	cntp=0;
	cnth=0;
	for(int i=0;i<MAX_V;++i) G[i].clear();
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) && (n || m)){
		init();
		for(int i=0;i<n;++i)
			scanf("%s",str[i]);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				if(str[i][j]=='m'){
					px[cntp]=i;
					py[cntp]=j;
					++cntp;
				}
				else if(str[i][j]=='H'){
					hx[cnth]=i;
					hy[cnth]=j;
					++cnth;
				}
			}
		for(int i=0;i<cntp;++i){
			for(int j=0;j<cnth;++j){
				int u=i+1;
				int v=j+1+cntp;
				add_edge(u,v,1,dis(i,j));
			}
		}
		for(int i=0;i<cntp;++i){
			int u=i+1;
			int v=i+1+cntp;
			add_edge(0,u,1,0);
			add_edge(v,2*cntp+1,1,0);
		}
		V=cntp*2+2;
		int ans=min_cost_flow(0,2*cntp+1,cntp);
		printf("%d\n",ans);
	}
	return 0;
}

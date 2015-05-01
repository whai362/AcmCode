#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=105;
const int M=10005;
const double INF=1e30;
struct Edge{
	int u,v;
	double w;
	Edge(){}
	Edge(int _u,int _v,double _w){
		u=_u;
		v=_v;
		w=_w;
	}
}e[M];
int etot;
void addEdge(int u,int v,double w){
	e[etot++]=Edge(u,v,w);
}

double in[N];
int pre[N],mark[N],vis[N];
double gao(int rt,int n,int m){
	double ans=0;
	while(1){
		for(int i=0;i<n;++i) in[i]=INF;
		for(int i=0;i<m;++i){
			int u=e[i].u;
			int v=e[i].v;
			if(e[i].w < in[v] && u!=v){
				pre[v]=u;
				in[v]=e[i].w;
			}
		}
		for(int i=0;i<n;++i){
			if(i==rt) continue;
			if(in[i]==INF) return -1;
		}
		int cnt=0;
		memset(mark,-1,sizeof(mark));
		memset(vis,-1,sizeof(vis));
		in[rt]=0;
		for(int i=0;i<n;++i){
			ans+=in[i];
			int v=i;
			while(v!=rt && vis[v]!=i && mark[v]==-1){
				vis[v]=i;
				v=pre[v];
			}
			if(v!=rt && mark[v]==-1){
				for(int u=pre[v];u!=v;u=pre[u])
					mark[u]=cnt;
				mark[v]=cnt++;
			}
		}
		if(cnt==0) break;
		for(int i=0;i<n;++i)
			if(mark[i]==-1) mark[i]=cnt++;
		for(int i=0;i<m;++i){
			int u=e[i].u;
			int v=e[i].v;
			e[i].u=mark[u];
			e[i].v=mark[v];
			if(e[i].u!=e[i].v) e[i].w-=in[v];
		}
		n=cnt;
		rt=mark[rt];
	}
	return ans;
}
double x[N],y[N];
double sqr(double x){
	return x*x;
}
double dist(int u,int v){
	return sqrt(sqr(x[u]-x[v])+sqr(y[u]-y[v]));
}
void init(){
	etot=0;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&x[i],&y[i]);
		init();
		for(int i=0;i<m;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			--u,--v;
			if(u!=v){
				double d=dist(u,v);
				addEdge(u,v,d);
			}
			else addEdge(u,v,INF);
		}
		double ans=gao(0,n,m);
		if(ans==-1) puts("poor snoopy");
		else printf("%.2f\n",ans);
	}
	return 0;
}

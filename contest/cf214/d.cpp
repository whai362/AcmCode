/*Dijkstra邻接表实现*/
/*人口参数:n,m,src(起点),邻接表*/
/*出口参数:数组dis[],从起点src到各点的最短路*/
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
#define N 1005
#define M 10005
int head[N],dis[N];
int n,m,e;		//n保存点的总数,m保存边的总数,e保存现在边的数目
bool vis[N];
struct note{
	int u,v,a,b,next;
}p[M];
struct ab{
	int v,c;
	ab(){}
	ab(int v,int c):v(v),c(c){}
	bool operator < (const ab &other) const{
		return c>other.c;
	}
};
void addnote(int u,int v,int a,int b){
	p[e].v=v;
	p[e].a=a;
	p[e].b=b;
	p[e].next=head[u];		//链表尾置为-1
	head[u]=e++;
}
void init(){	//建立邻接表 
	int i,u,v,a,b;	//u起点,v终点,c权 
	memset(head,-1,sizeof(head));
	e=0;
	for(i=0;i<m;++i){
		scanf("%d%d%d%d",&u,&v,&a,&b);
		addnote(u,v,a,b);		//单向
		addnote(v,u,a,b);		//双向
	}
}
void dij(int src){
	int i,j;
	ab u;
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;++i) dis[i]=inf;
	dis[src]=0;
	priority_queue<ab> q;
	q.push(ab(src,dis[src]));
	for(i=0;i<n;++i){
		u=q.top();
		q.pop();
		vis[u.v]=1;
		for(j=head[u.v];j+1;j=p[j].next){
			if(!vis[p[j].v]&&dis[p[j].v]>dis[u.v]+p[j].c){
				dis[p[j].v]=dis[u.v]+p[j].c;
				q.push(ab(p[j].v,dis[p[j].v]));
			}
		}
		while(!q.empty()&&vis[q.top().v]) q.pop();
		if(q.empty()) break;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	dij(src);
	d=dis[2];	//从点src到点2的最短路 
	printf("%d\n",d);
	return 0;
}


/*spfa判断是否存在负环和求最短路*/
/*人口参数:n,m,src(起点),邻接表*/
/*出口参数:数组dis[],bool值(是否存在负环)*/
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
#define N 1005
#define M 200005
int head[N],dis[N],cnt[N];
int n,m1,m2,e;
bool vis[N];
struct note{
	int u,v,c,next;
}p[M];
void addnote(int u,int v,int c){
	p[e].v=v;
	p[e].c=c;
	p[e].next=head[u];
	head[u]=e++;
}
bool relax(int u,int v,int c){
	if(dis[v]>dis[u]+c){
		dis[v]=dis[u]+c;
		return 1;
	}
	return 0;
}
void init(){
	int i,u,v,c;
	//char str[5];
	e=0;
	memset(head,-1,sizeof(head));
	for(i=0;i<m1;++i){
		scanf("%d%d%d",&u,&v,&c);
		if(u<v)
			addnote(u,v,c);
		else
			addnote(v,u,c);
	}
	for(i=0;i<m2;++i){
		scanf("%d%d%d",&u,&v,&c);
		if(u>v)
			addnote(u,v,-c);
		else
			addnote(v,u,-c);
	}
}
bool spfa(int src){
	int i,pre;
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	for(i=0;i<=n;++i) dis[i]=inf;
	dis[src]=0,vis[src]=1;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		vis[pre]=0;
		for(i=head[pre];i+1;i=p[i].next){
			if(relax(pre,p[i].v,p[i].c)&&!vis[p[i].v]){
				if((++cnt[p[i].v])>n+1) return 0;
				q.push(p[i].v);
				vis[p[i].v]=1;
			}
		}	
	}
	return 1;
}
int main(){
	int i;
	scanf("%d%d%d",&n,&m1,&m2);
		init();
		//for(i=1;i<=n;++i) addnote(0,i,0);				
		if(spfa(1)){
			if(dis[n]==inf) printf("-2\n");
			else printf("%d\n",dis[n]);
		}
		else printf("-1\n");	//存在负环
	return 0;
}


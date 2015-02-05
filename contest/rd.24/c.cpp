/*floyd算法*/
/*人口参数m,n,邻接矩阵*/
/*出口参数p[st][en]*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define inf 10000
int m,n,vis[105],hash[105],p1[105][105],map[105][105];

int e,head[105];
struct edge{
	int v,c,next;	//v为终止点,c为边权,next为下个结点
}p[10005];
void addEdge(int u,int v,int c){
	p[e].v=v;
	p[e].c=c;
	p[e].next=head[u];		//链表尾置为-1
	head[u]=e++;
}

bool dfs(int root,int dis){
	int flag=0,i;
	if(root==n){
		if(dis==p1[1][n]){
			++hash[root];
			return 1;
		}
		else return 0;
	}
	for(i=head[root];i+1;i=p[i].next){
		if(p[i].c!=inf && !vis[p[i].v] && dis+p[i].c<=p1[1][n]){
			vis[root]=1;
			if(dfs(p[i].v,dis+p[i].c)){
				++hash[root];
				flag=1;
			}
			vis[root]=0;
		}
	}
	if(flag) return 1;
	return 0;
}
int main(){
	int i,j,k,Max=0,u,v,c,tmp;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){	//注意初始化的方式*/ 
		for(j=1;j<=n;++j) p1[i][j]=inf;
	}
	memset(head,-1,sizeof(head));
	e=0;
	for(i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		p1[u][v]=1;	//单向
		p1[v][u]=1;	//双向
		addEdge(u,v,1);		//单向
		addEdge(v,u,1);		//双向
	}
	for(k=1;k<=n;++k)
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j) p1[i][j]=min(p1[i][j],p1[i][k]+p1[k][j]);
	dfs(1,0);
	/*for(i=1;i<=n;++i)
	  cout<<hash[i]<<' ';
	cout<<endl;*/
	for(i=1;i<=n;++i){
		if(i==1 || i==n) tmp=hash[i];
		else tmp=2*hash[i];
		if(tmp>Max) Max=tmp;
	}
	printf("%lf\n",(Max+0.0)/hash[n]);
	return 0;
}


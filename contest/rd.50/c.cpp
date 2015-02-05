#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
#define N 100005
#define M 200005
int head[N];
int n,m,e;		//n保存点的总数,m保存边的总数,e保存现在边的数目
bool vis[N],ok[N];
struct note{
	int v,next;
}p[M];
void addnote(int u,int v){
	p[e].v=v;
	p[e].next=head[u];		//链表尾置为-1
	head[u]=e++;
}
void init(){	//建立邻接表 
	int i,u,v;	//u起点,v终点,c权 
	memset(head,-1,sizeof(head));
	e=0;
	for(i=0;i<2*n;++i){
		scanf("%d%d",&u,&v);
		addnote(u,v);		//单向
		if(u==1) ok[v]=1;
		addnote(v,u);
		if(v==1) ok[u]=1;
	}
}
bool Dfs(int root,int n){
	int i,j;
	if(n==1 && ok[root]){
		printf("1");
		return 1;
	}
	for(i=head[root];i+1;i=p[i].next){
		if(!vis[p[i].v]){
			vis[p[i].v]=1;
			if(Dfs(p[i].v,n-1)){
				printf(" %d",p[i].v);
				return 1;
			}
			vis[p[i].v]=0;
		}
	}
	return 0;
}
int main(){
	int d,src;
	scanf("%d",&n);
	init();
	vis[1]=1;
	if(Dfs(1,n))
	printf("\n");
	else printf("-1\n");
	return 0;
}


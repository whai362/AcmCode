#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 500
struct edge{
	int v,next;
}p[N];
int chk[N],head[N],map[N][N],match[N];
int n,m,e,res;

void addEdge(int u,int v){
	p[e].v=v;
	p[e].next=head[u];
	head[u]=e++;
}

int dfs(int src){
	int i,t1,t2,f1,f2;
	for(i=head[src];i+1;i=p[i].next){
		if(map[p[i].v][src] && !chk[p[i].v]){
			chk[p[i].v]=1;
			t1=match[p[i].v];
			t2=match[src];
			match[p[i].v]=src;
			match[src]=p[i].v;
			f1=dfs(t1);
			f2=dfs(t2);
			if((t1==0 && t2==0) || (t1==0 && f2) || (t2==0 && f1) || (f1 && f2)) return 1;
			match[p[i].v]=t1;
			match[src]=t2;
		}
	}
	return 0;
}


void pro(){
	int i;
	res=0;
	for(i=1;i<=n;++i){
		memset(chk,0,sizeof(chk));
		res=res+dfs(i);
	}
}
int main(){
	int a,b,i,j,tmp;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(match,0,sizeof(match));
		memset(head,-1,sizeof(head));
		e=0;
		for(i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			map[a][b]=map[b][a]=1;
			addEdge(a,b);
			addEdge(b,a);
		}
		pro();
		printf("%d\n",res);
	}
	return 0;
}


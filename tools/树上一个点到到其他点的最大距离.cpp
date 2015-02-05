/*题意：
  树是一种优美的数据结构，对于一个有N个节点的树，它恰好有N-1条边，每个点相互之间可达并且只有一条简单路径。
  现在你有两颗带权无根树A和B，我们想知道，如果在A树的u节点和B树的v节点之间连一条长度为w的边，形成的新树上任意两点之间的最大距离是多少。
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1e6+5;
struct Edge{
	int v,wei,pre;
	Edge(){}
	Edge(int a,int b,int c){v=a;pre=b;wei=c;}
}edge[N*2];

int head[2][N],tot,n1,n2;
int dx[N],dy[N],d1[N],d2[N];

void addEdge(int t,int u,int v,int wei){
	edge[tot]=Edge(v,head[t][u],wei);
	head[t][u]=tot++;
}
void dfs(int t,int u,int fa,int dis,int *d){
	for(int i=head[t][u];i!=-1;i=edge[i].pre){
		int v=edge[i].v,wei=edge[i].wei;
		if(v!=fa) dfs(t,v,u,d[v]=dis+wei,d);
	}
}

int main(){
	while(scanf("%d%d",&n1,&n2)!=EOF){
		tot=0;
		memset(head,-1,sizeof(head));

		int i,u,v,w,x,y;
		for(int i=2;i<=n1;++i){
			scanf("%d%d%d",&u,&v,&w);
			addEdge(0,u,v,w);
			addEdge(0,v,u,w);
		}
		dfs(0,1,0,d1[1]=0,d1);
		for(x=1,i=2;i<=n1;++i)
			if(d1[i]>d1[x]) x=i;
		dfs(0,x,0,dx[x]=0,dx);
		for(y=1,i=2;i<=n1;++i)
			if(dx[i]>dx[y]) y=i;
		dfs(0,y,0,dy[y]=0,dy);
		
		int _max1=0,_max2=0;
		for(int i=1;i<=n1;++i){
			d1[i]=max(dx[i],dy[i]);
			_max1=max(_max1,d1[i]);
			//cout<<i<<' '<<d1[i]<<endl;
		}

		for(i=2;i<=n2;++i){
			scanf("%d%d%d",&u,&v,&w);
			addEdge(1,u,v,w);
			addEdge(1,v,u,w);
		}
		dfs(1,1,0,d2[1]=0,d2);
		for(x=1,i=2;i<=n2;++i)
			if(d2[i]>d2[x]) x=i;
		dfs(1,x,0,dx[x]=0,dx);
		for(y=1,i=2;i<=n2;++i)
			if(dx[i]>dx[y]) y=i;
		dfs(1,y,0,dy[y]=0,dy);

		for(i=1;i<=n2;++i){
			d2[i]=max(dx[i],dy[i]);
			_max2=max(_max2,d2[i]);
			//cout<<i<<' '<<d2[i]<<endl;
		}
		int q;
		scanf("%d",&q);
		for(i=0;i<q;++i){
			scanf("%d%d%d",&u,&v,&w);
			int tmp=d1[u]+d2[v]+w;
			printf("%d\n",max(tmp,max(_max1,_max2)));
		}
	}
	return 0;
}

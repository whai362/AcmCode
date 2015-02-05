#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#define LL long long
#define Maxn 105000
#define Maxm 205000
using namespace std;
struct Edge {
	int to, next;
} edge[Maxm * 2];
int en, head[Maxn];
inline void add_edge(int u, int v) {
	edge[en].to = v, edge[en].next = head[u], head[u] = en++;
}
int nex[Maxn],u[Maxm],v[Maxm];
bool ff[Maxn];
int top;
int n,m,k;
int fa[Maxn];
int getfather(int x){
	if (x!=fa[x]) return fa[x]=getfather(fa[x]);
	return fa[x];
}
int main(){
	int cases;
	int x,uu,vv;
	scanf("%d",&cases);
	for (int cas=1;cas<=cases;cas++){
		en=0;
		memset(head,-1,sizeof(head));
		scanf("%d%d%d",&n,&m,&k);
		memset(ff,false,sizeof(false));
		for (int i=1;i<=k;i++){
			scanf("%d",&x);
			ff[x]=true;
		}
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u[i],&v[i]);
			add_edge(u[i],v[i]);
			add_edge(v[i],u[i]);
			if (!ff[u[i]]&&!ff[v[i]]){
				uu=getfather(u[i]);vv=getfather(v[i]);
				fa[vv]=uu;
			}
		}
		int x,y;
		scanf("%d",&top);
		scanf("%d",&y);
		for (int p=head[y];p!=-1;p=edge[p].next){
			if(!ff[edge[p].to]){
				uu=getfather(y);vv=getfather(edge[p].to);
				//cout<<edge[p].to<<' ';
				fa[vv]=uu;
			}
		}
		ff[y]=0;
		//cout<<endl;
		bool flag=true;
		for (int i=2;i<=top;i++){
			scanf("%d",&x);
			for (int p=head[x];p!=-1;p=edge[p].next){
				if(!ff[edge[p].to]){
					uu=getfather(x);vv=getfather(edge[p].to);
					fa[vv]=uu;
				}
			}
			ff[x]=0;
			if (getfather(x)!=getfather(y)){
				flag=false;
			}
		}
		int rt=getfather(1);
		for (int i=1;i<=n;i++){
			if (getfather(i)!=rt) flag=false;
		}
		if (top==k && flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}


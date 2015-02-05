/*Dijkstra邻接表实现*/
/*人口参数:n,m,src(起点),邻接表*/
/*出口参数:数组dis[],从起点src到各点的最短路*/
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 10007
#define N 50005
#define M 100005
int head[N],dis[N],hash[N];
int ans[N];
int n,m,e;		//n保存点的总数,m保存边的总数,e保存现在边的数目
bool vis[N];
struct note{
	int u,v,c,next;
}p[M];
struct ab{
	int v,c;
	ab(){}
	ab(int v,int c):v(v),c(c){}
	bool operator < (const ab &other) const{
		return c>other.c;
	}
};
void addnote(int u,int v,int c){
	p[e].v=v;
	p[e].c=c;
	p[e].next=head[u];		//链表尾置为-1
	head[u]=e++;
}
void init(){	//建立邻接表 
	int i,u,v,c;	//u起点,v终点,c权 
	memset(head,-1,sizeof(head));
	memset(hash,0,sizeof(hash));
	e=0;
	for(i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		++hash[u],++hash[v];
		addnote(u,v,1);		//单向
		addnote(v,u,1);		//双向
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

int a_b_Mod_c(int a, int b, int c){
    int result = 1;
    int digit[32];
    int i,k;
    i=0;
    while(b){
        digit[i++]=b%2;
        b>>=1;
    }
    for(k=i-1; k >= 0; k--)
    {
        result = (result * result) % c;
        if(digit[k] == 1)
        {
            result=(result*a) % c;
        }
    }
    return result;
}

int main(){
	int i,j,k,src,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(n==1){ printf("%d\n",0); continue; }
		memset(ans,0,sizeof(ans));
		for(i=1;i<=n-1;++i) ans[0]=(ans[0]+a_b_Mod_c(i,k,mod))%mod;
		ans[0]=ans[0]%mod;
		ans[n-1]=ans[0];
		for(i=1,j=n-1;i<n/2;++i,--j){
			ans[i]=(ans[i-1]+a_b_Mod_c(i,k,mod)-a_b_Mod_c(j,k,mod))%mod;
			ans[i]=ans[i]%mod;
			ans[n-1-i]=ans[i];
		}
		if(n%2==1){
			ans[i]=(ans[i-1]+a_b_Mod_c(i,k,mod)-a_b_Mod_c(j,k,mod))%mod;
			ans[i]=ans[i]%mod;
		}
		m=n-1;
		init();
		for(i=0;i<n;++i) if(hash[i]==1){ src=i; break; }
		dij(src);
		for(i=1;i<=n;++i) printf("%d\n",ans[dis[i]]);
	}
	return 0;
}


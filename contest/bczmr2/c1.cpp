#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=100000+10;
struct Edge
{
    int u,v,next;
};
Edge edges[maxn<<1];
int head[maxn],nEdge;
int n,m;
int color[maxn],degree[maxn];
ll a[700][700],sum[700][2];
ll res[3];
int hash[maxn],spnt;
void AddEdge(int u,int v,int w)
{
    nEdge++;
    edges[nEdge].u=u;
    edges[nEdge].v=v;
    edges[nEdge].w=w;
    edges[nEdge].next=head[u];
    head[u]=nEdge;
}
void Init()
{
    memset(head,0xff,sizeof(head));
    memset(degree,0,sizeof(degree));
    memset(hash,0,sizeof(hash));
    memset(res,0,sizeof(res));
    nEdge=-1;spnt=0;
}
void precal()
{
    int lim=(int)sqrt((double)m);
    for(int i=1;i<=n;++i)
    {
        if(degree[i]>lim)
        {
            spnt++;
            hash[i]=spnt;
        }
    }
    memset(a,0,sizeof(a));
    memset(sum,0,sizeof(sum));
    int u,v;
    for(int i=0;i<nEdge;i+=2)
    {
        u=edges[i].u;v=edges[i].v;
        if(color[u]^color[v])
          res[2]+=edges[i].w;
        else if(color[u])
          res[1]+=edges[i].w;
        else res[0]+=edges[i].w;
        if(hash[u]&&hash[v])
        {
            a[hash[u]][hash[v]]+=edges[i].w;
            a[hash[v]][hash[u]]+=edges[i].w;
        }
        if(hash[u]) sum[hash[u]][color[v]]+=edges[i].w;
        if(hash[v]) sum[hash[v]][color[u]]+=edges[i].w;
    }
}
void change(int x)
{
    if(hash[x])
    {
        if(color[x])
        {
            res[0]+=sum[hash[x]][0];
            res[2]+=sum[hash[x]][1];
            res[2]-=sum[hash[x]][0];
            res[1]-=sum[hash[x]][1];
        }
        else
        {
            res[1]+=sum[hash[x]][1];
            res[2]+=sum[hash[x]][0];
            res[2]-=sum[hash[x]][1];
            res[0]-=sum[hash[x]][0];
        }
        for(int i=1;i<=spnt;++i)
        {
            if(i==hash[x]) continue;
            sum[i][color[x]]-=a[i][hash[x]];
            sum[i][color[x]^1]+=a[i][hash[x]];
        }
        color[x]^=1;
    }
    else
    {
        int v;
        for(int k=head[x];k!=-1;k=edges[k].next)
        {
            v=edges[k].v;
            if(color[x])
            {
                if(color[v]) res[2]+=edges[k].w,res[1]-=edges[k].w;
                else res[0]+=edges[k].w,res[2]-=edges[k].w;
            }
            else
            {
                if(color[v]) res[1]+=edges[k].w,res[2]-=edges[k].w;
                else res[2]+=edges[k].w,res[0]-=edges[k].w;
            }
            if(hash[v])
            {
                sum[hash[v]][color[x]]-=edges[k].w;
                sum[hash[v]][color[x]^1]+=edges[k].w;
            }
        }
        color[x]^=1;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tcase=0;
    int q;
	int op;
    map<ll,int>mp;
    while(~scanf("%d%d",&n,&m))
    {
        tcase++;
        Init();
        mp.clear();
        for(int i=1;i<=n;++i)
          scanf("%d",&color[i]);
        int u,v,w,id;
        ll tmp;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(u>v) swap(u,v);
            tmp=(ll)u*100000+v;
            if(!mp[tmp])
            {
                degree[u]++;degree[v]++;
                AddEdge(u,v,w);
                AddEdge(v,u,w);
                mp[tmp]=nEdge;
            }
            else
            {
                id=mp[tmp];
                edges[id].w+=w;
                edges[id^1].w+=w;
            }
        }
        precal();
        printf("Case %d:\n",tcase);
        scanf("%d",&q);
        int a,b;
        while(q--)
        {
			scanf("%d",&op);
            if(op==3)
            {
                printf("%I64d\n",res[2]);
            }
            else if(op==1)
            {
                scanf("%d",&a);
                change(a);
            }
			else{
				
			}
        }
    }
    return 0;
}

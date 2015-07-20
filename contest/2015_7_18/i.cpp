#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;
#define nNode 100005
#define nEdge 400005

struct node
{
    int id;
    int color;
    int next;
}edge[nEdge];

struct state
{
    int id;
    int color;
};

int map[nNode];
int n,m,len;
int level[nNode],path[nNode],mmin[nNode];

void addEdge(int u,int v,int c)
{
    edge[len].id=v;
    edge[len].color=c;
    edge[len].next=map[u];
    map[u]=len++;
}

void bfs()
{
    int i,t;
    queue<int> q;
    memset(level,0,sizeof(level));
    q.push(n);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(i=map[t];i!=-1;i=edge[i].next)
        {
            if(level[edge[i].id]==0 && edge[i].id!=n)
            {
                level[edge[i].id]=level[t]+1;
                q.push(edge[i].id);
            }
        }
    }
}

void dijkstra()
{
    int i,k;
    state t,tmp;
    memset(path,127,sizeof(path));
    memset(mmin,127,sizeof(mmin));
    queue<state> q;
    t.id=1;
    t.color=0;
    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        k=level[t.id];
        if(t.color>path[k])
            continue;
        for(i=map[t.id];i!=-1;i=edge[i].next)
        {
            tmp.id=edge[i].id;
            tmp.color=edge[i].color;
            if(level[tmp.id]==k-1 && tmp.color<=path[k-1])
            {
                path[k-1]=tmp.color;
                if(tmp.color<mmin[tmp.id])
                {
                    mmin[tmp.id]=tmp.color;
                    q.push(tmp);
                }
            }
        }
    }
}

int main()
{
    int t,i,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        memset(map,-1,sizeof(map));	//
        len=0;	//
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        bfs();
		for(int ii=1;ii<=n;++ii){
			cout<<level[ii]<<' ';
		}
		cout<<endl;
        dijkstra();
        printf("%d\n",level[1]);
        for(i=level[1]-1;i>0;i--)
            printf("%d ",path[i]);
        printf("%d\n",path[i]);
    }
    return 0;
}

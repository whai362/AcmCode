#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

const int MAXN = 30010;
struct Edge
{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN]; //top[v] 表示v所在的重链的顶端节点
int fa[MAXN]; //父亲节点
int deep[MAXN];//深度
int num[MAXN]; //num[v]表示以v为根的子树的节点数
int p[MAXN]; //p[v]表示v在线段树中的位置
int fp[MAXN];//和p数组相反
int son[MAXN];//重儿子
int pos;
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 0;
    memset(son,-1,sizeof(son));
}
void addedge(int u,int v)
{
    edge[tot].to = v; edge[tot].next = head[u]; head[u] = tot++;
}
void dfs1(int u,int pre,int d) //第一遍dfs求出fa,deep,num,son
{
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != pre)
        {
            dfs1(v,u,d+1);
            num[u] += num[v];
            if(son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}
void getpos(int u,int sp)
{
    top[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if(son[u] == -1) return;
    getpos(son[u],sp);
    for(int i = head[u]; i != -1 ; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u]) getpos(v,v);
    }
}

struct Node
{
    int l,r;
    int sum;
	int ne;
    //int Max;
}segTree[MAXN*3];
void push_up(int i)
{
    segTree[i].sum = segTree[i<<1].sum + segTree[(i<<1)|1].sum;
    //segTree[i].Max = max(segTree[i<<1].Max,segTree[(i<<1)|1].Max);
} 
int s[MAXN];
void build(int i,int l,int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
	segTree[i].ne=0;
    if(l == r)
    {
        segTree[i].sum = s[fp[l]];
        return ;
    }
    int mid = (l + r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
    push_up(i);
}
void push_down(int i)
{
    if(segTree[i].l == segTree[i].r)return;
    if(segTree[i].ne)
    {
		segTree[i<<1].sum=-segTree[i<<1].sum;
		segTree[i<<1|1].sum=-segTree[i<<1|1].sum;
        segTree[i<<1].ne ^= 1;
        segTree[(i<<1)|1].ne ^= 1;
        segTree[i].ne = 0;
    }
}
void ne_update(int i,int l,int r) // 更新线段树的区间[l,r]取反
{
    if(segTree[i].l == l && segTree[i].r == r)
    {
		segTree[i].sum=-segTree[i].sum;
        segTree[i].ne ^= 1;
        return;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)ne_update(i<<1,l,r);
    else if(l > mid) ne_update((i<<1)|1,l,r);
    else
    {
        ne_update(i<<1,l,mid);
        ne_update((i<<1)|1,mid+1,r);
    }
    push_up(i);
}
void Negate(int u,int v)//把u-v路径上的边的值都设置为val
{
    int f1 = top[u], f2 = top[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        ne_update(1,p[f1],p[u]);
        u = fa[f1]; f1 = top[u];
    }
    if(u == v)return;
    if(deep[u] > deep[v]) swap(u,v);
    return ne_update(1,p[son[u]],p[v]);
}
int querySum(int i,int l,int r) //查询线段树[l,r]区间的和
{
    if(segTree[i].l == l && segTree[i].r == r)
        return segTree[i].sum;
	push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)return querySum(i<<1,l,r);
    else if(l > mid)return querySum((i<<1)|1,l,r);
    else return querySum(i<<1,l,mid) + querySum((i<<1)|1,mid+1,r);
}
int findSum(int u,int v) //查询u->v路径上节点的权值的和
{
    int f1 = top[u], f2 = top[v];
    int tmp = 0;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        tmp += querySum(1,p[f1],p[u]);
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u,v);
    return tmp + querySum(1,p[u],p[v]);
}
int main() 
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    int q;
    int op,u,v;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        init();
		for(int i = 1;i <= n;i++)
            scanf("%d",&s[i]);
        for(int i = 1;i < n;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,0,0);
        getpos(1,1);
        build(1,0,pos-1);
        while(q--)
        {
            scanf("%d%d%d",&op,&u,&v);
            if(op == 1)
                Negate(u,v);//修改单点的值
            else printf("%d\n",findSum(u,v));//查询路径上点权的和
        }
    }
    return 0;
}

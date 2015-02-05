/* ***********************************************
Author        :kuangbin
Created Time  :2013/8/17 4:04:42
File Name     :F:\2013ACM练习\专题学习\数链剖分\POJ3237Tree.cpp
************************************************ */

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
#include <time.h>
using namespace std;

const int MAXN = 100010;
struct Edge
{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN];//top[v]表示v所在的重链的顶端节点
int fa[MAXN]; //父亲节点
int deep[MAXN];//深度
int num[MAXN];//num[v]表示以v为根的子树的节点数
int p[MAXN];//p[v]表示v与其父亲节点的连边在线段树中的位置
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
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
void dfs1(int u,int pre,int d) //第一遍dfs求出fa,deep,num,son
{
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i = head[u];i != -1; i = edge[i].next)
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
void getpos(int u,int sp) //第二遍dfs求出top和p
{
    top[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if(son[u] == -1) return;
    getpos(son[u],sp);
    for(int i = head[u] ; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])
            getpos(v,v);
    }
}

//线段树
struct Node
{
    int l,r;
    int Max;
    int Min;
    int ne;
}segTree[MAXN*3];
void build(int i,int l,int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
    segTree[i].Max = 0;
    segTree[i].Min = 0;
    segTree[i].ne = 0;
    if(l == r)return;
    int mid = (l+r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
}
void push_up(int i)
{
    segTree[i].Max = max(segTree[i<<1].Max,segTree[(i<<1)|1].Max);
    segTree[i].Min = min(segTree[i<<1].Min,segTree[(i<<1)|1].Min);
}
void push_down(int i)
{
    if(segTree[i].l == segTree[i].r)return;
    if(segTree[i].ne)
    {
        segTree[i<<1].Max = -segTree[i<<1].Max;
        segTree[i<<1].Min = -segTree[i<<1].Min;
        swap(segTree[i<<1].Min,segTree[i<<1].Max);
        segTree[(i<<1)|1].Max = -segTree[(i<<1)|1].Max;
        segTree[(i<<1)|1].Min = -segTree[(i<<1)|1].Min;
        swap(segTree[(i<<1)|1].Max,segTree[(i<<1)|1].Min);
        segTree[i<<1].ne ^= 1;
        segTree[(i<<1)|1].ne ^= 1;
        segTree[i].ne = 0;
    }
}
void update(int i,int k,int val) // 更新线段树的第k个值为val
{
    if(segTree[i].l == k && segTree[i].r == k)
    {
        segTree[i].Max = val;
        segTree[i].Min = val;
        segTree[i].ne = 0;
        return;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(k <= mid)update(i<<1,k,val);
    else update((i<<1)|1,k,val);
    push_up(i);
}
void ne_update(int i,int l,int r) // 更新线段树的区间[l,r]取反
{
    if(segTree[i].l == l && segTree[i].r == r)
    {
        segTree[i].Max = -segTree[i].Max;
        segTree[i].Min = -segTree[i].Min;
        swap(segTree[i].Max,segTree[i].Min);
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
int query(int i,int l,int r)  //查询线段树中[l,r] 的最大值
{
    if(segTree[i].l == l && segTree[i].r == r)
        return segTree[i].Max;
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)return query(i<<1,l,r);
    else if(l > mid)return query((i<<1)|1,l,r);
    else return max(query(i<<1,l,mid),query((i<<1)|1,mid+1,r));
    push_up(i);
}
int findmax(int u,int v)//查询u->v边的最大值
{
    int f1 = top[u], f2 = top[v];
    int tmp = -100000000;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        tmp = max(tmp,query(1,p[f1],p[u]));
        u = fa[f1]; f1 = top[u];
    }
    if(u == v)return tmp;
    if(deep[u] > deep[v]) swap(u,v);
    return max(tmp,query(1,p[son[u]],p[v]));
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
int e[MAXN][3];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        for(int i = 0;i < n-1;i++)
        {
            scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
            addedge(e[i][0],e[i][1]);
            addedge(e[i][1],e[i][0]);
        }
        dfs1(1,0,0);
        getpos(1,1);
        build(1,0,pos-1);
        for(int i = 0;i < n-1; i++)
        {
            if(deep[e[i][0]] > deep[e[i][1]])
                swap(e[i][0],e[i][1]);
            update(1,p[e[i][1]],e[i][2]);
        }
        char op[10];
        int u,v;
        while(scanf("%s",op) == 1)
        {
            if(op[0] == 'D')break;
            scanf("%d%d",&u,&v);
            if(op[0] == 'Q')
                printf("%d\n",findmax(u,v));//查询u->v路径上边权的最大值
            else if(op[0] == 'C')
                update(1,p[e[u-1][1]],v);//改变第u条边的值为v
            else Negate(u,v);
        }
    }
    return 0;
}

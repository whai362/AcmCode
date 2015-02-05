#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAXN 50010
#define L(u) (u<<1)
#define R(u) (u<<1|1)

//写在类里面爆栈
int n, m, q;
int tim;       //时间戳
int num[MAXN]; //树上每个节点的初始值
int siz[MAXN]; //siz[u]表示以u为根的子树的节点数
int top[MAXN]; //树链上深度最小的点
int son[MAXN]; //重儿子
int dep[MAXN]; //深度
int tid[MAXN]; //节点的时间戳
int _tid[MAXN]; //tid[i]=j表示时间戳为i的节点是j
int father[MAXN]; //父节点
bool vis[MAXN];
vector<int> edge[MAXN];

void init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		siz[i] = top[i] = son[i] = 0;
		dep[i] = tid[i] = _tid[i] = father[i] = 0;
		vis[i] = false;
		tim = 0; //时间戳
		edge[i].clear();
	}
}

void addedge(int u, int v) //无根树加双向边
{
	edge[u].push_back(v);
	edge[v].push_back(u);
}

//树链剖分
void dfs1(int u, int pre)
{
	vis[u] = true;
	siz[u] = 1;
	father[u] = pre;
	dep[u] = dep[pre] + 1; //注意根节点比较特殊
	int sz = edge[u].size();
	for(int i = 0; i < sz; i++)
	{
		int v = edge[u][i];
		if(v != father[u] && vis[v] == false)
		{
			dfs1(v, u);
			siz[u] += siz[v];
			if(son[u] == 0) son[u] = v;
			else if(siz[son[u]] < siz[v]) son[u] = v;
		}
	}
}

void dfs2(int u, int tp)
{
	vis[u] = true;
	tid[u] = ++tim;
	_tid[tim] = u;
	top[u] = tp;
	if(son[u] != 0)
		dfs2(son[u], tp); //同一条重链的顶部相同

	int sz = edge[u].size();
	for(int i = 0; i < sz; i++)
	{
		int v = edge[u][i];
		if(v != father[u] && v != son[u] && vis[v] == false) //注意去掉重儿子
			dfs2(v, v);
	}
}

void update(int u, int l, int r, int v); //线段树的更新函数

void change(int x, int y, int val)
{
	while(top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		update(1, tid[top[x]], tid[x], val); //dfs2时顶部先访问，故tid[top]较小
		x = father[top[x]]; //因为top[x]->x路径上的所有点已经被更新了
	}

	if(dep[x] > dep[y]) //同一条重链上深度小的tid小
		swap(x, y);
	update(1, tid[x], tid[y], val);
}


//线段树部分
struct NODE {
	int l, r, val, lazy;
}node[MAXN*4];

void build(int u, int l, int r)
{
	node[u].l = l;
	node[u].r = r;
	node[u].lazy = node[u].val = 0;
	if(l == r)
	{
		node[u].val = num[_tid[l]];
		return;
	}

	int mid = (l + r) >> 1;
	build(L(u), l, mid);
	build(R(u), mid + 1, r);
}

void pushdown(int u)
{
	if(node[u].lazy != 0)
	{
		node[L(u)].val += node[u].lazy;
		node[R(u)].val += node[u].lazy;
		node[L(u)].lazy += node[u].lazy;
		node[R(u)].lazy += node[u].lazy;
		node[u].lazy = 0;
	}
}

void update(int u, int l, int r, int v)
{
	if(node[u].l == l && node[u].r == r)
	{
		node[u].val += v;
		node[u].lazy += v;
		return;
	}
	pushdown(u);
	int mid = (node[u].l + node[u].r) >> 1;
	if(r <= mid)
		update(L(u), l, r, v);
	else if(l > mid)
		update(R(u), l, r, v);
	else
	{
		update(L(u), l, mid, v);
		update(R(u), mid + 1, r, v);
	}
}

int query(int u, int x)
{
	if(node[u].l == x && node[u].r == x)
		return node[u].val;

	pushdown(u);
	int mid = (node[u].l + node[u].r) >> 1;
	if(x <= mid) return query(L(u), x);
	else return query(R(u), x);
}

const int MAXN1 = 100010;
struct Edge
{
    int to,next;
}edge1[MAXN1*2];
int head[MAXN1],tot;
int top1[MAXN1];//top1[v]表示v所在的重链的顶端节点
int fa[MAXN1]; //父亲节点
int deep[MAXN1];//深度
int num1[MAXN1];//num1[v]表示以v为根的子树的节点数
int p[MAXN1];//p[v]表示v与其父亲节点的连边在线段树中的位置
int fp[MAXN1];//和p数组相反
int son1[MAXN1];//重儿子
int pos;
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 0;
    memset(son1,-1,sizeof(son1));
}
void addedge1(int u,int v)
{
    edge1[tot].to = v;edge1[tot].next = head[u];head[u] = tot++;
}
void dfs11(int u,int pre,int d) //第一遍dfs求出fa,deep,num,son
{
    deep[u] = d;
    fa[u] = pre;
    num1[u] = 1;
    for(int i = head[u];i != -1; i = edge1[i].next)
    {
        int v = edge1[i].to;
        if(v != pre)
        {
            dfs11(v,u,d+1);
            num1[u] += num1[v];
            if(son1[u] == -1 || num1[v] > num1[son1[u]])
                son1[u] = v;
        }
    }
}
void getpos(int u,int sp) //第二遍dfs求出top1和p
{
    top1[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if(son1[u] == -1) return;
    getpos(son1[u],sp);
    for(int i = head[u] ; i != -1; i = edge1[i].next)
    {
        int v = edge1[i].to;
        if(v != son1[u] && v != fa[u])
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
	int sum;
}segTree[MAXN*3];
void build1(int i,int l,int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
    segTree[i].Max = 0;
    segTree[i].Min = 0;
    segTree[i].ne = 0;
	segTree[i].sum = 0;
    if(l == r)return;
    int mid = (l+r)/2;
    build1(i<<1,l,mid);
    build1((i<<1)|1,mid+1,r);
}
void push_up(int i)
{
    //segTree[i].Max = max(segTree[i<<1].Max,segTree[(i<<1)|1].Max);
    //segTree[i].Min = min(segTree[i<<1].Min,segTree[(i<<1)|1].Min);
}
void push_down(int i,int add)
{
    if(segTree[i].l == segTree[i].r)return;
    if(segTree[i].ne)
    {
        /*segTree[i<<1].Max = -segTree[i<<1].Max;
        segTree[i<<1].Min = -segTree[i<<1].Min;
        swap(segTree[i<<1].Min,segTree[i<<1].Max);
        segTree[(i<<1)|1].Max = -segTree[(i<<1)|1].Max;
        segTree[(i<<1)|1].Min = -segTree[(i<<1)|1].Min;
        swap(segTree[(i<<1)|1].Max,segTree[(i<<1)|1].Min)*/

        segTree[i<<1].ne += add;
        segTree[(i<<1)|1].ne += add;
        segTree[i].ne = 0;
    }
}
/*void update1(int i,int k,int val) // 更新线段树的第k个值为val
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
    if(k <= mid)update1(i<<1,k,val);
    else update1((i<<1)|1,k,val);
    push_up(i);
}*/
void ne_update(int i,int l,int r,int add) // 更新线段树的区间[l,r]取反
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
int query1(int i,int l,int r)  //查询线段树中[l,r] 的最大值
{
    if(segTree[i].l == l && segTree[i].r == r)
        return segTree[i].Max;
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)/2;
    if(r <= mid)return query1(i<<1,l,r);
    else if(l > mid)return query1((i<<1)|1,l,r);
    else return max(query1(i<<1,l,mid),query1((i<<1)|1,mid+1,r));
    push_up(i);
}
int findmax(int u,int v)//查询u->v边的最大值
{
    int f1 = top1[u], f2 = top1[v];
    int tmp = -100000000;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        tmp = max(tmp,query1(1,p[f1],p[u]));
        u = fa[f1]; f1 = top1[u];
    }
    if(u == v)return tmp;
    if(deep[u] > deep[v]) swap(u,v);
    return max(tmp,query1(1,p[son1[u]],p[v]));
}
void Negate(int u,int v)//把u-v路径上的边的值都设置为val
{
    int f1 = top1[u], f2 = top1[v];
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        ne_update(1,p[f1],p[u]);
        u = fa[f1]; f1 = top1[u];
    }
    if(u == v)return;
    if(deep[u] > deep[v]) swap(u,v);
    return ne_update(1,p[son1[u]],p[v]);
}
int e[MAXN][3];
/*int main()
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
        dfs11(1,0,0);
        getpos(1,1);
        build1(1,0,pos-1);
        for(int i = 0;i < n-1; i++)
        {
            if(deep[e[i][0]] > deep[e[i][1]])
                swap(e[i][0],e[i][1]);
            update1(1,p[e[i][1]],e[i][2]);
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
}*/

int main()
{
	char oper[5];
	int a, b, c;
	while(scanf("%d%d",&n,&q) != EOF)
	{
		init(n);
		m=n-1;
		/*for(int i = 1; i <= n; i++)
			scanf("%d", &num[i]);*/

		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d",&a, &b);
			addedge(a, b);
			e[i][0]=a;
			e[i][1]=b;
			e[i][2]=0;
			addedge1(e[i][0],e[i][1]);
            addedge1(e[i][1],e[i][0]);
		}

		dfs1(1, 0);
		memset(vis, 0, sizeof(vis));
		dfs2(1, 1);
		build(1, 1, n);

		dfs11(1,0,0);
        getpos(1,1);
        build1(1,0,pos-1);

		for(int i = 0;i < n-1; i++)
        {
            if(deep[e[i][0]] > deep[e[i][1]])
                swap(e[i][0],e[i][1]);
            update1(1,p[e[i][1]],e[i][2]);
        }

		while(q--)
		{
			scanf("%s", oper);
			
			scanf("%d%d%d", &a, &b, &c);
			if(oper[3] == '1')
				change(a, b, c);
		}
		for(int i=1;i<=n;++i){
			cout<<query(1,i)<<endl;
		}
	}
	return 0;
}


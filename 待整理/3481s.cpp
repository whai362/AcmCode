#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2000009
#define lch(rt) son[rt][0]
#define rch(rt) son[rt][1]
using namespace std;

int son[maxn][2],fa[maxn],size[maxn],val[maxn],st[maxn];
int gcd[maxn][2],root,cnt;
int num[maxn*2],fst[maxn*2];

int get_gcd(int a,int b)
{
    if(a==-1)return b;
    if(b==-1)return a;
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

void newnode(int &rt,int father,int v,int state)
{
    rt=++cnt;
    son[rt][0]=son[rt][1]=0;
    size[rt]=1;
    val[rt]=v;
    fa[rt]=father;
    gcd[rt][state]=v,gcd[rt][state^1]=-1;//attention;
    st[rt]=state;
}

void maintain(int rt)
{
    size[rt]=size[son[rt][0]]+size[son[rt][1]]+1;
    gcd[rt][0]=get_gcd(gcd[lch(rt)][0],gcd[rch(rt)][0]);
    gcd[rt][1]=get_gcd(gcd[lch(rt)][1],gcd[rch(rt)][1]);
    gcd[rt][st[rt]]=get_gcd(gcd[rt][st[rt]],val[rt]);
}

void rotate(int x,int kind)
{
    int y=fa[x];
    son[y][kind^1]=son[x][kind];
    fa[son[x][kind]]=y;
    if(fa[y])
        son[fa[y]][son[fa[y]][1]==y]=x;
    fa[x]=fa[y];
    son[x][kind]=y;
    fa[y]=x;
    maintain(y);
}

void splay(int rt,int goal)
{
    while(fa[rt]!=goal)
    {
        int y=fa[rt];
        if(fa[y]==goal)
            rotate(rt,son[y][0]==rt);
        else
        {
            int kind=son[fa[y]][0]==y;
            if(son[y][kind]==rt)
            {
                rotate(rt,kind^1);
                rotate(rt,kind);
            }
            else
            {
                rotate(y,kind);
                rotate(rt,kind);
            }
        }
    }
    maintain(rt);
    if(goal==0) root=rt;
}

void rotateto(int k,int goal)//把第k个点旋转到目标位置；
{
    int rt=root;
    while(size[lch(rt)]!=k)
    {
        if(size[lch(rt)]>k)
            rt=lch(rt);
        else
        {
            k-=(size[lch(rt)]+1);
            rt=rch(rt);
        }
    }
    splay(rt,goal);
}

void build(int l,int r,int &rt,int father)
{
    if(l>r) return ;
    int m=(l+r)>>1;
    newnode(rt,father,num[m],fst[m]);
    build(l,m-1,lch(rt),rt);
    build(m+1,r,rch(rt),rt);
    maintain(rt);
}

int query(int L,int R,int state)
{
    rotateto(L-1,0);
    rotateto(R+1,root);
    return gcd[lch(rch(root))][state];
}

void insert(int pos,int v,int state)//前端插入
{
    rotateto(pos,0);
    if(lch(root)==0)
    {
        newnode(lch(root),root,v,state);
        maintain(root);
        return ;
    }
    int rc=lch(root);
    while(rch(rc))
        rc=rch(rc);
    splay(rc,root);
    newnode(rch(rc),rc,v,state);
    maintain(rc);
    maintain(root);
}

void del(int pos)
{
    rotateto(pos,0);
    if(lch(root)==0)
    {
        root=rch(root);
        fa[root]=0;
        return ;
    }
    int rc=lch(root);
    while(rch(rc)) rc=rch(rc);
    splay(rc,root);
    int rt=rch(root);
    rch(rc)=rt;
    fa[rt]=rc;
    root=rc;
    fa[rc]=0;
    maintain(root);
}

void changes(int pos)
{
    rotateto(pos,0);
    st[root]^=1;
    maintain(root);
}

void modify(int pos,int v)
{
    rotateto(pos,0);
    val[root]=v;
    maintain(root);
}

void init(int n)
{
    for(int i=0;i<n;++i)
        scanf("%d%d",&num[i],&fst[i]);
    lch(0)=rch(0)=0;
    fa[0]=size[0]=0;val[0]=-1;
    gcd[0][0]=gcd[0][1]=-1;
    cnt=0;
    newnode(root,0,-1,0);
    newnode(rch(root),root,-1,0);
    build(0,n-1,lch(rch(root)),rch(root));
    maintain(rch(root));
    maintain(root);
}

char s[5];
int l,r,pos,state,v;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init(n);
        while(m--)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d%d%d",&l,&r,&state);
                int ans=query(l,r,state);
                printf("%d\n",ans);
            }
            else if(s[0]=='I')
            {
                scanf("%d%d%d",&pos,&v,&state);
                insert(pos+1,v,state);
            }
            else if(s[0]=='D')
            {
                scanf("%d",&pos);
                del(pos);
            }
            else if(s[0]=='R')
            {
                scanf("%d",&pos);
                changes(pos);
            }
            else
            {
                scanf("%d%d",&pos,&v);
                modify(pos,v);
            }
        }
    }
    return 0;
}


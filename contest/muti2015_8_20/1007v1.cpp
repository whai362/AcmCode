#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

struct treap_node
{
    treap_node *left,*right;
    int v,fix,size,weight;
    inline int lsize() {return left ?left ->size:0;}
    inline int rsize() {return right?right->size:0;}
};

struct sgt_node
{
    sgt_node *left,*right;
    int a,b;
    treap_node *treap;
};

const int MAXN=100001,MAXM=100001,INF=0x7FFFFFFF/2;
const int MAXTN=(MAXN+MAXM)*16,MAXSN=MAXN*2;
treap_node TS[MAXTN];
sgt_node SS[MAXSN];
int D,N,M,TC,SC,Tcnt;
sgt_node *sgt_root;
treap_node *T[MAXN];

inline treap_node* new_treap_node(int v)
{
    TS[++TC].v=v;
    TS[TC].left=TS[TC].right=0;
    TS[TC].size=TS[TC].weight=1;
    TS[TC].fix=rand();
    return &TS[TC];
}

inline void treap_rotate_right(treap_node *&p)
{
    treap_node *q=p->left;
    p->left=q->right;
    q->right=p;
    p=q;
    q=p->right;
    q->size=q->lsize() + q->rsize() +q->weight;
    p->size=p->lsize() + p->rsize() +p->weight;
}

inline void treap_rotate_left(treap_node *&p)
{
    treap_node *q=p->right;
    p->right=q->left;
    q->left=p;
    p=q;
    q=p->left;
    q->size=q->lsize() + q->rsize() +q->weight;
    p->size=p->lsize() + p->rsize() +p->weight;
}

int treap_find(treap_node *p,int v)
{
    if (!p)
        return 0;
    else if (v<p->v)
        return treap_find(p->left,v);
    else if (v>p->v)
        return treap_find(p->right,v);
    else
        return p->weight;
}

void treap_insert(treap_node *&p,int v)
{
    if (!p)
        p=new_treap_node(v);
    else
    {
        p->size++;
        if (v < p->v)
        {
            treap_insert(p->left,v);
            if (p->left->fix < p->fix)
                treap_rotate_right(p);
        }
        else if (v > p->v)
        {
            treap_insert(p->right,v);
            if (p->right->fix < p->fix)
                treap_rotate_left(p);
        }
        else
            p->weight++;
    }
}

void treap_delete(treap_node *&p) //real deletion
{
    if (p->left && p->right)
    {
        if (p->left->fix < p->right->fix)
        {
            treap_rotate_right(p);
            treap_delete(p->right);
        }
        else
        {
            treap_rotate_left(p);
            treap_delete(p->left);
        }
    }
    else
    {
        if (p->left)
            p=p->left;
        else
            p=p->right;
    }
}

void treap_delete(treap_node *&p,int v) //lazy deletion
{
    if (v==p->v)
    {
        p->weight--;
        p->size--;
        if (p->weight==0)
            treap_delete(p);
    }
    else
    {
        if (v < p->v)
            treap_delete(p->left,v);
        else
            treap_delete(p->right,v);
        p->size--;
    }
}

void treap_succ(treap_node *p,int v,int &rs)
{
    if (!p) return;
    if (p->v >= v)
    {
        rs=p->v;
        treap_succ(p->left,v,rs);
    }
    else
        treap_succ(p->right,v,rs);
}

int treap_getmin(treap_node *p)
{
    while (p->left)
        p=p->left;
    return p->v;
}

int treap_getmax(treap_node *p)
{
    while (p->right)
        p=p->right;
    return p->v;
}

void treap_rank(treap_node *p,int v,int cur,int &rank)
{
    if (v == p->v)
        rank=p->lsize() + cur + 1;
    else if (v < p->v)
        treap_rank(p->left,v,cur,rank);
    else
        treap_rank(p->right,v,p->lsize() + cur + p->weight,rank);
}

inline sgt_node* new_sgt_node()
{
    SS[++SC].treap=0;
    SS[SC].a=SS[SC].b=0;
    SS[SC].left=SS[SC].right=0;
    return &SS[SC];
}

void sgt_build(sgt_node *&p,int a,int b)
{
    p=new_sgt_node();
    if (a==b)
        p->a=p->b=a;
    else
    {
        int m=(a+b) >> 1;
        sgt_build(p->left,a,m);
        sgt_build(p->right,m+1,b);
        p->a=a;p->b=b;
    }
}

int sgt_edit(sgt_node *p,int k,int v,bool del)
{
    int delter=0;
    if (p->a==p->b)
    {
        if (del)
            delter=p->treap->v;
    }
    else
    {
        int m=(p->a+p->b) >> 1;
        if (k>=p->a && k<=m)
            delter=sgt_edit(p->left,k,v,del);
        else
            delter=sgt_edit(p->right,k,v,del);
    }
    if (del)
        treap_delete(p->treap,delter);
    treap_insert(p->treap,v);
    return delter;
}

void sgt_get(sgt_node *p,int a,int b)
{
    if (p->a==a && p->b==b)
        T[++Tcnt]=p->treap;
    else
    {
        int m=(p->a+p->b) >> 1;
        if (b<=m)
            sgt_get(p->left,a,b);
        else if (a>=m+1)
            sgt_get(p->right,a,b);
        else
        {
            sgt_get(p->left,a,m);
            sgt_get(p->right,m+1,b);
        }
    }
}

void init()
{
    }

int check(int result,int k)
{
    int totalrankL,totalrankR,minsucc=INF;
    int i,rank,succ,totalrank=0,totalcount=0;
    for (i=1;i<=Tcnt;i++)
    {
        succ=INF;
        treap_succ(T[i],result,succ);
        if (succ==INF)
            rank=T[i]->size+1;
        else
            treap_rank(T[i],succ,0,rank);
        totalrank+=rank-1;
        if (succ < minsucc)
            minsucc=succ;
    }
    for (i=1;i<=Tcnt;i++)
        totalcount+=treap_find(T[i],minsucc);
    totalrankL=++totalrank;
    totalrankR=totalrank+totalcount-1;
    if (k>=totalrankL && k<=totalrankR)
    {
        printf("%d\n",minsucc);
        return 0;
    }
    else if (totalrankL > k)
        return 1;
    else
        return -1;
}

void binary(int a,int b,int k)
{
    int Min=INF,Max=0,i,m,r;
    Tcnt=0;
    sgt_get(sgt_root,a,b);
    for (i=1;i<=Tcnt;i++)
    {
        m=treap_getmax(T[i]);
        if (m>Max)
            Max=m;
        m=treap_getmin(T[i]);
        if (m<Min)
            Min=m;
    }
    m=(Max+Min)>>1;
    do
    {
        r=check(m,k); //-1=smaller 1=bigger
        if (r<0)
        {
            Min=m;
            m=(m+Max+1)>>1;
        }
        else if (r>0)
        {
            Max=m;
            m=(Min+m)>>1;
        }
    }while (r!=0);
}

void request()
{
    int i,a,b,c,j=0;
	int op;
    for (i=1;i<=M;i++)
    {
		scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d",&a,&b);
            sgt_edit(sgt_root,a,b,true);
        }
        else
        {
            scanf("%d%d%d",&a,&b,&c);
            binary(a,b,c);
        }
    }
}

int main()
{

	while(scanf("%d", &N) != EOF) {
		int i,v;
		TC=SC=-1;
		sgt_root=0;
		sgt_build(sgt_root,1,N);
		for (i=1;i<=N;i++)
		{
			scanf("%d",&v);
			sgt_edit(sgt_root,i,v,false); //non-deletion
		}
		scanf("%d", &M);
		request();
	}
    return 0;
}

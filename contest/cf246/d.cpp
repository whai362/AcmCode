#include <iostream>
#include <string.h>
#include <stdio.h>
#define maxn 2000010
#define Smaxn 26
#define inf 21000000
using namespace std;
struct node
{
    node *par,*go[Smaxn];
    int right;
    int num;
    int po;
    int val;
}*root,*tail,que[maxn],*top[maxn];
int tot;
char str[maxn>>1];
void add(int c,int l,int po)
{
    node *p=tail,*np=&que[tot++];
    np->val=l;
    np->po=po;
    while(p&&p->go[c]==NULL)
    p->go[c]=np,p=p->par;
    if(p==NULL) np->par=root;
    else
    {
        node *q=p->go[c];
        if(p->val+1==q->val) np->par=q;
        else
        {
            node *nq=&que[tot++];
            *nq=*q;
            nq->val=p->val+1;
            np->par=q->par=nq;
            while(p&&p->go[c]==q) p->go[c]=nq,p=p->par;
        }
    }
    tail=np;
}
int c[maxn],len;
void init()
{
    memset(que,0,sizeof(que));
    tot=0;
    len=1;
    root=tail=&que[tot++];
}
void solve(int n)
{
    memset(c,0,sizeof(c));
    int i;
    for(i=0;i<tot;i++)
    c[que[i].val]++;
    for(i=1;i<len;i++)
    c[i]+=c[i-1];
    for(i=0;i<tot;i++)
    top[--c[que[i].val]]=&que[i];
    for(node *p=root;;p=p->go[str[p->val+1]-'a'])
    {
        p->num=1;
        p->right=p->po;
        //printf("f");
        if (p->val==len-1)break;
    }
    for(i=tot-1;i>=0;i--)
    {
        node *p=top[i];
        if(p->right==0)
        {
            p->right=p->po;
        }
        if(p->par)
        {
            node *q=p->par;
            q->num+=p->num;
            if(q->right==0||q->right<p->right)
            q->right=p->right;
        }
    }
    int po=0;
    node *p=root;
    for(i=1;i<=n;i++)
    {
        p=p->go[str[i]-'a'];
        if(str[i]==str[n])
        {
            if(p->right==n&&p->num>=3)
            po=i;
        }
    }
    if(po==0)
    printf("Just a legend\n");
    else
    {
        for(i=1;i<=po;i++)
        printf("%c",str[i]);
        printf("\n");
    }
}
int main()
{
     freopen("dd.txt","r",stdin);
        scanf("%s",str+1);
        int i,l=strlen(str+1);
        init();
        for(i=1;i<=l;i++)
        {
            add(str[i]-'a',len++,i);
        }
        solve(l);

    return 0;
}


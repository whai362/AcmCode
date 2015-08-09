#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;
const int N=250005;

struct State
{
    State *pre,*go[26];
    int step,v;
    void clear()
    {
        v=0;
        pre=0;
        step=0;
        memset(go,0,sizeof(go));
    }
}*root,*last;

State statePool[N*2],*b[2*N],*cur;

void init()
{
    cur=statePool;
    root=last=cur++;
    root->clear();
}

void Insert(int w)
{
    State *p=last;
    State *np=cur++;
    np->clear();
    np->step=p->step+1;
    while(p&&!p->go[w])
        p->go[w]=np,p=p->pre;
    if(p==0)
        np->pre=root;
    else
    {
        State *q=p->go[w];
        if(p->step+1==q->step)
            np->pre=q;
        else
        {
            State *nq=cur++;
            nq->clear();
            memcpy(nq->go,q->go,sizeof(q->go));
            nq->step=p->step+1;
            nq->pre=q->pre;
            q->pre=nq;
            np->pre=nq;
            while(p&&p->go[w]==q)
                p->go[w]=nq, p=p->pre;
        }
    }
    last=np;
}

char str[N];
int cnt[N];
int dp[N];

int main()
{
    int n,m;
    while(~scanf("%s",str))
    {
        n=strlen(str);
        init();
        for(int i=0; i<n; i++)
            Insert(str[i]-'a');
		//for(State *p=statePool; p!=cur; p++)
		//	cout<<p->step<<' ';
		//cout<<endl;
        memset(cnt,0,sizeof(cnt));
        for(State *p=statePool; p!=cur; p++)
            cnt[p->step]++;
        for(int i=1; i<=n; i++)
            cnt[i]+=cnt[i-1];
		//for(int i = 0; i <= n; ++i)
		//	cout<<cnt[i]<<' ';
		//cout<<endl;
        for(State *p=statePool; p!=cur; p++)
            b[--cnt[p->step]]=p;
        for(int i=0;i<n;i++)
        {
            int x=str[i]-'a';
            root=root->go[x];
            root->v++;
        }

		//for(State *p=statePool; p!=cur; p++)
		//	cout<<p->v<<' ';
		//cout<<endl;
        memset(dp,0,sizeof(dp));
        int num=cur-statePool;
        for(int i=num-1;i>0;i--)
        {
			//cout<<b[i]->step<<' '<<b[i]->v<<endl;
            dp[b[i]->step]=max(dp[b[i]->step],b[i]->v);
            if(b[i]->pre) b[i]->pre->v += b[i]->v;
        }
		//for(int i = 0; i < n; ++i) {
		//	cout<<dp[i]<<' ';
		//}
		//cout<<endl;
        for(int i=n-1;i>0;i--)
            dp[i]=max(dp[i],dp[i+1]);
        for(int i=1;i<=n;i++)
            printf("%d\n",dp[i]);
    }
    return 0;
}

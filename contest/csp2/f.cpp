#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Node
{
    int x,y;
}node[800];
struct vector
{
    int a,b;
}V[100];
inline int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=a;a=b;b=t%b;
    }
    return a;
}
int cmp(const void *a,const void *b)
{
    if(((vector *)a)->a==((vector *)b)->a)
        return ((vector *)a)->b-((vector *)b)->b;
    return ((vector *)a)->a-((vector *)b)->a;
}
int solve(int N)
{
    int i,s,mx,j,t,ans=0;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            t=j-i;
            V[t].a=node[j].x-node[i].x;
            V[t].b=node[j].y-node[i].y;
            s=gcd(V[t].a,V[t].b);
            V[t].a/=s;V[t].b/=s;
            if(V[t].a<0)
                V[t].a*=-1,V[t].b*=-1;
        }
        qsort(V+1,N-i-1,sizeof(vector),cmp);
       
        for(j=2,s=1,mx=0;j<=N-i-1;j++)
        {
            if(V[j].a==V[j-1].a&&V[j].b==V[j-1].b)
                s++;
            else
                mx=mx>s?mx:s,s=1;
        }
        mx=mx>s?mx:s;
        ans=ans>mx?ans:mx;
    }
    return ans+1;
}
int main()
{
    int N,i,j,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
    
        for(i=0;i<N;i++)
            scanf("%d%d",&node[i].x,&node[i].y);
        printf("%d\n",solve(N));
    }
}

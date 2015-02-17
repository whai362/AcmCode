#include<stdio.h>
int fa[100010];long long rank[100010]; int n;
void initial()
{
    int i;
    for(i=1;i<=100000;i++)
    {
        fa[i]=i;  rank[i]=0;
    }
}
int getfather(int x)
{
    if(x!=fa[x]){
		rank[x]+=rank[fa[x]];
		return fa[x]=getfather(fa[x]);
	}
	return x;
}
int istrue(int x,int y,int c)
{
    int fx,fy;
    fx=getfather(x); fy=getfather(y);
    if(fx!=fy)
    {
        return 1;
    }
    else
    {
        if( rank[y] + c == rank[x] )  return 1;
        else  return 0;
    }
}
void unionset(int x,int y,int c)
{
    int fx,fy;
    fx=getfather(x); fy=getfather(y);
    if(fx==fy)  return;
    if(fy>fx)
    {
        fa[fx]=fy;
        rank[fx]= (c+rank[y]-rank[x]);
    }
    else
    {
        fa[fy]=fx;
        rank[fy]= (rank[x]-c-rank[y]);
    }
}
void isknown(int x)
{
    int fx,fy,y;
    y=x+1;
    fx=getfather(x); fy=getfather(y);
    if(fx!=fy)
    {
         printf("Unknown!\n");
    }
    else
    {
         printf("%lld\n",rank[x]-rank[y]);
    }
}
int main()
{
    int m,s,t,c,i,j;
    initial();
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&s,&t,&c);
        t++;
        if( istrue(s,t,c) )
        {
            unionset(s,t,c);
            printf("Accepted!\n");
        }
        else
        {
            printf("Error!\n");
        }
    }
    for(i=1;i<=n;i++)
    {
        isknown(i);
    }
    return 0;
}


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 10005
#define EPS 1e-6
using namespace std;
struct point
{
    int x,y;
    double len,theta;
} g[N];
void qsort(int st,int en)
{
    int i=st,j=en;
    g[0]=g[i];
    while(i<j)
    {
        while(i<j && g[0].theta>=g[j].theta) j--;
        if(i<j) { g[i]=g[j]; i++; }
        while(i<j && g[i].theta>=g[0].theta) i++;
        if(i<j) { g[j]=g[i]; j--; }
    }
    g[i]=g[0];
    if(st<i-1) qsort(st,i-1);
    if(i+1<en) qsort(i+1,en);
}
void graham(int *n)
{
    int p=1;
    for(int i=2;i<=*n;i++)
      if((g[i].y<g[p].y)||(g[i].y==g[p].y&&g[i].x<g[p].x)) p=i;
    g[0]=g[p]; g[p]=g[1]; g[1]=g[0];
    for(int i=2;i<=*n;i++)
    {
        g[i].len=sqrt((g[i].x-g[1].x)*(g[i].x-g[1].x)+(g[i].y-g[1].y)*(g[i].y-g[1].y));
        g[i].theta=(g[i].x-g[1].x)/g[i].len;
    }
    qsort(2,*n);
    point map[N]; int tot=0; p=1;
    while(p<=*n)
    {
        int k=p;
        while(fabs(g[p].theta-g[p+1].theta)<=EPS)
        {
            if(g[k].len<g[p+1].len) k=p+1;
            p++;
        }
        map[++tot]=g[k];
        p++;
    }
    *n=tot; tot=3; g[1]=map[1]; g[2]=map[2]; g[3]=map[3];
    for(int i=4;i<=*n;i++)
    {
        double chaji=(g[tot].x-g[tot-1].x)*(map[i].y-g[tot].y)-(map[i].x-g[tot].x)*(g[tot].y-g[tot-1].y);
        for(;chaji<0;chaji=(g[tot].x-g[tot-1].x)*(map[i].y-g[tot].y)-(map[i].x-g[tot].x)*(g[tot].y-g[tot-1].y)) tot--;
        g[++tot]=map[i];
    }
    *n=tot;
}
double jisuan(int x1,int x2,int x3)
{
    double a=sqrt((g[x1].x-g[x2].x)*(g[x1].x-g[x2].x)+(g[x1].y-g[x2].y)*(g[x1].y-g[x2].y));
    double b=sqrt((g[x2].x-g[x3].x)*(g[x2].x-g[x3].x)+(g[x2].y-g[x3].y)*(g[x2].y-g[x3].y));
    double c=sqrt((g[x1].x-g[x3].x)*(g[x1].x-g[x3].x)+(g[x1].y-g[x3].y)*(g[x1].y-g[x3].y));
    double p=1.0/2*(a+b+c);
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&g[i].x,&g[i].y);
    graham(&n);
    double ans=0;
    for(int i=2;i<n;i++) ans+=jisuan(1,i,i+1);
    printf("%d\n",int(ans/50));
    return 0;
}


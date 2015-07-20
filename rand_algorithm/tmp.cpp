#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
double xx,yy,ans,t;
double ansx,ansy;
struct point{double x,y;int v;}p[1005];
double sqr(double x){return x*x;}
double dis(double x,double y,point p)
{return sqrt(sqr(x-p.x)+sqr(y-p.y));}
double getsum(double x,double y)
{
    double tmp=0;
    for(int i=1;i<=n;i++)
        tmp+=p[i].v*dis(x,y,p[i]);
    return tmp;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        xx=yy=0;ans=1e20;t=10000;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%d",&p[i].x,&p[i].y,&p[i].v);
            xx+=p[i].v*p[i].x;yy+=p[i].v*p[i].y;
        }
        xx/=n;yy/=n;
        ans=getsum(xx,yy);
        double tmp,x,y;
        while(t>0.00000001)
        {
            x=y=0;
            for(int i=1;i<=n;i++)
            {
                x+=p[i].v*(p[i].x-xx)/dis(xx,yy,p[i]);
                y+=p[i].v*(p[i].y-yy)/dis(xx,yy,p[i]);
            }
			xx+=x*t;yy+=y*t;
            tmp=getsum(xx,yy);
            if(tmp<ans){ans=tmp;ansx=xx;ansy=yy;}
            t*=0.998;
        }
        printf("%.2f %.2f\n",ansx,ansy);
    }
    return 0;
}

//求n边形的费马点
//即找到一个点使得这个点到n个点的距离之和最小
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
const double inf = 1e10;
const double pi = acos(-1.0);
const int Rp = 4;//初始时随机选择一些点，不用太多
const int shift = 60;//但是方向一定要多
struct point {
    double x,y;
    void goto_rand_dir(double key)
    {
        double d=2*pi*(double)rand()/RAND_MAX;
        x+=key*sin(d);
        y+=key*cos(d);
    }
    void Get_Rand_Point(int a,int b)
    {
        x=rand()%a+1;
        y=rand()%b+1;
    }
}p[1010],randp[Rp];
double Dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dis[Rp];
int main()
{
    int i,j,x,y,k,m;
    srand(time(NULL));
    while(scanf("%d",&m)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        x=10000;y=10000;
        double tmp;
        for(i=0;i<Rp;i++)
        {
            dis[i]=inf;
            randp[i].Get_Rand_Point(x,y);
            tmp=0;
            for(j=0;j<m;j++)
            {
                tmp+=Dis(randp[i],p[j]);    
            }
            if(tmp<dis[i])
                dis[i]=tmp;
        }
        double key=sqrt(1.0*(x*x+y*y));//初始的步长，要保证初始点从该点出发肯定能包括整个区域
        while(key>=0.01)
        {
            for(i=0;i<Rp;i++)
            {
                for(j=0;j<shift;j++)
                {
                    point cc=randp[i];
                    cc.goto_rand_dir(key);
                    if(cc.x<0||cc.y<0||cc.x>x||cc.y>y) continue;
                    tmp=0;
                    for(k=0;k<m;k++)
                    {
                        tmp+=Dis(cc,p[k]);
                    }
                    if(tmp<dis[i]) //如果从i点出发随机移动的点比原来的点更优，则接受该移动
                    {
                        dis[i]=tmp;
                        randp[i]=cc;
                    }
                }
            }
            key=key*0.6;//可灵活调整
        }
        for(i=k=0;i<Rp;i++)
            if(dis[i]<dis[k])
                k=i;
            printf("%.0lf\n",dis[k]);
    }
    return 0;
}

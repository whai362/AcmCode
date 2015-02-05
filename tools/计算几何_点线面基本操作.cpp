/* 需要包含的头文件 */
#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
/* 常量定义 */
const double INF = 1E200;
const double EP = 1E-11;
const int MAXV = 300;
const double PI = acos(-1.0);
/* 基本几何结构 */
struct POINT
{
    double x;
    double y;
    POINT(double a=0, double b=0) { x=a; y=b;}
};
struct LINESEG
{
    POINT s;
    POINT e;
    double a, b, c;//一般式,ax+by+c=0
    LINESEG(POINT _s, POINT _e) { s=_s; e=_e;}
    LINESEG() { }
};
// 直线的解析方程 a*x+b*y+c=0 为统一表示，约定 a>= 0
struct LINE
{
    double a;
    double b;
    double c;
    LINE(double d1=1, double d2=-1, double d3=0) {a=d1; b=d2; c=d3;}
};
//线段树
struct LINETREE
{
};
//浮点误差的处理
int dblcmp(double d)
{
    if(fabs(d)<EP)
        return 0 ;
    return (d>0) ?1 :-1 ;
}
// 返回两点之间欧氏距离
double dist(POINT p1,POINT p2)
{
    return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) );
}
// 判断两个点是否重合
bool equal_point(POINT p1,POINT p2)
{
    return ( (abs(p1.x-p2.x)<EP)&&(abs(p1.y-p2.y)<EP) );
}
/*(sp-op)*(ep-op)的叉积
  r=multiply(sp,ep,op),得到(sp-op)*(ep-op)的叉积
  r>0:sp在矢量op ep的顺时针方向；
  r=0：op sp ep三点共线；
  r<0: sp在矢量op ep的逆时针方向 */
double multiply(POINT sp,POINT ep,POINT op)
{
    return((sp.x-op.x)*(ep.y-op.y) - (ep.x-op.x)*(sp.y-op.y));
}
double amultiply(POINT sp,POINT ep,POINT op)
{
    return fabs((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y));
}
/*矢量(p1-op)和(p2-op)的点积
  r=dotmultiply(p1,p2,op),得到矢量(p1-op)和(p2-op)的点积如果两个矢量都非零矢量
  r < 0: 两矢量夹角为锐角；
  r = 0：两矢量夹角为直角；
  r > 0: 两矢量夹角为钝角 */
double dotmultiply(POINT p1,POINT p2,POINT p0)
{
    return ((p1.x-p0.x)*(p2.x-p0.x) + (p1.y-p0.y)*(p2.y-p0.y));
}
/* 判断点p是否在线段l上
   条件：(p在线段l所在的直线上)&& (点p在以线段l为对角线的矩形内) */
bool online(LINESEG l,POINT p)
{
    return ((multiply(l.e,p,l.s)==0)
            && ( ( (p.x-l.s.x) * (p.x-l.e.x) <=0 ) && ( (p.y-l.s.y)*(p.y-l.e.y) <=0 ) ) );
}
// 返回点p以点o为圆心逆时针旋转alpha(单位：弧度)后所在的位置
POINT rotate(POINT o,double alpha,POINT p)
{
    POINT tp;
    p.x -=o.x;
    p.y -=o.y;
    //cout<<alpha<<endl;
    tp.x=p.x*cos(alpha) - p.y*sin(alpha)+o.x;
    tp.y=p.y*cos(alpha) + p.x*sin(alpha)+o.y;
    //cout<<tp.x<<' '<<tp.y<<endl;
    return tp;
}
/* 返回顶角在o点，起始边为os，终止边为oe的夹角(单位：弧度)
   角度小于pi，返回正值
   角度大于pi，返回负值
   可以用于求线段之间的夹角 */
double angle(POINT o,POINT s,POINT e)
{
    /*cout<<o.x<<' '<<o.y<<endl;
    cout<<s.x<<' '<<s.y<<endl;
    cout<<e.x<<' '<<e.y<<endl;*/
    double cosfi,fi,norm;
    double dsx = s.x - o.x;
    double dsy = s.y - o.y;
    double dex = e.x - o.x;
    double dey = e.y - o.y;
    //cout<<dsx<<' '<<dsy<<' '<<dex<<' '<<dey<<endl;
    cosfi=dsx*dex+dsy*dey;

    norm=(dex*dex+dey*dey)*(dsx*dsx+dsy*dsy);
    cosfi /= sqrt( norm );
    //cout<<cosfi<<endl;
    if (cosfi >= 1.0 ) return 0;
    if (cosfi <= -1.0 ) return PI;
    fi=acos(cosfi);
    if (dsx*dey-dsy*dex>0) return fi; // 说明矢量os 在矢量 oe的顺时针方向
    return 2*PI-fi;
}

LINESEG ppline(POINT _a, POINT _b)
{
    LINESEG ret;
    ret.s.x = (_a.x + _b.x) / 2;
    ret.s.y = (_a.y + _b.y) / 2;
    //一般式
    ret.a = _b.x - _a.x;
    ret.b = _b.y - _a.y;
    ret.c = (_a.y - _b.y) * ret.s.y + (_a.x - _b.x) * ret.s.x;
    //两点式
    if(fabs(ret.a) > EP)
    {
        ret.e.y = 0.0;
        ret.e.x = - ret.c / ret.a;
        if(fabs(ret.e.x-ret.s.x)<EP && fabs(ret.e.y-ret.s.y)<EP) //
        {
            ret.e.y = 1e10;
            ret.e.x = - (ret.c - ret.b * ret.e.y) / ret.a;
        }
    }
    else
    {
        ret.e.x = 0.0;
        ret.e.y = - ret.c / ret.b;
        if(fabs(ret.e.x-ret.s.x)<EP && fabs(ret.e.y-ret.s.y)<EP) //
        {
            ret.e.x = 1e10;
            ret.e.y = - (ret.c - ret.a * ret.e.x) / ret.b;
        }
    }
    return ret;
}

/* 判断点C在线段AB所在的直线l上垂足P的与线段AB的关系
   本函数是根据下面的公式写的，P是点C到线段AB所在直线的垂足
   AC dot AB
   r = ----------------------
   ||AB||^2
   (Cx-Ax)(Bx-Ax) + (Cy-Ay)(By-Ay)
   = ----------------------------------------------------
   L^2
   r has the following meaning:
   r=0 P = A
   r=1 P = B
   r<0 P is on the backward extension of AB
   r>1 P is on the forward extension of AB
   0<r<1 P is interior to AB
 */
double relation(POINT c,LINESEG l)
{
    LINESEG tl;
    tl.s=l.s;
    tl.e=c;
    return dotmultiply(tl.e,l.e,l.s)/(dist(l.s,l.e)*dist(l.s,l.e));
}
// 求点C到线段AB所在直线的垂足 P
POINT perpendicular(POINT p,LINESEG l)
{
    double r=relation(p,l);
    POINT tp;
    tp.x=l.s.x+r*(l.e.x-l.s.x);
    tp.y=l.s.y+r*(l.e.y-l.s.y);
    return tp;
}
/* 求点p到线段l的最短距离
   返回线段上距该点最近的点np 注意：np是线段l上到点p最近的点，不一定是垂足 */
double ptolinesegdist(POINT p,LINESEG l,POINT &np)
{
    double r=relation(p,l);
    if(r<0)
    {
        np=l.s;
        return dist(p,l.s);
    }
    if(r>1)
    {
        np=l.e;
        return dist(p,l.e);
    }
    np=perpendicular(p,l);
    return dist(p,np);
}
// 求点p到线段l所在直线的距离
//请注意本函数与上个函数的区别
double ptoldist(POINT p,LINESEG l)
{
    return abs(multiply(p,l.e,l.s))/dist(l.s,l.e);
}
/* 计算点到折线集的最近距离,并返回最近点.
   注意：调用的是ptolineseg()函数 */
double ptopointset(int vcount, POINT pointset[], POINT p, POINT &q)
{
    int i;
    double cd=double(INF),td;
    LINESEG l;
    POINT tq,cq;
    for(i=0;i<vcount-1;i++)
    {
        l.s=pointset[i];
        l.e=pointset[i+1];
        td=ptolinesegdist(p,l,tq);
        if(td<cd)
        {
            cd=td;
            cq=tq;
        }
    }
    q=cq;
    return cd;
}
/* 判断圆是否在多边形内*/
bool CircleInsidePolygon(int vcount,POINT center,double radius,POINT polygon[])
{
    POINT q;
    double d;
    q.x=0;
    q.y=0;
    d=ptopointset(vcount,polygon,center,q);
    if(d<radius||fabs(d-radius)<EP) return true;
    else return false;
}
/* 返回两个矢量l1和l2的夹角的余弦 (-1 ~ 1)
   注意：如果想从余弦求夹角的话，注意反余弦函数的值域是从 0到pi */
double cosine(LINESEG l1,LINESEG l2)
{
    return(((l1.e.x-l1.s.x)*(l2.e.x-l2.s.x)+(l1.e.y-l1.s.y)*(l2.e.y-l2.s.y))/(dist(l1.e,l1.s)*dist(l2.e,l2.s)));
}
// 返回线段l1与l2之间的夹角
//单位：弧度 范围(-pi，pi)
double lsangle(LINESEG l1,LINESEG l2)
{
    POINT o,s,e;
    o.x=o.y=0;
    s.x=l1.e.x-l1.s.x;
    s.y=l1.e.y-l1.s.y;
    e.x=l2.e.x-l2.s.x;
    e.y=l2.e.y-l2.s.y;
    return angle(o,s,e);
}
//判断线段u和v相交(包括相交在端点处)
bool intersect(LINESEG u,LINESEG v)
{
    return ( (max(u.s.x,u.e.x)>=min(v.s.x,v.e.x))&& //排斥实验
            (max(v.s.x,v.e.x)>=min(u.s.x,u.e.x))&&
            (max(u.s.y,u.e.y)>=min(v.s.y,v.e.y))&&
            (max(v.s.y,v.e.y)>=min(u.s.y,u.e.y))&&
            (multiply(v.s,u.e,u.s)*multiply(u.e,v.e,u.s)>=0)&& //跨立实验
            (multiply(u.s,v.e,v.s)*multiply(v.e,u.e,v.s)>=0));
}
// 判断线段u和v相交（不包括双方的端点）
bool intersect_A(LINESEG u,LINESEG v)
{
    return ((intersect(u,v)) &&
            (!online(u,v.s)) &&
            (!online(u,v.e)) &&
            (!online(v,u.e)) &&
            (!online(v,u.s)));
}
// 判断线段v所在直线与线段u相交
bool intersect_l(LINESEG u,LINESEG v)
{
    return multiply(u.s,v.e,v.s)*multiply(v.e,u.e,v.s)>=0;
}
// 根据已知两点坐标，求过这两点的直线解析方程： a*x+b*y+c = 0 (a >= 0)
LINE makeline(POINT p1,POINT p2)
{
    LINE tl;
    int sign = 1;
    tl.a=p2.y-p1.y;
    if(tl.a<0)
    {
        sign = -1;
        tl.a=sign*tl.a;
    }
    tl.b=sign*(p1.x-p2.x);
    tl.c=sign*(p1.y*p2.x-p1.x*p2.y);
    return tl;
}
// 根据直线解析方程返回直线的斜率k,水平线返回 0,竖直线返回 1e200
double slope(LINE l)
{
    if(abs(l.a) < 1e-20)return 0;
    if(abs(l.b) < 1e-20)return INF;
    return -(l.a/l.b);
}
// 返回直线的倾斜角alpha ( 0 - pi)
// 注意：atan()返回的是 -PI/2 ~ PI/2
double alpha(LINE l)
{
    if(abs(l.a)< EP)return 0;
    if(abs(l.b)< EP)return PI/2;
    double k=slope(l);
    if(k>0)
        return atan(k);
    else
        return PI+atan(k);
}
// 求点p关于直线l的对称点
POINT symmetry(LINE l,POINT p)
{
    POINT tp;
    tp.x=((l.b*l.b-l.a*l.a)*p.x-2*l.a*l.b*p.y-2*l.a*l.c)/(l.a*l.a+l.b*l.b);
    tp.y=((l.a*l.a-l.b*l.b)*p.y-2*l.a*l.b*p.x-2*l.b*l.c)/(l.a*l.a+l.b*l.b);
    return tp;
}
// 如果两条直线 l1(a1*x+b1*y+c1 = 0), l2(a2*x+b2*y+c2 = 0)相交，返回true，且返回交点p
bool lineintersect(LINE l1,LINE l2,POINT &p) // 是 L1，L2
{
    double d=l1.a*l2.b-l2.a*l1.b;
    if(abs(d)<EP) // 不相交
        return false;
    p.x = (l2.c*l1.b-l1.c*l2.b)/d;
    p.y = (l2.a*l1.c-l1.a*l2.c)/d;
    return true;
}
// 如果线段l1和l2相交，返回true且交点由(inter)返回，否则返回false
bool intersection(LINESEG l1,LINESEG l2,POINT &inter)
{
    LINE ll1,ll2;
    ll1=makeline(l1.s,l1.e);
    ll2=makeline(l2.s,l2.e);
    if(lineintersect(ll1,ll2,inter)) return online(l1,inter);
    else return false;
}

int main(){
    int n,T;
    scanf("%d",&T);
    while(T--){
    double du;
    POINT p[4],o;
    p[0].x=p[0].y=3.1415;
    p[2].x=p[2].y=31.415;
    scanf("%d",&n);
    p[1]=p[0];
    p[3]=p[2];
    for(int i=0;i<n;++i){
        scanf("%lf%lf%lf",&o.x,&o.y,&du);
        p[1]=rotate(o,du,p[1]);
        p[3]=rotate(o,du,p[3]);
    }
    LINESEG l1=ppline(p[0],p[1]),
            l2=ppline(p[2],p[3]);
    POINT anso;
    intersection(l1,l2,anso);
    double ansdu;
    ansdu=angle(anso,p[2],p[3]);
    printf("%.10lf %.10lf %.10lf\n",anso.x,anso.y,ansdu);
    }
    return 0;
}

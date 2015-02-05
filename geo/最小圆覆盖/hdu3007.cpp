#include<stdio.h> 
#include<string.h> 
#include<math.h> 
 
struct Point 
{ 
    double x, y; 
} p[101], o; //定义点和圆心 
 
int n; 
double r;//圆半径 
double eps = 1e-6; 
 
double dist( Point a, Point b) 
{ 
    return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y ) * (a.y - b.y)); 
} 
 
Point intersection(Point u1, Point u2, Point v1, Point v2) 
{ 
    Point ans = u1; 
    double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) / 
               ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x)); 
    ans.x += (u2.x - u1.x) * t; 
    ans.y += (u2.y - u1.y) * t; 
    return ans; 
}//求线段交点 
 
Point circumcenter(Point a, Point b, Point c) 
{ 
    Point ua, ub, va, vb; 
    ua.x = ( a.x + b.x ) / 2; 
    ua.y = ( a.y + b.y ) / 2; 
    ub.x = ua.x - a.y + b.y;//根据 垂直判断，两线段点积为0 
    ub.y = ua.y + a.x - b.x; 
    va.x = ( a.x + c.x ) / 2; 
    va.y = ( a.y + c.y ) / 2; 
    vb.x = va.x - a.y + c.y; 
    vb.y = va.y + a.x - c.x; 
    return intersection(ua, ub, va, vb); 
} 
//计算三角形外接圆圆心 
 
Point min_center() 
{ 
    int i, j, k; 
    o = p[0]; 
    r = 0; 
    for( i = 1 ; i < n ; i++)//准备加入的点 
    { 
        if( dist( p[i], o) - r > eps)//如果第i点在 i-1前最小圆外面 
        { 
            o = p[i];//另定圆心 
            r = 0;//另定半径 
 
            for( j = 0 ; j < i; j++)//循环再确定半径 
            { 
                if( dist(p[j], o) - r > eps) 
                { 
                    o.x = (p[i].x + p[j].x) / 2.0; 
                    o.y = (p[i].y + p[j].y) / 2.0; 
 
                    r = dist( o, p[j]); 
 
                    for( k = 0 ; k < j; k++) 
                    { 
                        if( dist(o, p[k]) - r > eps)//如果j前面有点不符和 i与j确定的圆，则更新 
                        { 
                            o = circumcenter(p[i], p[j], p[k]); 
                            r = dist(o, p[k]); 
                        } 
                    }//循环不超过3层，因为一个圆最多3个点可以确定 
                } 
            } 
        } 
    } 
    return o; 
} 
 
int main() 
{ 
    int i, j, k; 
    while(scanf("%d", &n), n) 
    { 
        for( i = 0 ; i < n ; i++) 
            scanf("%lf%lf", &p[i].x, &p[i].y); 
 
 
        min_center(); 
 
        printf("%.2lf %.2lf %.2lf\n", o.x, o.y, r); 
    } 
    return 0; 
} 

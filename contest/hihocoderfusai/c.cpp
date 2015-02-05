#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define maxn 105
struct point 
{
    double x, y, z;
}p[maxn];
double a, b, c;
void one()
{
    int i = 1;
    if (p[i].x == 0 && p[i].y == 0 && p[i].z == 0) {a = b = c = 1; return ;}
    if (p[i].x == 0 && p[i].y == 0 && p[i].z != 0) {a = b = 1, c = 0; return ;}
    if (p[i].x == 0 && p[i].y != 0 && p[i].z == 0) {a = c = 1, b = 0; return ;}
    if (p[i].x != 0 && p[i].y == 0 && p[i].z == 0) {a = 0, b = c = 1; return ;}
    if (p[i].x == 0 && p[i].y != 0 && p[i].z != 0) {a = 1, b = c = 0;}
    if (p[i].x != 0 && p[i].y == 0 && p[i].z != 0) {a = c = 0, b = 1;}
    if (p[i].x != 0 && p[i].y != 0 && p[i].z == 0) {a = b = 0, c = 1;}
    if (p[i].x != 0 && p[i].y != 0 && p[i].z != 0) 
    {
        a = 0, b = 1; c = - (double)p[i].y * b / (double)p[i].z;
        return ;
    }
}
void two()
{
    if (p[1].x == 0 && p[1].y == 0 && p[1].z == 0) 
    {
        p[1].x = p[2].x, p[1].y = p[2].y, p[1].z = p[2].z;
        one();
        return ;
    }
    if (p[2].x == 0 && p[2].y == 0 && p[2].z == 0) 
    {
        one();
        return ;
    }
    if (p[1].x == p[2].x && p[1].y == p[1].y && p[1].z == p[2].z) 
    {
        one();
        return ;
    }
    if (p[1].z * p[2].x == p[2].z * p[1].x && p[1].y * p[2].x == p[2].y * p[1].x) 
    {
        one();
        return ;
    }
    a = p[1].y * p[2].z - p[2].y * p[1].z;
    b = p[1].z * p[2].x - p[2].z * p[1].x;
    c = p[1].x * p[2].y - p[2].x * p[1].y;
}

int main()
{
    int cas = 1, T, n;
    scanf("%d", &T);
    while (T--) 
    {
        scanf("%d", &n);
        printf("Case %d: ", cas++);
        for (int i = 1; i <= n; i ++) 
            scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
        if (n == 1) one();
        if (n == 2) two();
        printf("%.6f %.6f %.6f\n", a, b, c);
    }
    return 0;
} 


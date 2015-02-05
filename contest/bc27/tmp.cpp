
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct note
{
    int m,id,ran;
}a[105];
bool cmp1(note a,note b)
{
    return a.m>b.m;
}
bool cmp2(note a,note b)
{
    return a.id<b.id;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i].m=max(max(x,y),z);
            a[i].id=i+1;
        }
        sort(a,a+n,cmp1);
        for(int i=0;i<n;i++)
        {
            a[i].ran=i+1;
        }
        sort(a,a+n,cmp2);
        for(int i=0;i<n;i++)
        {
            printf(i==n-1?"%d\n":"%d ",a[i]);
        }
    }
    return 0;
}


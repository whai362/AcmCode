#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>

using namespace std;

double aim,part,dif,a[1002];
int u[1002],flag,n;

void dfs(int x)
{
    int i;
    if (flag==1)
    {
        return;
    }
    else if (x>=n)
    {
        part=0;
        for (i=0;i<=n-1;i++)
        {
           if (u[i]==1)
           {
               part=part+a[i];
           }
        }
        dif=abs(aim-part)/aim;
        if (dif<=0.02)
        {
            flag=1;
        }
        return;
    }
    else if (x<n)
    {
        u[x]=0;
        dfs(x+1);
        if (flag==1)
        {
            return;
        }
        u[x]=1;
        dfs(x+1);
        if (flag==1)
        {
            return;
        }
    }
}

int main()
{
    do
    {
        int i,t;
        flag=0;
        t=0;
        memset(u,0,sizeof(u));
        scanf("%d",&n);
        for (i=0;i<=n-1;i++)
        {
            scanf("%lf",&a[i]);
            t=t+a[i];
        }
        aim=t/2.0;
        dfs(0);
        for (i=0;i<=n-1;i++)
        {
            if (u[i]==1)
            {
                printf("%d ",i+1);
            }
        }
        printf("\n");
    }while(1);
    return 0;
}

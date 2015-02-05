#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,m,sum,a,max,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        sum=0; max=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(max<a) max=a;
            sum+=a;
        }
        if(n<=m)
        {
            printf("%d\n",max);
        }
        else
        {
            k=sum/m;
            if(sum%m)k++;
            if(k<max)k=max;
            printf("%d\n",k);
        }
    }
}


#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int Max,sum,n,ans;
long long pos,p;
void dfs(int row,int l,int r)
{
    int pos=Max & (~(row|l|r));
    if(row!=Max)
    {
        while(pos!=0)
        {
            p=pos&-pos;
            pos-=p;
            l&=Max;
            dfs(row+p,(l+p)<<1,(r+p)>>1);
        }
    }
    else
        sum++;
}
int main()
{
    int row,l,r;
    while(~scanf("%d",&n))
    {
        Max=(1<<n)-1;
        sum=0;
        for(int i=1;i<Max;i<<=1)
        {
            row=i,l=(i<<1),r=(i>>1);
            dfs(row,l,r);
        }
        printf("%d\n",sum);
    }
    return 0;
}


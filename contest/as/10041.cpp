#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int T,N,M,D;
vector<int> tab[51];
long double dp[10009][51];
double getans(int p)
{
    memset(dp,0,sizeof(dp));
    long double ans = 1.0;
    for (int i=1;i<=N;i++)
        dp[0][i]=1.0/N;
    for (int i=0;i<=D;i++)
    {
        ans-=dp[i][p];
        dp[i][p]=0;
        for (int j=1;j<=N;j++)
            for (int k=0;k<tab[j].size();k++)
                dp[i+1][tab[j][k]]+=dp[i][j]/tab[j].size();
    }
    return (double)ans;
}
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&N,&M,&D);
        for (int i=1;i<=N;i++)
            tab[i].clear();
        for (int i=1;i<=M;i++)
        {
            int f,t;
            scanf("%d%d",&f,&t);
            tab[f].push_back(t);
            tab[t].push_back(f);
        }
        for (int i=1;i<=N;i++)
            printf("%.10lf\n",fabs(getans(i)));
    }
    return 0;
}

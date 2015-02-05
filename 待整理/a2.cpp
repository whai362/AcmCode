#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 100010;
vector<int>vec[MAXN];
int pre[MAXN];
vector<int>ans;
void add(int u)
{
    if(u == -1)return ;
    add(pre[u]);
    ans.push_back(u);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int iCase = 0;
    scanf("%d",&T);
    int n,m;
    while(T--)
    {
        iCase++;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < m;i++)
            vec[i].clear();
        for(int i = 0;i < m;i++)
        {
            int num;
            int x;
            scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&x);
                vec[i].push_back(x);
            }
        }
        bool flag = true;
        for(int i = 0;i < m;i++)
        {
            int sz = vec[i].size();
            for(int j = 1;j < sz;j++)
                if(vec[i][j] < vec[i][j-1])
                {
                    flag = false;
                    break;
                }
        }
        if(!flag)
        {
            printf("Case #%d: No solution\n",iCase);
            continue;
        }
        memset(pre,-1,sizeof(pre));
        for(int i = m-1;i > 0;i--)
        {
            int sz = vec[i].size();
            int p = vec[i-1].size();
            for(int j = sz-1;j >= 0;j--)
            {
                if(p <= 0)
                {
                    flag = false;
                    break;
                }
                p = lower_bound(vec[i-1].begin(),vec[i-1].begin()+p,vec[i][j]) - vec[i-1].begin();
                if(p <= 0)
                {
                    flag = false;
                    break;
                }
                pre[vec[i-1][p-1]] = vec[i][j];
                p--;
            }
        }
        if(!flag)
        {
            printf("Case #%d: No solution\n",iCase);
            continue;
        }
        ans.clear();
        for(int i = 0;i < vec[0].size();i++)
            add(vec[0][i]);
        printf("Case #%d:",iCase);
        for(int i = 0;i < n;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    
    return 0;
}


#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef __int64 lld;
const int MAX=11000;
const lld INF=1000000000;
const lld MOD=1000000;
const double EPS=1.0e-8;
priority_queue<int>q;
struct TOWN
{
    int p,f;
}town[MAX];
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
  
int dblcmp(double x)
{
    if(fabs(x)<EPS)return 0;
    return x<0?-1:1;
}
bool cmp(TOWN a,TOWN b)
{
    return a.p<b.p;
}
int main()
{
    int n=5;
    int i,j,k;
    int m,CS=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%d%d",&town[i].p,&town[i].f);
        town[n].p=0;
        town[n].f=0;
        n++;
        sort(town,town+n,cmp);
        int p,f;
        scanf("%d%d",&p,&f);
        while(!q.empty())q.pop();
        int ans=0;
        bool flag=false;
        for(i=n-1;i>=0;i--)
        {
            if(p-f<=0)
            {
                flag=true;
                break;
            }
            while(p-f>town[i].p)
            {
                if(!q.empty())
                {
                    f+=q.top();
                    q.pop();
                    ans++;
                }
                else break;
            }
            if(p-f>town[i].p)break;
            q.push(town[i].f);
            f-=(p-town[i].p);
            p=town[i].p;
              
        }
        if(i<0)flag=true;
        if(flag)printf("%d\n",ans);
        else puts("-1");
    }
    return 0;
}


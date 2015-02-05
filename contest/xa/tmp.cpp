#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define inf INT_MAX
#define maxn 110
struct node
{
    int i,j;//记录坐标
}man[maxn],house[maxn];

//dis[x][y]顶点x到顶点y的距离
//c[x][y]表示当前残余流量值:1或者0
//p[x]记录增益路径中x点前一个顶点
//inq[x]标记函数
//hi房子数目,mi人数
//增益路径中d[x]是S到x的最短距离
int dis[2*maxn][2*maxn],c[2*maxn][2*maxn];
int p[2*maxn];
bool inq[2*maxn];
int d[2*maxn];
int hi,mi;//mi==hi
//采用FIFO队列Bellman_Ford寻找一条增益路径,成功返回1，失败返回0
int bellman_ford(int s,int t)
{
    queue<int> q;
    q.push(s);
    //初始化标记函数和距离函数
    memset(inq,0,sizeof(inq));
    for(int i=0;i<=2*mi+1;i++)  d[i]=inf;
    d[s]=0;
    inq[s]=1;
    while(!q.empty())
    {
        int x=q.front();
            q.pop();
        inq[x]=false;
        for(int v=1;v<=2*mi+1;v++)
        {
            if(d[v] > d[x] + dis[x][v] && c[x][v]) //有残余,松弛
            {
                d[v]=d[x]+dis[x][v];
                p[v]=x;                            //记录路径
                if(!inq[v])                        //已经在队列中就不需要重复添加
                {
                    inq[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return d[2*mi+1]!=inf;//是否找到增益路径
}

int main()
{
    //freopen("2195.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    int n,m;
    int i,j;
    char ch;
    //int mi,hi;
    while(scanf("%d%d\n",&n,&m)!=EOF && !(n==0 && m==0))
    {
        mi=hi=1;
        //scanf("&c",&ch);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                //cin>>ch;
                scanf("%c\n",&ch);
                if(ch=="m")
                {
                    man[mi].i = i;
                    man[mi++].j = j;
                }
                if(ch=="H")
                {
                    house[hi].i = i;
                    house[hi++].j = j;
                }

            }
        }
        hi--;mi--;
        //初始化残余流量为0
        //dis[x][y] x,y不相连
        memset(c,0,sizeof(c));
        for(i=0;i<=2*mi+1;i++)
            for(j=0;j<=2*mi+1;j++)
                dis[i][j]=inf;
        for(i=1;i<=mi;i++)
        {
            for(j=1;j<=hi;j++)
            {
                //计算dis[man][house]=|i|+|j|;
                //计算c[man][house]=1;
                dis[i][mi+j]=abs(man[i].i-house[j].i) + abs(man[i].j - house[j].j);
                dis[mi+j][i]=-dis[i][mi+j];
                c[i][mi+j]=1;
            }
        }
        for(i=1;i<=mi;i++)
        {
            //创造一个源点S[0]和汇点t[2*mi+1]
            //dis[0][man]=dis[man][0]=0 c[0][man]=1;
            //dis[t][house]=dis[house][t]=0 c[house][t]=1;
            dis[0][i]=dis[i][0]=0;
            dis[mi+i][2*mi+1]=dis[2*mi+1][mi+i]=0;
            c[0][i]=1;
            c[mi+i][2*mi+1]=1;
        }
        int s=0,t=2*mi+1;
        int min=0;//记录费用
        while(bellman_ford(s,t))
        {
            for(int u=t;u!=s;u=p[u])
            {
                //cout<<u<<" ";
                c[p[u]][u]-=1;
                c[u][p[u]]+=1;
            }
            min+=d[2*mi+1];
        }
        cout<<min<<endl;
    }
    return 1;
}

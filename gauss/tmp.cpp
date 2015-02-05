ZJUT 1423

/*

地下迷宫

Description:
由于山体滑坡，DK被困在了地下蜘蛛王国迷宫。为了抢在DH之前来
到TFT，DK必须尽快走出此迷宫。此迷宫仅有一个出口，而由于大BOSS
的力量减弱影响到了DK，使DK的记忆力严重下降，他甚至无法记得他
上一步做了什么。所以他只能每次等概率随机的选取一个方向走。
当然他不会选取周围有障碍的地方走。如DK周围只有两处空地，则每
个都有1/2的概率。现在要求他平均要走多少步可以走出此迷宫。

Input:
先是一行两个整数N, M(1<=N, M<=10)表示迷宫为N*M大小，
然后是N行，每行M个字符，'.'表示是空地，'E’表示出口，'D’表示DK，'X’表示障碍。
Output:
如果DK无法走出或要超过1000000步才能走出，输出tragedy!，
否则输出一个实数表示平均情况下DK要走几步可以走出迷宫，四舍五入到小数点后两位。
Sample Input:
2
ED
3
D.X
.X.
X.E
Sample Output:
1.00
tragedy!


首先对地图节点重新标号。假设E[i]表示DK从i点开始走出迷宫的期望值。
那么E[i]=(E[a1]+E[a2]+E[a3]+...+E[an])/n+1，其中a1...an是i的相邻节点。
那么对于每一个DK可达的节点来说，都可以为它建立这样的一个方程。现
在假设DK可达的点有N个，那么我们最终将会得到N元一次方程组。最后
利用高斯消元解出E[No[S]]。其中S是DK的起点，No[S]是重标号后的起点
这里要重点注意的是，我们联立方程的时候，一定要注意DK可达这个条件，
不然就会导致无解的情况。

*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;

#define eps 1e-9
const int MAXN=200;
double a[MAXN][MAXN],x[MAXN];//方程的左边的矩阵和等式右边的值，求解之后x存的就是结果
int equ,var;//方程数和未知数个数

int Gauss()
{
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
          if(fabs(a[i][col])>fabs(a[max_r][col]))
            max_r=i;
        if(fabs(a[max_r][col])<eps)return 0;
        if(k!=max_r)
        {
            for(j=col;j<var;j++)
              swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j=col+1;j<var;j++)a[k][j]/=a[k][col];
        a[k][col]=1;
        for(i=0;i<equ;i++)
          if(i!=k)
          {
              x[i]-=x[k]*a[i][k];
              for(j=col+1;j<var;j++)a[i][j]-=a[k][j]*a[i][col];
              a[i][col]=0;
          }
    }
    return 1;
}

char map[20][20];
int num[20][20];
struct Node
{
    int x,y;
};
int sx,sy,ex,ey;
int n,m;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int cnt;

void bfs()
{
    memset(num,-1,sizeof(num));
    cnt=0;
    num[sx][sy]=cnt++;
    queue<Node>que;
    Node temp;
    Node tt;
    temp.x=sx;temp.y=sy;
    que.push(temp);
    while(!que.empty())
    {
        temp=que.front();
        que.pop();
        for(int i=0;i<4;i++)
        {
            tt.x=temp.x+dir[i][0];
            tt.y=temp.y+dir[i][1];
            if(tt.x>=0&&tt.x<n&&tt.y>=0&&tt.y<m&&map[tt.x][tt.y]!='X'&&num[tt.x][tt.y]==-1)
            {
                num[tt.x][tt.y]=cnt++;
                que.push(tt);
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",&map[i]);
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='D')
                {
                    sx=i;sy=j;
                }
                if(map[i][j]=='E')
                {
                    ex=i;ey=j;
                }
            }
        }
        bfs();
        if(num[ex][ey]==-1)
        {
            printf("tragedy!\n");
            continue;
        }
        memset(a,0,sizeof(a));
        memset(x,0,sizeof(x));
        equ=var=cnt;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
           if(num[i][j]!=-1)
           {
               int now=num[i][j];
               if(map[i][j]=='E')
               {
                   memset(a[now],0,sizeof(a[now]));
                   x[now]=0;
                   a[now][now]=1;
                   continue;
               }

               int Count=0;
               for(int k=0;k<4;k++)
               {
                   int tx=i+dir[k][0];
                   int ty=j+dir[k][1];
                   if(tx>=0&&tx<n&&ty>=0&&ty<m&&map[tx][ty]!='X'&&num[tx][ty]!=-1)
                   {
                       a[now][num[tx][ty]]=-1;
                       Count++;
                   }
                   a[now][now]=Count;
                   x[now]=Count;
               }
           }
        if(Gauss())
        {
            if(x[num[sx][sy]]<=1000000)printf("%.2lf\n",x[num[sx][sy]]);
            else printf("tragedy!\n");
        }
        else printf("tragedy!\n");
    }
    return 0;
}

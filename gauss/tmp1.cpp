/*
POJ 1681
*/

#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;

const int MAXN=300;

//有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
int equ,var;
int a[MAXN][MAXN];//增广矩阵
int x[MAXN];//解集

bool free_x[MAXN];//标记是否是不确定的变元
int free_num;//不确定变元个数


void Debug(void)
{
    int i, j;
    for (i = 0; i < equ; i++)
    {
        for (j = 0; j < var + 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int  Gauss()
{
    int i,j,k;
    int max_r;
    int col;
    int temp;

    int free_x_num;
    int free_index;

    col=0;
    for(k=0;k<equ&&col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
        {
            if(abs(a[i][col])>abs(a[max_r][col]))max_r=i;
        }
        if(max_r!=k)
        {
            for(j=col;j<var+1;j++)swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0)
        {
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++)
        {
            if(a[i][col]!=0)
            {
                for(j=col;j<var+1;j++)
                  a[i][j]^=a[k][j];
            }
        }
    }
    for(i=k;i<equ;i++)
    {
        if(a[i][col]!=0)return -1;//无解
    }
    for(i=var-1;i>=0;i--)
    {
        x[i]=a[i][var];
        for(j=i+1;j<var;j++)
          x[i]^=(a[i][j]&&x[j]);
    }
    return 0;
}


int n;

void init()
{
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    memset(free_x, 1, sizeof(free_x)); // 一开始全是不确定的变元.
    equ=n*n;
    var=n*n;
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
       {
           int t=i*n+j;
           a[t][t]=1;
           if(i>0)a[(i-1)*n+j][t]=1;
           if(i<n-1)a[(i+1)*n+j][t]=1;
           if(j>0)a[i*n+j-1][t]=1;
           if(j<n-1)a[i*n+j+1][t]=1;
       }
}
char str[20];

int main()
{
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        init();
        for(int i=0;i<n;i++)
        {
            scanf("%s",&str);
            for(int j=0;j<n;j++)
            {
                if(str[j]=='y')a[i*n+j][n*n]=0;
                else a[i*n+j][n*n]=1;
            }
        }

		for(int i=0;i<25;++i){
		for(int j=0;j<=25;++j){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}

       /* int t=Gauss();
        if(t==-1)
        {
            printf("inf\n");
            continue;
        }

        int ans=0;
        for(int i=0;i<n*n;i++)
          if(x[i]==1)ans++;

        printf("%d\n",ans);*/
    }
    return 0;
}

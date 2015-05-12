#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=110;
const int INF=0x3f3f3f3f;

int n,m;
double map[N][N],dis[N];
int vis[N];

void gao(int src){
    int i;
    for(i=1;i<=n;i++){
        dis[i]=map[src][i];
        vis[i]=0;
    }
    dis[src]=1;
    int j,k;
    double tmp;
    for(i=1;i<n;i++){
        tmp=0;
        for(j=1;j<=n;j++)
            if(!vis[j] && tmp<dis[j]){
                tmp=dis[j];
                k=j;
            }
        if(tmp==0)
            break;
        vis[k]=1;
        for(j=1;j<=n;j++)
            if(!vis[j] && dis[j]<dis[k]*map[k][j])
                dis[j]=dis[k]*map[k][j];
    }
}

int main(){
    while(scanf("%d",&n) && n){
        scanf("%d",&m);
        memset(map,0,sizeof(map));
        int a,b,p;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&p);
            map[a][b]=map[b][a]=p/100.0;
        }
        gao(1);
        printf("%.6f percent\n",dis[n]*100);
    }
    return 0;
}

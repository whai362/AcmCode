#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
const int INF = 1000000007;

vector<int> e[200];
int n,m,w,a[200],u[100];
int dp[200][128];
PII pt[200][128];
char o[105][105];

void add_edge(int t, int p, int q){
    if(p<0 || q<0 || p>=n || q>=m) return;
    e[t].push_back(p*m+q);
}

void getans(int x, int s){
    if(x<0) return;
    o[x/m][x%m]='X';
    int y,p;
    tie(y,p)=pt[x][s];
    getans(y,p);
    if(p!=s && p>=0) getans(y,p^s);
}

int main(){
    scanf("%d%d%d",&n,&m,&w);
    memset(dp,63,sizeof(dp));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        int t=i*m+j;
        scanf("%d",a+t);
        o[i][j]='.';
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        int t=i*m+j;
        add_edge(t,i-1,j);
        add_edge(t,i+1,j);
        add_edge(t,i,j-1);
        add_edge(t,i,j+1);
    }
    for(int i=0;i<w;i++){
        int r,c;
        scanf("%d%d",&r,&c);
        u[i]=(r-1)*m+c-1;
        dp[u[i]][1<<i]=a[u[i]];
        pt[u[i]][1<<i]={-1,-1};
    }
    int mask=(1<<w)-1,nm=n*m;
    for(int s=1;s<=mask;s++){
        for(int x=0;x<nm;x++) for(int p=(s-1)&s;p;p=(p-1)&s){
            int q=s^p,use=dp[x][p]+dp[x][q]-a[x];
            if(use<dp[x][s]){
                dp[x][s]=use;
                pt[x][s]={x,p};
            }
        }
        queue<int> q;
        bool in[200];
        for(int x=0;x<nm;in[x++]=true) q.push(x);
        while(q.size()){
            int x=q.front();
            q.pop();
            in[x]=false;
            for(auto y:e[x]){
                int use=dp[x][s]+a[y];
                if(use<dp[y][s]){
                    dp[y][s]=use;
                    pt[y][s]={x,s};
                    if(!in[y]){
                        in[y]=true;
                        q.push(y);
                    }
                }
            }
        }
    }
    int v=0;
    for(int i=0;i<nm;i++) if(dp[i][mask]<dp[v][mask]) v=i;
    printf("%d\n",dp[v][mask]);
    getans(v,mask);
    for(int i=0;i<n;i++) puts(o[i]);
}

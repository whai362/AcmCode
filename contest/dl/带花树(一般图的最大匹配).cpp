/*大致题意：
    给出n个士兵，再给出多组士兵之间两两可以匹配的关系。已知某个士兵最多只能与一个士兵匹配。求最多能够有多少对匹配，并输出这些匹配。
 
大致思路：
    最大匹配问题，对于二分图来说用的是匈牙利算法，求一般图最大匹配用的是带花树开花算法。这里面要注意一点，输出匹配时，要把match[i]和match[match[i]]同时设为-1。*/
//链接: http://bbezxcy.iteye.com/blog/1488104
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXE 250*250*2
#define MAXN 250
#define SET(a,b) memset(a,b,sizeof(a))
deque<int> Q;
//g[i][j]存放关系图：i,j是否有边,match[i]存放i所匹配的点
bool g[MAXN][MAXN],inque[MAXN],inblossom[MAXN];
int match[MAXN],pre[MAXN],base[MAXN];

//找公共祖先
int findancestor(int u,int v){
    bool inpath[MAXN]={false};
    while(1){
        u=base[u];
        inpath[u]=true;
        if(match[u]==-1)break;
        u=pre[match[u]];
    }
    while(1){
        v=base[v];
        if(inpath[v])return v;
        v=pre[match[v]];
    }
}

//压缩花
void reset(int u,int anc){
    while(u!=anc){
        int v=match[u];
        inblossom[base[u]]=1;
        inblossom[base[v]]=1;
        v=pre[v];
        if(base[v]!=anc)pre[v]=match[u];
        u=v;
    }
}

void contract(int u,int v,int n){
    int anc=findancestor(u,v);
    //SET(inblossom,0);
    memset(inblossom,0,sizeof(inblossom));
    reset(u,anc);reset(v,anc);
    if(base[u]!=anc)pre[u]=v;
    if(base[v]!=anc)pre[v]=u;
    for(int i=1;i<=n;i++)
        if(inblossom[base[i]]){
            base[i]=anc;
            if(!inque[i]){
                Q.push_back(i);
                inque[i]=1;
            }
        }
}

bool dfs(int S,int n){
    for(int i=0;i<=n;i++)pre[i]=-1,inque[i]=0,base[i]=i;
    Q.clear();Q.push_back(S);inque[S]=1;
    while(!Q.empty()){
        int u=Q.front();Q.pop_front();
        for(int v=1;v<=n;v++){
            if(g[u][v]&&base[v]!=base[u]&&match[u]!=v){
                if(v==S||(match[v]!=-1&&pre[match[v]]!=-1))contract(u,v,n);
                else if(pre[v]==-1){
                    pre[v]=u;
                    if(match[v]!=-1)Q.push_back(match[v]),inque[match[v]]=1;
                    else{
                        u=v;
                        while(u!=-1){
                            v=pre[u];
                            int w=match[v];
                            match[u]=v;
                            match[v]=u;
                            u=w;
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    int n,m,a,b,ans,i;
    while(scanf("%d",&n)!=EOF){
        ans=0;          //最多有几对匹配
        memset(match,-1,sizeof(match));
        memset(g,0,sizeof(g));
        while(scanf("%d%d",&a,&b)!=EOF&&a!=0){
            g[a][b]=g[b][a]=1;
        }
        for(i=1;i<=n;i++){
            if(match[i]==-1&&dfs(i,n)){
                ans++;
            }
        }
        cout<<ans*2<<endl;
        for(i=1;i<=n;i++){
            if(match[i]!=-1){
                printf("%d %d\n",i,match[i]);
                match[i]=match[match[i]]=-1;
            }
        }
    }
    return 0;
}


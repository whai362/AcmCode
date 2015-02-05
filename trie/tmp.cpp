#include<cstdio>  
#include<cstring>  
#define N 100100  
#define M 2  
using namespace std;  
int n;  
struct Edge{  
    int v,w,next;  
}edge[N*2];  
int head[N],cnt,cou;  
int dis[N];  
void addedge(int u,int v,int w){  
    edge[cnt].v=v,edge[cnt].w=w,edge[cnt].next=head[u],head[u]=cnt++;  
    edge[cnt].v=u,edge[cnt].w=w,edge[cnt].next=head[v],head[v]=cnt++;  
}  
void init(){  
    memset(head,-1,sizeof(head));  
    cnt=cou=0;  
}  
void dfs(int u,int fa){  
    int i;  
    for(i=head[u];i!=-1;i=edge[i].next){  
        int v=edge[i].v;  
        if(v==fa)continue;  
        dis[v]=dis[u]^edge[i].w;  
        dfs(v,u);  
    }  
}  
struct Trie {  
    int s[M];  
    int end;  
    void clear(){  
        memset(s,-1,sizeof(s));  
        end=0;  
    }
}trie[N*33];  
void insert(int id){
    int cur=0,i;
    for(i=30;i>=0;i--){
        int tem=(1<<i)&id;
        if(tem)tem=1;
        if(trie[cur].s[tem]==-1){  
            trie[cou].clear();
            trie[cur].s[tem]=cou;  
            cur=cou++;
        }
        else  
            cur=trie[cur].s[tem];  
    }  
    trie[cur].end=id;  
}
int query(int id){  
    int cur=0,i;  
    for(i=30;i>=0;i--){  
        int tem=(1<<i)&id;  
        if(tem)tem=1;  
        if(trie[cur].s[!tem]!=-1)  
            cur=trie[cur].s[!tem];  
        else if(trie[cur].s[tem]!=-1)  
            cur=trie[cur].s[tem];  
        else  
            break;  
    }  
    return trie[cur].end^id;  
}  
int main(){  
    int u,v,w;  
    int i,j;  
    while(scanf("%d",&n)==1){  
        init();  
        for(i=1;i<n;i++){  
            scanf("%d %d %d",&u,&v,&w);  
            addedge(u,v,w);  
        }  
        dis[0]=0;  
        dfs(0,-1);  
        int ans=0;  
        trie[cou++].clear();  
        for(i=0;i<n;i++){  
            insert(dis[i]);  
            int tem=query(dis[i]);  
            if(ans<tem)ans=tem;  
        }  
        printf("%d\n",ans);  
    }  
}

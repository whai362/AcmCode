#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

#define LL long long 
const int maxn = 1e6+5;

int n,m,k;

int head[maxn];
struct EDGE{
    int to,nxt;
}edge[maxn*2]; int mm;
void addedge(int from ,int to){
    mm++;
    edge[mm].to = to;
    edge[mm].nxt = head[from];
    head[from] = mm;
}

struct NODE{
    int id,v;
}node[maxn];
bool cmpv(NODE a,NODE b){
    return a.v < b.v;
}

bool vis[maxn] , used[maxn];
int dfs(int x){
    vis[x] = true;
    int res = x;
    for(int side=head[x];side!=-1;side=edge[side].nxt){
        int to = edge[side].to;
        if ( !vis[to] ){
            int id = dfs(to);
            if ( node[res].v > node[id].v )
                res = id;
        }
    }
    return res;
}

int main(){

    int t; scanf("%d",&t);
    for(int it=1;it<=t;it++){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&node[i].v);
            node[i].id = i;
            node[i].v;
        }

        int u,v; mm = 0;
        for(int i=1;i<=n;i++) head[i] = -1;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v); addedge(v,u);
        }
        
        int cnt = 0; LL ans = 0;
        memset(used,false,sizeof(used));
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++){
            if ( !vis[i] ){
                int id = dfs(i);
                used[id] = true;
                ans += node[id].v;
                cnt++;
            }
        }
        int h = m-(n-1)+cnt-1;
        k -= h;
        if ( k>0 ){
            sort(node+1,node+n+1,cmpv);
            for(int i=1;i<=n;i++){
                int id = node[i].id;
                if ( used[id] ) continue;
                k--;
                ans += node[i].v;
                if ( k==0 ) break;
            }
        }
        printf("Case #%d: %lld\n",it,ans);
    }
    return 0;
}

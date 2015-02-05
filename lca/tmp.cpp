#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)

using namespace std;

typedef long long ll;
typedef pair<int ,int> pii;
typedef pair<unsigned int, unsigned int> puu;
typedef pair<int ,double> pid;
typedef pair<ll, int> pli;

const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int LEN = 100010;
const int LOG_LEN = 22;
vector<int> Map[LEN];
int ind[LEN], root, parent[LOG_LEN][LEN], depth[LEN];

void dfs(int v, int p, int d)
{
    depth[v] = d;
    parent[0][v] = p;
    for(int i=0; i<Map[v].size(); i++){
        if(Map[v][i]!=p) dfs(Map[v][i], v, d+1);
    }
}

void init(int n)
{
    dfs(root, -1, 0);
    for(int k=0; k+1<LOG_LEN; k++){
        for(int i=1; i<=n; i++){
            if(parent[k][i] < 0) parent[k+1][i] = -1;
            else parent[k+1][i] = parent[k][parent[k][i]];
        }
    }
}

int lca(int u, int v)
{
    if(depth[u] > depth[v]) swap(u, v);
    for(int i=0; i<LOG_LEN; i++){
        if((depth[v]-depth[u]) >> i & 1) v = parent[i][v];
    }
    if(u==v) return u;
    for(int i=LOG_LEN-1; i>=0; i--){
        if(parent[i][u]!=parent[i][v]){
            v = parent[i][v];
            u = parent[i][u];
        }
    }
    return parent[0][u];
}

int main()
{
//    freopen("in.txt", "r", stdin);

    int T, n, a, b;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        memset(ind, 0, sizeof ind);
        for(int i=0; i<LEN; i++)Map[i].clear();
        for(int i=0; i<n-1; i++){
            scanf("%d%d", &a, &b);
            Map[a].PB(b);
            Map[b].PB(a);
            ind[b]++;
        }
        for(int i=1; i<=n; i++)if(!ind[i]){root = i;break;}
        init(n);
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}

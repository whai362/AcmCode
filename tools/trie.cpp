/*poj 3764
  题意：
  给你一棵树，n个节点（n = 100000），n-1条边每条边i都有一个权值wi。
  定义任意两点间的权值为：
  这两点间的路径上的所有边的值的异或。
  比如a点和b点间有i，j，k三条边，那么ab两点间的权值为：wi^wj^wk
  求这个最大的权值。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define pb push_back
const int N = 100005;
struct Edge {
    int to, w, next;
} edge[N * 2];
int head[N], tot;
void addedge(int u, int v, int w) {
    edge[tot].to = v, edge[tot].w = w, edge[tot].next = head[u], head[u] = tot++;
    edge[tot].to = u, edge[tot].w = w, edge[tot].next = head[v], head[v] = tot++;
}

int n;
int dis[N];

const int MAXB = 2;
int Ntot = 0;
struct Node {
    int br[MAXB];
    int num;
    void clear() {
        memset(br, -1, sizeof(br));
        num = 0;
    }
} node[N * 33];
void insert(int x) {
    int cur = 0;
    for (int i = 30; i >= 0; --i) {
        int id = ((1 << i) & x) > 0 ? 1 : 0;
        if (node[cur].br[id] == -1) {
            node[Ntot].clear();
            node[cur].br[id] = Ntot;
            cur = Ntot++;
        }
        else {
            cur = node[cur].br[id];
        }
    }
    node[cur].num = x;
}
int find(int x) {
    int cur = 0;
    for (int i = 30; i >= 0; --i) {
        int id = ((1 << i) & x) > 0 ? 1 : 0;
        if (node[cur].br[!id] != -1) {
            cur = node[cur].br[!id];
        }
        else if (node[cur].br[id] != -1) {
            cur = node[cur].br[id];
        }
        else break;
    }
    return x ^ node[cur].num;
}

void dfs(int pa, int fa, int xs) {
    dis[pa] = xs;
    for (int i = head[pa]; i != -1; i = edge[i].next) {
        int to = edge[i].to;
        if (to == fa) continue;
        dfs(to, pa, xs ^ edge[i].w);
    }
}
void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
    Ntot = 0;
    node[Ntot++].clear();
}
int main() {
    int u, v, w;
    while (scanf("%d", &n) != EOF) {
        init();
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
        }
        dfs(0, -1, 0);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            insert(dis[i]);
            ans = max(ans, find(dis[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}

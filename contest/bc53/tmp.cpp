#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , a , K , pre[N] , mcnt;
const LL inf = 0xC0C0C0C0C0C0C0C0LL;
struct edge {
    int x , next;
}e[N << 1];
int w[N] , size[N];
LL s[N] , f[N][501] , g[2][501];

void dfs(int x , int fa) {
    s[x] = w[x] , size[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x);
            s[x] += s[y];
            size[x] += size[y];
        }
    }
    int cur = 0 , nxt = 1;
    memset(g[cur] , 0xC0 , K + 1 << 3);
    g[cur][0] = w[x];
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            memset(g[nxt] , 0xC0 , K + 1 << 3);            
            for (int j = 0 ; j <= K ; ++ j) {
                if (g[cur][j] == inf)
                    continue;
                g[nxt][j] = max(g[nxt][j] , g[cur][j]);
                if (j < K)
                    g[nxt][j + 1] = max(g[nxt][j + 1] , g[cur][j] + a * s[y]);
                for (int k = 0 ; k <= size[y] && j + k <= K ; ++ k) {
                    g[nxt][j + k] = max(g[nxt][j + k] , g[cur][j] + f[y][k]);
                }
            }            
            swap(cur , nxt);
        }
    }
    memcpy(f[x] , g[cur] , K + 1 << 3);        
}

void work() {
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &w[i]);
    }
    memset(pre , -1 , sizeof(pre));
    mcnt = 0;
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0);
    LL res = inf;
    for (int i = 0 ; i <= K ; ++ i)
        res = max(res , f[1][i]);
    printf("%I64d\n" , res);
}

int main() {
    int __size__ = 256 << 20; // 256MB
    char *__p__ = (char*)malloc(__size__) + __size__;
    __asm__("movl %0, %%esp\n" :: "r"(__p__));

    while (~scanf("%d%d%d" , &n , &a , &K))
        work();
    return 0;
}

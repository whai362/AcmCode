#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <cassert>
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define MOD 1000000007
#define MAXN 1005
template <typename T> inline void checkMax(T &a, T b) {a = a>b?a:b;}
template <typename T> inline void checkMin(T &a, T b) {a = a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
const double eps = 1e-8;
int T, N, K, Cas = 1;

LL dp[MAXN][MAXN], cnm[MAXN][MAXN], g[MAXN];

int head[MAXN], cnt, sz[MAXN], leaf[MAXN];

struct Edge {
    int v, next;
} p[MAXN << 1];

void Init() {
    g[0] = g[1] = 1;
    for (int i = 2; i <= 1000; i ++) g[i] = (g[i - 1] * i) % MOD;
    for (int i = 0; i <= 1000; i ++) cnm[i][i] = cnm[i][0] = 1;
    for (int i = 2; i <= 1000; i ++) {
        for (int j = 1; j < i; j ++) {
            cnm[i][j] = (cnm[i - 1][j - 1] + cnm[i - 1][j]) % MOD;
        }
    }
}

void init() {
    cnt = 0;
    fill(head, head + MAXN, -1);
    memset(p, 0, sizeof(p));
    memset(sz, 0, sizeof(sz));
    memset(dp, 0, sizeof(dp));
    memset(leaf, 0, sizeof(leaf));
}

void addEdge(int u, int v) {
    p[cnt].v = v;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}

void dfs(int u, int fa) {
    sz[u] = 1;
    for (int i = head[u]; i != -1; i = p[i].next) {
        int v = p[i].v;
        if (v != fa) {
            dfs(v, u);
            sz[u] += sz[v];
            leaf[u] += leaf[v];
        }
    }
    if (sz[u] == 1) {
        leaf[u] = 1;
    }
}


void gao(int u, int fa) {
    if (sz[u] == 1) {
        dp[u][1] = 1;
        return ;
    }
    LL mul = 1ll;
    int pre = 0, now = 1, Size = sz[u] - 1;
    LL tmp[2][MAXN];
    fill(tmp[pre], tmp[pre] + K + 1, 0);
    tmp[pre][0] = 1ll;
    for (int i = head[u]; i != -1; i = p[i].next) {
        int v = p[i].v;
        if (v != fa) {
            gao(v, u);
            mul = mul * cnm[Size][sz[v]] ;
            Size -= sz[v];
            fill(tmp[now], tmp[now] + K + 1, 0);
            int minindex = leaf[v], maxindex = sz[v];
            for (int j = 0; j <= K; j ++) {
                if (tmp[pre][j] == 0) continue;
                for (int k = minindex; k <= maxindex; k ++) {
                    if (j + k > K) break;
                    LL add = dp[v][k];
                    tmp[now][j + k] = (tmp[now][j + k] + tmp[pre][j] * add) % MOD;
                }
            }
            swap(now, pre);
        }
    }
    for (int i = leaf[u]; i <= sz[u]; i ++) {
        dp[u][i] = (dp[u][i] + tmp[pre][i - 1] * mul) % MOD;
        dp[u][i] = (dp[u][i] + ((tmp[pre][i] * mul) % MOD) * (sz[u] - 1)) % MOD;
    }
}

void work() {
    init();
    scanf("%d %d", &N, &K);
    for (int i = 1; i < N; i ++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1, 1);
    gao(1, 1);
    printf("Case #%d: ", Cas ++);
    LL res = dp[1][K] % MOD;
    cout << res << endl;
}
int main() {
#ifdef __SKT__
    freopen("in", "r", stdin);
#endif
    Init();
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}

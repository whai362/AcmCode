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
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define MAXN 1005
template <typename T> inline void checkMax(T &a, T b) {a = a>b?a:b;}
template <typename T> inline void checkMin(T &a, T b) {a = a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
const double eps = 1e-8;
int T, N, M;

int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int a[MAXN][MAXN], len[MAXN][MAXN];

bool vis[MAXN][MAXN], has[MAXN][MAXN], is[MAXN][MAXN];

char str[MAXN];

vector<PII> gao() {
    vector<PII> point;
    if (a[1][1] == 0) {
        vis[1][1] = true;
        is[1][1] = true;
        queue<PII> Q;
        Q.push(mp(1, 1));
        while (!Q.empty()) {
            PII now = Q.front(); Q.pop();
            for (int i = 0; i < 4; i ++) {
                PII next = now;
                next.x += dir[i][0];
                next.y += dir[i][1];
                if (next.x >= 1 && next.x <= N && next.y >= 1 && next.y <= M) {
                    if (!vis[next.x][next.y]) {
                        if (a[next.x][next.y]) {
                            if (!has[next.x][next.y]) {
                                has[next.x][next.y] = true;
                                point.push_back(next);
                            }
                        } else {
                            vis[next.x][next.y] = true;
                            Q.push(next);
                        }
                    }
                }
            }
        }
    } else {
        point.push_back(mp(1, 1));
    }
    return point;
}

int bfs1(vector<PII> &point) {
    queue<PII> Q;
    Q.push(mp(N, M));
    len[N][M] = 1;
    vis[N][M] = true;
    while (!Q.empty()) {
        PII now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i ++) {
            PII next = now;
            next.x += dir[i][0];
            next.y += dir[i][1];
            if (next.x >= 1 && next.x <= N && next.y >= 1 && next.y <= M) {
                if (!vis[next.x][next.y]) {
                    len[next.x][next.y] = len[now.x][now.y] + 1;
                    vis[next.x][next.y] = true;
                    Q.push(next);
                }
            }
        }
    }
    int minlen = N * M + 1;
    for (int i = 0; i < point.size(); i ++) {
        minlen = min(minlen, len[point[i].x][point[i].y]);
    }
    return minlen;
}

void bfs(vector<PII> &point, int minlen) {
    queue <PII> Q;
    for (int i = 0; i < point.size(); i ++) {
        if (len[point[i].x][point[i].y] == minlen) {
            Q.push(point[i]);   
            is[point[i].x][point[i].y] = true;
        }
    }
    while (!Q.empty()) {
        vector<PII> tmp;
        int c = 1;
        while (!Q.empty()) {
            PII now = Q.front();
            c = min(a[now.x][now.y], c);
            Q.pop();
            tmp.push_back(now);
        }
        printf("%d", c);
        if (minlen == 1) {
            tmp.clear();
            break;
        }
        for (int i = 0; i < tmp.size(); i ++) {
            if (a[tmp[i].x][tmp[i].y] == c) {
                for (int j = 0; j < 4; j ++) {
                    PII next = tmp[i];
                    next.x += dir[j][0];
                    next.y += dir[j][1];
                    if (len[next.x][next.y] + 1 == len[tmp[i].x][tmp[i].y]) {
                        if (!is[next.x][next.y]) {
                            is[next.x][next.y] = true;
                            Q.push(next);
                        }
                    }
                }
            }
        }
        tmp.clear();
        minlen --;
    }
}

void work() {
    memset(len, -1, sizeof(len));
    memset(vis, 0, sizeof(vis));
    memset(has, 0, sizeof(has));
    memset(is, 0, sizeof(is));
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i ++) {
        scanf("%s", str + 1);
        for (int j = 1; j <= M; j ++) {
            a[i][j] = str[j] == '1' ? 1 : 0;
        }
    }
    vector<PII> point = gao();
    if (vis[N][M]) {
        printf("0\n");
    } else {
        int clen = bfs1(point);
        bfs(point, clen);
        printf("\n");
    }
}
int main() {
#ifdef __SKT__
    freopen("in", "r", stdin);
#endif
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}

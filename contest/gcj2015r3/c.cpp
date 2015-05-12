#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
int T, Cas = 1, C, D, V, d[MAXN];

bool dp[MAXN];

const int INF = 0x3fffffff;

bool vis[MAXN], is[MAXN];

int small_ans = 5;


bool check() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= V; i ++) {
        if (is[i]) {
            for (int j = V; j >= i; j --) {
                dp[j] |= dp[j - i];
            }
        }
    }
    for (int i = 1; i <= V; i ++) {
        if (dp[i] == false) {
            return false;
        }
    }
    return true;
}

void dfs(int top, int pre) {
    if (check()) {
        small_ans = min(small_ans, top);
    }
    if (top == 4) {
        return ;
    }
    for (int i = pre; i <= V; i ++) {
        if (!is[i]) {
            is[i] = true;
            dfs(top + 1, i + 1);
            is[i] = false;
        }
    }
}

int small_task() {
    dfs(0, 1);
    return small_ans;
}

void work() {
    small_ans = 5;
    printf("Case #%d:", Cas ++);
    scanf("%d %d %d", &C, &D, &V);
    memset(is, 0, sizeof(is));
    for (int i = 1; i <= D; i ++) {
        scanf("%d", &d[i]);
        is[d[i]] = true;
    }
    printf(" %d\n", small_task());
}
int main() {
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}


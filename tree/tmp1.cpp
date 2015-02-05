#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
    int v, l;
    node() {};
    node(int _v, int _l):v(_v), l(_l) {};
};
#define N 10015
int n, m, K, size, root, s[N], f[N], d[N], ans;
bool done[N], ok;
vector<int> dep;
vector<node> g[N];

void getroot(int now, int fa) {
    int u;
    s[now] = 1; f[now] = 0;
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i].v) != fa && !done[u]) {
            getroot(u, now);
            s[now] += s[u];
            f[now] = max(f[now], s[u]);
        }
    f[now] = max(f[now], size-s[now]);
    if (f[now] < f[root]) root = now;
}
void getdep(int now, int fa) {
    dep.push_back(d[now]);
    int u; s[now] = 1;
    for (int i=0; i<g[now].size(); i++)
        if ((u = g[now][i].v) != fa && !done[u]) {
            d[u] = d[now] + g[now][i].l;
            getdep(u, now);
            s[now] += s[u];
        }
}
int calc(int now, int init) {
    d[now] = init; dep.clear();
    getdep(now, 0);
    sort(dep.begin(), dep.end());
    int ret = 0;
    for (int l=0, r=dep.size()-1; l<r; ) {
        if (dep[l] + dep[r] == K) {
            if (dep[l] == dep[r]) {
                ret += (r-l+1)*(r-l)/2; break;
            }
            int i=l, j=r;
            while (dep[i] == dep[l]) i++;
            while (dep[j] == dep[r]) j--;
            ret += (i-l)*(r-j);
            l = i, r = j;
        } else if (dep[l] + dep[r] < K) l++;
        else r--;
    }
    return ret;
}
void work(int now) {
    ans += calc(now, 0);
    int u;
    done[now] = true;
    for (int i=0; i<g[now].size(); i++)
        if (!done[u = g[now][i].v]) {
            ans -= calc(u, g[now][i].l);
            f[0] = size = s[u];
            getroot(u, root=0);
            work(root);
        }
}
void solve() {
    memset(done, false, sizeof(done));
    f[0] = size = n;
    getroot(1, root=0);
    ans = 0;
    work(root);
	cout<<ans<<endl;
    //puts(ans ? "AYE" : "NAY");
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d", &n) == 1 && n) {
        for (int i=0; i<=n; i++) g[i].clear();
        int a, b;
        for (int i=1; i<=n; i++) {
            while (scanf("%d", &a) && a) {
                scanf("%d", &b);
                g[i].push_back(node(a, b));
                g[a].push_back(node(i, b));
            }
        }
        while (scanf("%d", &K) == 1 && K) solve();
        puts(".");
    }

    return 0;
}


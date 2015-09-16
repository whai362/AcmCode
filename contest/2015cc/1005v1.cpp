#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL __int64

const int M = 1e5 + 5;

struct E {
    int u, v, c;
}e[M];

bool cmp(E a, E b) {
    return a.c < b.c;
}

LL s[M];
int a[M];

const int N = 2 * 1e4 + 5;

int fa[N];
int cnt[N];

int get_fa(int x) {
    if(x != fa[x]) return fa[x] = get_fa(fa[x]);
    return x;
}

void init(int n) {
    for(int i = 0; i <= n; ++i) {
        fa[i] = i;
        cnt[i] = 1;
    }
    memset(s, 0, sizeof(s));
}

LL Cn2(int n) {
    if(n < 2) return 0;
    return (LL)(n) * (n - 1);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        init(n);
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
            a[i] = e[i].c;
        }
        sort(e, e + m, cmp);
        sort(a, a + m);
        for(int i = 0; i < m; ++i) {
            int u = e[i].u;
            int v = e[i].v;
            int fu = get_fa(u);
            int fv = get_fa(v);
            if(fu == fv) continue;
            s[i] = cnt[fu] * cnt[fv];
            fa[fv] = fu;
            cnt[fu] += cnt[fv];
            cnt[fv] = 0;
        }
        //for(int i = 0; i < m; ++i) {
        //    cout<<s[i]<<' ';
        //}
        //cout<<endl;
        for(int i = 1; i < m; ++i) {
            s[i] += s[i - 1];
        }
        //for(int i = 0; i < m; ++i) {
        //    cout<<s[i]<<' ';
        //}
        //cout<<endl;
        s[m] = s[m - 1];
        for(int i = 0; i < q; ++i) {
            int x;
            scanf("%d", &x);
            int p = upper_bound(a, a + m, x) - a;
            LL ans = s[p - 1];
            if(p < 0) cout<<0<<endl;
            else cout<<ans*2<<endl;
        }
    }
    return 0;
}

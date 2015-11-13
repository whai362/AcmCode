/*======================================================
# Author: whai
# Last modified: 2015-11-05 01:36
# Filename: d.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 2 * 1e5 + 5;

const int LOGN = 22;

vector<int> tree[N];

int fa[N][LOGN];
int depth[N];
//map<P, LL> C;
unordered_map<LL, LL> C;
LL get_p(int x, int y) {
	return (LL)x * N + y;
}

void dfs(int u, int p, int d) {
    depth[u] = d;
    fa[u][0] = p;
    for (int i = 0; i < tree[u].size(); ++i) {
        if (tree[u][i] != p)
            dfs(tree[u][i], u, d + 1);
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int i = 0; i < LOGN; ++i) {
        if (((depth[v] - depth[u]) >> i) & 1)
            v = fa[v][i];
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int f[N];
int get_fa(int x) {
	if(x != f[x]) return f[x] = get_fa(f[x]);
	return x;
}

void predo(int n) {
    int root = 1;
    dfs(root, 0, 0);
	depth[0] = -1;
    for (int j = 0; j + 1 < LOGN; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (fa[i][j] < 0) fa[i][j + 1] = -1;
            else fa[i][j + 1] = fa[fa[i][j]][j];
        }
    }
	for(int i = 0; i <= n; ++i) {
		f[i] = i;
	}
}

void init(int n) {
    for (int i = 0; i <= n; ++i)
        tree[i].clear();
}

LL s[N], tot;

void Q1(int a, int b, LL y) {
    int ac = LCA(a, b);
    int now = a;
    LL ans = y;
    while(depth[now] > depth[ac]) {
        int nxt = fa[now][0];
        int u = now, v = nxt;
        if(u > v) swap(u, v);
        LL c = C[get_p(u, v)];
		if(c == 1) {
			int f_now = get_fa(now);
			int f_nxt = get_fa(nxt);
			f[f_now] = f_nxt;
			now = f_nxt;
		} else {
			ans /= c;
			now = get_fa(nxt);
		}
        if(ans == 0) break;
    }
    if(ans == 0) {
        puts("0");
        return ;
    }

    tot = 0;
    now = b;
    LL tmp = ans;
    while(depth[now] > depth[ac]) {
        int nxt = fa[now][0];
        int u = now, v = nxt;
        if(u > v) swap(u, v);
        LL c = C[get_p(u, v)];
		if(c == 1) {
			int f_now = get_fa(now);
			int f_nxt = get_fa(nxt);
			f[f_now] = f_nxt;
			now = f_nxt;
		} else {
			tmp /= c;
			s[tot++] = c;
			now = get_fa(nxt);
		}
        if(tmp == 0) break;
    }
    if(tmp == 0) {
        puts("0");
        return ;
    }
    for(int i = tot - 1; i >= 0; --i) {
        ans /= s[i];
    }
    printf("%I64d\n", ans);
}
int u[N], v[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    LL c;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%I64d", &u[i], &v[i], &c);
        if(u[i] > v[i]) swap(u[i], v[i]);
        tree[u[i]].PB(v[i]);
        tree[v[i]].PB(u[i]);
        C[get_p(u[i], v[i])] = c;
    }
    predo(n);
    for(int i = 0; i < m; ++i) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int a, b;
            LL y;
            scanf("%d%d%I64d", &a, &b, &y);
            Q1(a, b, y);
        } else {
            int a;
            LL y;
            scanf("%d%I64d", &a, &y);
            C[get_p(u[a], v[a])] = y;
        }
    }
    return 0;
}

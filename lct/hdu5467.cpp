#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL __int64
#define LS(x) node[(x)].ch[0]
#define RS(x) node[(x)].ch[1]
#define P pair<int ,int>
#define X first
#define Y second
#define PB push_back

const int N = 3 * 1e5 + 5;

const int MOD = 1000000007;

int a[N];

set<P> used;
set<P>::iterator it;

struct LCT {
    struct Node {
        int fa, ch[2];
        bool rev;
        int size;
        void init(LL x) {
            fa = 0;
            rev = ch[0] = ch[1] = 0;
            size = (LL)x * (x - 1) / 2;
        }
    } node[N];

    bool is_root(int x) {
        return (LS(node[x].fa) != x && RS(node[x].fa) != x);
    }

    void down(int x) {
        if(node[x].rev) {
            node[LS(x)].rev ^= 1;
            node[RS(x)].rev ^= 1;
            swap(LS(x), RS(x));
            node[x].rev = 0;
        }
    }

    void up(int x) {
        node[x].size = (LL)a[x] * (a[x] - 1) / 2 * node[LS(x)].size % MOD * node[RS(x)].size % MOD;
    }

    void rotate(int x, bool kind) {
        int fx = node[x].fa;
        int ffx = node[fx].fa;
        node[fx].ch[!kind] = node[x].ch[kind];
        node[node[x].ch[kind]].fa = fx;
        
        if(!is_root(fx))
            node[ffx].ch[RS(ffx) == fx] = x;
        node[x].fa = ffx;

        node[x].ch[kind] = fx;
        node[fx].fa = x;
        up(fx);
    }

    int d_st[N], ds_top;

    void splay(int x) {
        ds_top = -1;
        d_st[++ds_top] = x;
        for(int i = x; !is_root(i); i = node[i].fa)
            d_st[++ds_top] = node[i].fa;
        for(int i = ds_top; i >= 0 ; --i) down(d_st[i]);

        while(!is_root(x)) {
            int fx = node[x].fa;
            int ffx = node[fx].fa;
            bool rot_x = (LS(fx) == x);
            bool rot_fx = (LS(ffx) == fx);
            if(is_root(fx)) rotate(x, rot_x);
            else {
                if(rot_x == rot_fx) rotate(fx, rot_fx);
                else rotate(x, rot_x);
                rotate(x, rot_fx);
            }
        }
        up(x);
    }

    void access(int x) {
        int last = 0;
        while(x) {
            splay(x);
            RS(x) = last;
            last = x;
            x = node[x].fa;
        }
    }

    //access(x); splay(x); 后x在根的位置，此时x只有左子树，没有右子树，打翻转标记就是使得左子树变到右子树上。
    void make_root(int x) {
        access(x); splay(x);
        node[x].rev ^= 1;
    }

    int find(int x) {
        access(x); splay(x);
        while(LS(x)) x = LS(x);
        return x;
    }

    bool cut(int x, int y) {
        if(x > y) swap(x, y);
        it = used.find(P(x, y));
        if(it == used.end()) return false;

        make_root(x);
        access(y); splay(y);
        LS(y) = node[x].fa = 0;
        up(y);

        used.erase(it);
        return true;
    }

    bool link(int x, int y) {
        if(x > y) swap(x, y);
        int fx = find(x);
        int fy = find(y);
        if(fx == fy) return false;

        make_root(x);
        node[x].fa = y;

        used.insert(P(x, y));
        return true;
    }

    void init(int n) {
        for(int i = 0; i <= n; ++i)
            node[i].init(a[i]);
        node[0].size = 1;
    }

    void debug(int n) {
        for(int i = 0; i <= n; ++i) {
            cout<<i<<": "<<node[i].size<<' '<<node[i].fa<<' '<<node[i].ch[0]<<' '<<node[i].ch[1]<<endl;
        }
    }

    int get_ans(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if(fx != fy) return 0;
        
        make_root(x);
        access(y); splay(y); 
        return node[y].size;
    }
    void dfs(int);
} lct;

vector<int> G[N];

int opt[N], u[N], v[N];
vector<P> ans;

void LCT::dfs(int x) {
    for(int i = 0; i < G[x].size(); ++i) {
        int y = G[x][i];
        if(opt[y] == 1) {
            bool flag = link(u[y], v[y]);
            dfs(y);
            if(flag) cut(u[y], v[y]);
        } else if(opt[y] == 2) {
            bool flag = cut(u[y], v[y]);
            dfs(y);
            if(flag) link(u[y], v[y]);
        } else if(opt[y] == 4) {
            //ans[y] = get_ans(u[y], v[y]);
            ans.PB(P(y, get_ans(u[y], v[y])));
            dfs(y);
        } else if(opt[y] == 5) {
            int tmp = a[u[y]];
            a[u[y]] = v[y];
            node[u[y]].size = (LL)v[y] * (v[y] - 1) / 2;
            access(u[y]); splay(u[y]);

            dfs(y);

            a[u[y]] = tmp;
            node[u[y]].size = (LL)tmp * (tmp - 1) / 2;
            access(u[y]); splay(u[y]);
        }
    }
}

void gao(int n, int q) {
    lct.dfs(0);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i].Y);
    }
}

void init(int n, int q) {
    lct.init(n);
    //lct.debug(n);
    for(int i = 0; i <= q; ++i) {
        G[i].clear();
    }
    ans.clear();
    used.clear();
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, q;
        scanf("%d%d", &n, &q);
        a[0] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        init(n, q);
        int pre = 0;
        for(int i = 1; i <= q; ++i) {
            scanf("%d", &opt[i]);
            if(opt[i] != 3) {
                scanf("%d%d", &u[i], &v[i]);
                G[pre].PB(i);
                pre = i;
            } else {
                scanf("%d", &u[i]);
                pre = u[i];
				while(opt[pre] == 3) pre = u[pre];
            }
        }

        gao(n, q);
    }
    return 0;
}

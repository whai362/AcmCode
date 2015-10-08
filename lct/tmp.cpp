#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<vector>
#include<string>
#include<iomanip>
#include<complex>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
#define mst(a) memset(a,0,sizeof(a))
#define sz(a) (int)a.size()
#define mp make_pair
#define lth th<<1
#define rth th<<1|1
#define fir first
#define sec second
#define fuck cout<<233<<endl
#define getll(k) scanf("%lld",&k)
#define getint(k) scanf("%d",&k)
const long double pi = acosl(-1.);
int T;
typedef std::complex<long double> com;
const long long mod = 1000000007;
long long gcd(long long x, long long y) {
    if (!y)return x;
    return gcd(y, x%y);
}
long long quickfind(long long x, long long y) {
    long long result = 1;
    while (y) {
        if (y & 1)result = result*x%mod;
        y >>= 1;
        x = x*x%mod;
    }
    return result;
}
using namespace std;
const int maxn = 333333;
int son[maxn][2] = { 0 }, fa[maxn], pos[maxn],key[maxn];
long long sum[maxn];
int ans[maxn], sta[maxn];
inline void update(int x)
{
    sum[x] = sum[son[x][0]] * sum[son[x][1]]%mod * key[x]%mod;
}
inline void pushdown(int x)
{
    if (!pos[x])return;
    pos[x] ^= 1; pos[son[x][0]] ^= 1; pos[son[x][1]] ^= 1;
    swap(son[x][0], son[x][1]);
}
inline bool isroot(int x)
{
    return son[fa[x]][0] != x&&son[fa[x]][1] != x;
}
inline void rotate(int x)
{
    int y = fa[x], z = fa[y], l = (son[y][1] == x), r = l ^ 1;
    if (!isroot(y))son[z][son[z][1] == y] = x;
    fa[x] = z; fa[y] = x; fa[son[x][r]] = y;
    son[y][l] = son[x][r]; son[x][r] = y;
    update(y);
    update(x);
}
inline void splay(int x)
{
    int top = 0; sta[++top] = x;
    for (int y = x; !isroot(y); y = fa[y])sta[++top] = fa[y];
    for (; top;)pushdown(sta[top--]);
    while (!isroot(x))
    {
        int y = fa[x], z = fa[y];
        if (!isroot(y))
        {
            if (son[z][0] == y^son[y][0] == x)rotate(x); else rotate(y);
        }
        rotate(x);
    }
}
inline void access(int x)
{
    for (int y = 0; x; x = fa[x])splay(x), son[x][1] = y, update(x), y = x;
}
inline void makeroot(int x)
{
    access(x); splay(x); pos[x] ^= 1;
}
inline void link(int x, int y)
{
    makeroot(x);
    fa[x] = y;
    splay(x);
}
inline void cut(int x, int y)
{
    makeroot(x); access(y); splay(y); son[y][0] = fa[x] = 0;
}
inline bool sametree(int x, int y) {
    while (fa[x])x = fa[x];
    while (fa[y])y = fa[y];
    return x == y;
}
int n, m;
struct master {
    int pos, x, y;
    void input()
    {
        getint(pos);
        if (pos == 3)getint(x);
        else getint(x), getint(y);
        if (pos <= 2 && x > y)swap(x, y);
        if (pos == 5)y = y*(y - 1) / 2;
    }
}q[maxn];
int th;
int ind[maxn], nex[maxn], point[maxn], num[maxn];
void addedge(int x, int y, int z) {
    point[++th] = y;
    nex[th] = ind[x];
    ind[x] = th;
    num[th] = z;
}
set<long long>st;
void dfs(int x, int z) {
    bool can = 1;
    int last;
    if (x) {
        if (q[z].pos == 1) {
            if (q[z].x == q[z].y)can = 0;
            else if (sametree(q[z].x, q[z].y))can = 0;
            else link(q[z].x, q[z].y), st.insert((long long)q[z].x*maxn + q[z].y);
        }
        else if (q[z].pos == 2) {
            if (q[z].x == q[z].y)can = 0;
            else if (st.find((long long)q[z].x*maxn + q[z].y) == st.end())can = 0;
            else cut(q[z].x, q[z].y), st.erase((long long)q[z].x*maxn + q[z].y);
        }
        else if (q[z].pos == 3)can = 0;
        else if (q[z].pos == 4) {
            can = 0;    
            if (sametree(q[z].x, q[z].y))
            {
                makeroot(q[z].y);
                access(q[z].x);
                splay(q[z].x);
                ans[z] = (int)sum[q[z].x];
                
            }
            else ans[z] = 0;
        }
        else {
            access(q[z].x);
            splay(q[z].x);
            last = key[q[z].x];
            key[q[z].x] = q[z].y;
            sum[q[z].x] = sum[son[q[z].x][0]] * sum[son[q[z].x][1]]%mod * key[q[z].x]%mod;
        }
    }
    for (int i = ind[x]; i; i = nex[i]) {
        int y = point[i];
        dfs(y, num[i]);
    }
    if (x&&can) {
        if (q[z].pos == 1) {
            st.erase((long long)q[z].x*maxn + q[z].y);
            cut(q[z].x, q[z].y);
        }
        else if (q[z].pos == 2) {
            st.insert((long long)q[z].x*maxn + q[z].y);
            link(q[z].x, q[z].y);
        }
        else if (q[z].pos == 5)
        {
            access(q[z].x);
            splay(q[z].x);
            key[q[z].x] = last;    
            sum[q[z].x] = sum[son[q[z].x][0]] * sum[son[q[z].x][1]] % mod * key[q[z].x] % mod;
        }
    }

}
void Railgun() {
    st.clear();
    getint(n);
    getint(m);
    rep(i, 1, n)pos[i] = fa[i] = son[i][0] = son[i][1] = 0,getint(key[i]),key[i]=key[i]*(key[i]-1)/2,sum[i]=key[i];
    rep(i, 0, m)ind[i] = 0;
    fa[0]=th = 0;
    rep(i, 1, m) {
        q[i].input();
        if (q[i].pos == 3)
            addedge(min(q[i].x,i-1), i, i);
        else addedge(i - 1, i, i);
    }
    dfs(0, 0);
    rep(i, 1, m)
        if (q[i].pos == 4)printf("%d\n", ans[i]);
    
}
int main() {
    getint(T);
    sum[0] = 1;
    while (T--) {
        Railgun();
    }
    return 0;
}

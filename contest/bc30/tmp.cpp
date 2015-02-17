#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define MX 300005
struct Edge {
    int u, v, d;
    void in() {scanf("%d%d%d", &u, &v, &d);}
} e[MX];
bool cmp0(const Edge &a, const Edge &b) {
    return a.d < b.d;
}
bool cmp1(const Edge &a, const Edge &b) {
    return a.d > b.d;
}

typedef unsigned long long ULL;
int rt[MX], sz[MX];
int stk[MX],top;
int find_root(int x) {
    top=-1;
	while(x!=rt[x]){ stk[++top]=x; x=rt[x]; }
	int now=x;
	while(top>=0){ now=stk[top--]; rt[now]=x; }
	return rt[now];
}

int main() {    
    int n, i, u, v, T = 0;
    while (scanf("%d", &n) == 1) {
        for (i = 0; i < n - 1; i++) e[i].in();
        ULL sum = 0;
        sort(e, e + n - 1, cmp0);
        for (i = 1; i <= n; i++) rt[i] = i, sz[i] = 1;
        
        for (i = 0; i < n - 1; i++) {
            u = find_root(e[i].u), v = find_root(e[i].v);
            sum += 1ULL * sz[u] * sz[v] * e[i].d;
            rt[u] = v;
            sz[v] += sz[u];
        }
        
        sort(e, e + n - 1, cmp1);
        for (i = 1; i <= n; i++) rt[i] = i, sz[i] = 1;
        
        for (i = 0; i < n - 1; i++) {
            u = find_root(e[i].u), v = find_root(e[i].v);
            sum -= 1ULL * sz[u] * sz[v] * e[i].d;
            rt[u] = v;
            sz[v] += sz[u];
        }
        
        cout << "Case #" << ++T << ": ";
        cout << sum << endl;
    }
    return 0;
}

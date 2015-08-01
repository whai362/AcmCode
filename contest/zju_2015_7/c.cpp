/*************************************************************************
	> File Name: f.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com
	> Created Time: 2015年07月26日 星期日 14时45分49秒
 ************************************************************************/

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
#include <unordered_map>
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define MAX_NICO 10000001
#define MAXN 100005
template <typename T> inline void checkMax(T &a, T b) {a = a>b?a:b;}
template <typename T> inline void checkMin(T &a, T b) {a = a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
const double eps = 1e-8;
bool ni[MAX_NICO] = {};

bool vis[MAXN];

int N, a[MAXN], split, Q, op, L, R, P, X, V;

void init() {
    ni[0] = false;
//    ni[0] = true;
    ni[1] = false;
    for (int i = 2; i <= MAX_NICO; i ++) {
        if (ni[i]) continue;
        for (int j = i + i; j <= MAX_NICO; j = j + i) {
            ni[j] = true;
        }
    }
    ni[6] = false;
    for (int i = 0; (1 << i) <= MAX_NICO; i ++) {
        ni[1 << i] = false;
    }
}

bool isni(int x) {
    return !ni[x];
}
    
struct Block {
    int l, r, maxvalue, cnt;
    vector<int> num;
    unordered_map<int, int> modify;

    Block() {}

    Block(int l, int r) : l(l), r(r) {
        num.clear();
        modify.clear();
        maxvalue = cnt = 0;
        for (int i = l; i <= r; i ++) {
            num.push_back(a[i]);
            maxvalue = max(maxvalue, a[i]);
            cnt = cnt + isni(a[i]);
        }
    }
    
    void update(int L, int R, int v) {
        vector<int> tmp;
        for (unordered_map<int, int>::iterator it = modify.begin(); it != modify.end(); it ++) {
            int x = it -> first, index = x - l;
            if (x >= L && x <= R) {
                tmp.push_back(x);
                cnt = cnt - isni(it -> second);
                num[index] = it -> second % v;
                cnt = cnt + isni(num[index]);
                maxvalue = max(maxvalue, num[index]);
            }
        } 
        if (maxvalue >= v) {
            cnt = maxvalue = 0;
            for (int i = l; i <= r; i ++) {
                int index = i - l;
                if (i >= L && i <= R) {
                    num[index] %= v;
                }
                cnt = cnt + isni(num[index]);
                maxvalue = max(maxvalue, num[index]);
            }
        }
        for (int i = 0; i < tmp.size(); i ++) {
            unordered_map<int, int>::iterator it = modify.find(tmp[i]);
            modify.erase(it);
            vis[tmp[i]] = false;
        }
    }

    void updateAll(int v) {
        vector<int> tmp;
        for (unordered_map<int, int>::iterator it = modify.begin(); it != modify.end(); it ++) {
            int x = it -> first, index = x - l;
            tmp.push_back(x);
            cnt = cnt - isni(it -> second);
            num[index] = it -> second % v;
            cnt = cnt + isni(num[index]);
            maxvalue = max(maxvalue, num[index]);
        } 
        if (maxvalue >= v) {
            cnt = maxvalue = 0;
            for (int i = l; i <= r; i ++) {
                int index = i - l;
                if (!vis[i] && num[i] >= v) {
                    num[i] %= v;
                }
                cnt = cnt + isni(num[index]);
                maxvalue = max(maxvalue, num[index]);
            }
        }
        modify.clear();
        for (int i = 0; i < tmp.size(); i ++) {
            vis[tmp[i]] = false;
        }
    }

    void add(int p, int x) {
        int index = p - l;
        vis[p] = true;
        if (modify.find(p) == modify.end()) {
            cnt = cnt - isni(num[index]);
            modify[p] = x;
            cnt = cnt + isni(x);
        } else {
            cnt = cnt - isni(modify[p]);
            modify[p] = x;
            cnt = cnt + isni(x);
        }
    }

    int query(int L, int R) {
        int ans = 0;
        for (int i = L; i <= R; i ++) {
            if (vis[i]) {
                ans = ans + isni(modify[i]);
            } else {
                ans = ans + isni(num[i - l]);
            }
        }
        return ans;
    }
} block[2005];

int fun1(int l, int r) {
    int firstblock = (l - 1) / split + 1;
    int endblock = (r - 1) / split + 1;
    int ans = 0;
    if (firstblock == endblock) {
        ans = ans + block[firstblock].query(l, r);
    } else {
        ans = ans + block[firstblock].query(l, block[firstblock].r);
        ans = ans + block[endblock].query(block[endblock].l, r);
        for (int i = firstblock + 1; i < endblock; i ++) {
            ans = ans + block[i].cnt;
        }
    }
    return ans;
}

void fun2(int l, int r, int v) {
    int firstblock = (l - 1) / split + 1;
    int endblock = (r - 1) / split + 1;
    if (firstblock == endblock) {
        block[firstblock].update(l, r, v);
    } else {
        block[firstblock].update(l, block[firstblock].r, v);
        block[endblock].update(block[endblock].l, r, v);
        for (int i = firstblock + 1; i < endblock; i ++) {
            block[i].updateAll(v);
        }
    }
}

void fun3(int p, int x) {
    int fblock = (p - 1) / split + 1;
    block[fblock].add(p, x);
}

void work() {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= N; i ++) {
        scanf("%d", &a[i]);
    }
    split = (int)(sqrt(1.0 * N)) + 5;
    int pnt = 0;
    for (int l = 1; l <= N; l += split) {
        int r = l + split - 1;
        r = min(r, N);
        block[++ pnt] = Block(l, r);
    }
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i ++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d", &L, &R);
            printf("%d\n", fun1(L, R));
        } else if (op == 2) {
            scanf("%d %d %d", &L, &R, &V);
            fun2(L, R, V);
        } else {
            scanf("%d %d", &P, &X);
            fun3(P, X);
        }
    }
}
int main() {
#ifdef __SKT__
    freopen("in", "r", stdin);
#endif
    init();
    while (scanf("%d", &N) != EOF) {
        work();
    }
    return 0;
}

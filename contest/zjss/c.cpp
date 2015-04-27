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
#define eps 1e-8
#define x first
#define y second
#define MOD 998244353 
#define MAXN 1005
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
int T, N;

struct Point {
    LL x, y;
} q[MAXN], bag[MAXN];

LL xmult(Point p1, Point p2, Point p0) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

int compare(const void *t1, const void *t2) {
    Point *p1 = (Point *)t1;
    Point *p2 = (Point *)t2;
    if (p1 -> y == p2 -> y) {
        return p1 -> x - p2 -> x;
    }
    return p1 -> y - p2 -> y;
}

int make_bag(Point *p, Point *bag, int n) {
    int i, j;
    qsort(p, n, sizeof(Point), compare);
    bag[0] = p[0];
    int len = 1;
    for (i = 1; i < n; i ++) {
        while (len >= 2 && xmult(bag[len - 2], bag[len - 1], p[i]) <= 0) len --;
        bag[len ++] = p[i];
    }
    j = len + 1;
    for (i = n - 2; i >= 0; i --) {
        while (len >= j && xmult(bag[len - 2], bag[len - 1], p[i]) <= 0) len --;
        bag[len ++] = p[i];
    }
    len --;
    return len;
}

LL power(LL a, LL n) {
    LL ans = 1ll;
    while (n) {
        if (n & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ans;
}

void work() {
    scanf("%d", &N);  
    LL ans = power(2, N - 3);
    for (int i = 0; i < N; i ++) {
        scanf("%lld %lld", &q[i].x, &q[i].y);
    }
    int len = make_bag(q, bag, N);
    LL res = 0;
    for (int i = 2; i < len; i ++) {
        res = res + xmult(bag[i], bag[i - 1], bag[0]);
    }
    res = abs(res);
    res = res % MOD;
    ans = ans * res % MOD;
    cout << ans << endl;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}

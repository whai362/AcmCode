#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int T, Cas = 1;
LL n, f;

bool Test(LL n, LL base)
{
    while (n) {
        LL x = n % base;
        n /= base;
        if (x < 3 || x > 6) return false;
    }
    return true;
}

LL check(LL n)
{
    LL ans = 0; 
    for (int i = 2; i <= f; i ++) {
        if (Test(n, i)) ans ++;
    }
    return ans;
}

LL solve(int state, LL base) 
{
    LL ans = 0, d = 1;
    while (state) {
        int x = state % 5;
        LL y;
        state /= 5;
        if (x == 0) {
            y = 0;
        } else if (x == 1) {
            y = 3;
        } else if (x == 2) {
            y = 4;
        } else if (x == 3) {
            y = 5;
        } else {
            y = 6;
        }
        ans = ans + y * d;
        d = d * base;
    }
    return ans;
}

LL Judge(int state) 
{
    LL l = f, r = n + 1;
    while (r - l > 1) {
        LL mid = (l + r) / 2;
        LL tmp = solve(state, mid);
        if (tmp == n) return mid;
        if (tmp > n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (solve(state, r) == n) return r;
    if (solve(state, l) == n) return l;
    return -1;
}

bool is(int state) 
{
    vector <int> tmp;
    tmp.clear();
    while (state) {
        tmp.pb(state % 5);
        state /= 5;
    }
    for (int i = 0; i < tmp.size(); i ++) {
        if (tmp[i] == 0) return false;
    }
    return true;
}

LL gao(LL n)
{
    LL ans = 0;
    for (int i = 0; i < 625; i ++) {
        if (!is(i)) continue;
        LL x = Judge(i);
        if (x > f) {
            ans ++;
        }
    }
    return ans;
}

void work()
{
    printf("Case #%d: ", Cas ++);
    cin >> n;
    if (n == 1 || n == 2) {
        printf("0\n"); return ;
    }
    if (n == 3 || n == 4 || n == 5 || n == 6) {
        printf("-1\n"); return ;
    }
    f = 50000;
    if (n <= f) {
        cout << check(n) << endl;
    } else {
        cout << (check(n) + gao(n)) << endl;
    }
}
int main()
{
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}

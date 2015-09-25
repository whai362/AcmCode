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
#define x first
#define y second
#define MAXN 250000
#define MOD 530600414 
template <typename T> inline void checkMax(T &a, T b) {a = a>b?a:b;}
template <typename T> inline void checkMin(T &a, T b) {a = a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
const double eps = 1e-8;
int T, Cas = 1, N;

LL a[MAXN], l[MAXN], r[MAXN], len[MAXN], num[MAXN];

void init() {
    a[1] = 0, a[2] = 0, a[3] = 0, a[4] = 0, a[5] = 5;
    l[1] = 0, l[2] = 0, l[3] = 1, l[4] = 3, l[5] = 7;
    r[1] = 0, r[2] = 0, r[3] = 3, r[4] = 3, r[5] = 11;
    len[1] = 1, len[2] = 2, len[3] = 3, len[4] = 5, len[5] = 8;
    num[1] = 0, num[2] = 0, num[3] = 1, num[4] = 1, num[5] = 2;
    for (int i = 6; i <= 201314; i ++) {
        a[i] = (((a[i - 2] + a[i - 1]) % MOD) + (r[i - 2] * num[i - 1] % MOD) + ((l[i - 1] - num[i - 1]) * num[i - 2] % MOD)) % MOD;
        num[i] = (num[i - 2] + num[i - 1]) % MOD;
        len[i] = (len[i - 2] + len[i - 1]) % MOD;
        r[i] = ((r[i - 2] + r[i - 1]) % MOD + (len[i - 1] * num[i - 2] % MOD)) % MOD;
        l[i] = ((l[i - 2] + l[i - 1]) % MOD + (len[i - 2] * num[i - 1] % MOD)) % MOD;
    }
}

void work() {
    printf("Case #%d: ", Cas ++);
    scanf("%d", &N);
    if (N == 3 || N == 4) {
        cout << 1 << endl; return ;
    }
    cout << a[N] << endl;
}
int main() {
    init();
    scanf("%d", &T);
    while (T --) {
        work();
    } 
    return 0;
}

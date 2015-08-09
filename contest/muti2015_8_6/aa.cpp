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
#include <ctime>
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define MAXN 100001
template <typename T> inline void checkMax(T &a, T b) {a = a>b?a:b;}
template <typename T> inline void checkMin(T &a, T b) {a = a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
const double eps = 1e-8;
int T, N, a[MAXN];

LL sum[MAXN], ans;

pair < LL, LL > border[45];

void init() {
    border[0] = mp(0ll, 1ll);
    for (int i = 1; i <= 34; i ++) {
        border[i].x = border[i - 1].y + 1;
        border[i].y = (1ll << (i + 1)) - 1ll;
    }
}

int getBigger(int l, int r, LL q) {
    while (r - l > 1) {
        int mid = (r + l) >> 1;
        if (sum[mid] <= q) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (sum[r] <= q) {
        return r;
    }
    if (sum[l] <= q) {
        return l;
    }
}

template <class T>
inline bool scan_d(T &ret) {
   char c; int sgn;
   if(c=getchar(),c==EOF) return 0; //EOF
   while(c!='-'&&(c<'0'||c>'9')) c=getchar();
   sgn=(c=='-')?-1:1;
   ret=(c=='-')?0:(c-'0');
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
   ret*=sgn;
   return 1;
}

void work() {
    scan_d(N);
    ans = 0;
    for (int i = 1; i <= N; i ++) {
        scan_d(a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= N; i ++) {
        LL left = i, top = 0;
        while (left <= N) {
            LL first = sum[left] - sum[i - 1];
            while (border[top].y < first) {
                top ++;
            }
            LL right = getBigger(left, N, sum[i - 1] + border[top].y);
            ans = ans + (top + 1) * (i * (right - left + 1) + (left + right) * (right - left + 1) / 2);
            left = right + 1;
        }
    }
    printf("%lld\n", ans);
}
int main() {
	//double st = clock();
    init();
    scan_d(T);
    while (T --) {
        work();
    }
	//double en = clock();
	//cerr<<(en - st) / CLOCKS_PER_SEC<<endl;
    return 0;
}

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
#define MAXN 1000005
template <typename T> inline void checkMax(T &a, T b) {a = a>b?a:b;}
template <typename T> inline void checkMin(T &a, T b) {a = a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
const double eps = 1e-8;
int T, N, ans;

LL a[MAXN];
int dp[MAXN];

void work() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%I64d", &a[i]);
    }
    dp[1] = 1;
    ans = 1;
    for (int i = 2; i <= N; i ++) {
        if (i == 2) {
            dp[i] = 2;
        } else {
            if (a[i] + a[i - 2] == a[i - 1] * 2) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 2;
            }
        }
        ans = max(ans, dp[i]);
    }
	cout<<ans<<endl;
    dp[1] = 1;
    for (int i = 2; i <= N; i ++) {
        if (i == 2) {
            dp[i] = 2;
        } else {
            if (a[i] * a[i - 2] == a[i - 1] * a[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 2;
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}

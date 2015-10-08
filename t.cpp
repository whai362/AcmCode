#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

const int N = 1e5 + 5;
const int P = 1e9 + 7;
typedef long long LL;

int power(int a, int n) {
    int ans = 1, z = a;
    while (n > 0) {
        if (n & 1) ans = (LL) ans * z % P;
        z = (LL)z * z % P;
        n >>= 1;
    }
    return ans;
}

int a[N], b[N];
int num[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int ans = 0;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            b[i] = a[i];
            ans = (ans + (LL)a[i] * power(2, n - 1) % P) % P;
        }
        sort(b + 1, b + 1 + n);
        int m = unique(b + 1, b + 1 + n) - b - 1;
        for (int i = 0; i <= m; ++i)
            num[i] = 0;
        for (int i = 1; i <= n; ++i) {
            int x = a[i];
            a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b;
            int res = (LL)num[a[i]] * power(2, n - i) % P;
            ans = (ans - (LL)res * x % P + P) % P;
            num[a[i]] = (num[a[i]] + power(2, i - 1)) % P;
        }
        printf("%d\n", ans);
    }
    return 0;
}

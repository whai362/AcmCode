#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long lint;

const int MAX_N = 2020;
const int MOD = 1000000007;
double d[MAX_N][MAX_N];
int dp[MAX_N][MAX_N], n;
int h[MAX_N], ss;

void add(int &x, int y) {
    if ((x += y) >= MOD) {
        x -= MOD;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(dp[0], dp[n + 3], 0);
        fill(d[0], d[n + 3], 0.0);
        d[0][0] = 1, dp[0][0] = 1;
        ss = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", h + i);
            ss += h[i];
        }
        for (int i = 1; i <= n; i++) {
            double s = 0.0;
            int sum = 0;
            for (int j = 0; j <= h[i]; j++) {
                s += d[i - 1][j];
                add(sum, dp[i - 1][j]);
                d[i][j] = s, dp[i][j] = sum;
            }
            for (int j = h[i] + 1; j <= ss; j++) {
                s += d[i - 1][j];
                s -= d[i - 1][j - h[i] - 1];
                add(sum, dp[i - 1][j]);
                add(sum, MOD - dp[i - 1][j - h[i] - 1]);
                d[i][j] = s, dp[i][j] = sum;
            }
        }
        /*
        double mx = 0.0;
        int ans = 0;
        for (int i = 0; i <= ss; i++) {
            if (mx < d[n][i]) {
                mx = d[n][i];
                ans = dp[n][i];
            }
        }
        */
        printf("%d\n", dp[n][ss >> 1]);
    }
    return 0;
}

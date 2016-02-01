/*======================================================
# Author: whai
# Last modified: 2015-12-31 00:01
# Filename: d.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 5005;
const int MOD = 1000000007;
char str[N];

LL dp[N][N];

bool gr(int L, int R) {
    int r = L - 1;
    int l = r - (R - L);
    if(l < 0) return true;
    for(int i = l; i <= r; ++i) {
        if(str[i] > str[i - l + L]) return false;
        else if(str[i] < str[i - l + L]) return true;
    }
    return false;
}

void gao(int n) {
    dp[1][1] = 1;
    for(int i = 2; i <= n; ++i) {
        dp[i][i] = 1;
        for(int j = 1; j < i; ++j) {
            if(str[i - j + 1] == '0') continue;
            if(!gr(i - j + 1, i)) dp[i][j] = (dp[i][j] + dp[i - j][min(i - j, j - 1)]) % MOD;
            else dp[i][j] = (dp[i][j] + dp[i - j][min(i - j, j)]) % MOD;
        }
        for(int j = 1; j <= i; ++j) {
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    
    cout<<dp[n][n]<<endl;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        scanf("%s", str + 1);
        gao(n);
    }
    return 0;
}

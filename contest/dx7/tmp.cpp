#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define eps 1e-8
template <typename T> inline T Max(T a, T b) {return a>b?a:b;}
template <typename T> inline T Min(T a, T b) {return a<b?a:b;}
int x, y, z, t, n;
typedef long long ll;

struct Node{
    ll sum;
    ll x;
    ll t;
}dp[1555][1555];
ll ans = 0;

void work()
{

}

inline ll solve(Node a, int i){
    ll ret = a.x * a.t * (n - i) + a.sum + a.t * (n - i) * x;
    return ret;
}

int main()
{
    int T,cas = 0;
    scanf("%d", &T);
    while (cas++ < T){
        scanf("%d%d%d%d%d", &n, &x, &y, &z, &t);
        memset(dp, 0, sizeof(dp));
        ans = x * n * t;
        dp[1][0].sum = 0;
        dp[1][0].x = y;
        dp[1][0].t = t;
        ans = max(ans, solve(dp[1][0], 1));
        dp[1][1].sum = 0;
        dp[1][1].x = 0;
        dp[1][1].t = t + z;
        ans = max(ans, solve(dp[1][1], 1));
        for (int i = 2; i <= n; i ++){
            dp[i][0].sum = dp[i - 1][0].sum + dp[i-1][0].x * dp[i-1][0].t;     
            dp[i][0].x = dp[i - 1][0].x + y;
            dp[i][0].t = dp[i-1][0].t;     
            ans = max(ans, solve(dp[i][0],i));
        }
        ll tmp1,tmp2;
        Node tmpa,tmpb;
        for (int i = 2; i <= n; i ++){
            for (int j = 1; j <= i; j  ++){
                tmpa.sum = dp[i-1][j].sum + dp[i-1][j].x * dp[i-1][j].t;
                tmpa.x = dp[i-1][j].x + y;
                tmpa.t = dp[i-1][j].t;
                tmp1 = solve(tmpa, i);
                tmpb.sum = dp[i-1][j-1].sum + dp[i-1][j-1].x * dp[i-1][j-1].t;
                tmpb.x = dp[i-1][j-1].x;
                tmpb.t = dp[i-1][j-1].t + z;
                tmp2 = solve(tmpb, i);
                if (tmp1 > tmp2){
                    ans = max(tmp1, ans);
                    dp[i][j] = tmpa;
                }else {
                    ans = max(tmp2, ans);
                    dp[i][j] = tmpb;
                }
            } 
        }
        printf("Case #%d: %I64d\n", cas, ans);
    } 
    return 0;
}

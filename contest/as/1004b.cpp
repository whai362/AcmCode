#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1e9 + 7;
int T, N;
int M[2009], sum[2009];
double dpd[2009][2009];
int dp[2009][2009];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        sum[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &M[i]);
            sum[i] = sum[i - 1] + M[i];
        }
        memset(dpd, 0, sizeof(dpd));
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dpd[0][0] = 1.0;
        for (int i = 1; i <= N; i++)
        {
            double m = 0;
            for (int j = 0; j <= sum[i]; j++)
            {
                for (int k = 0; k <= M[i] && k <= j; k++)
                {
                    dpd[i][j] += dpd[i - 1][j - k];
                    dp[i][j] = ((long long)dp[i][j] + dp[i - 1][j - k]) % MOD;
                }
                m = max(m, dpd[i][j]);
            }
            if (m > 1.0e100)
                for (int j = 0; j <= sum[i]; j++)
                    dpd[i][j] /= 1.0e100;
        }
        // int maxindex = 0;
        // for (int i = 0; i <= sum[N]; i++)
        // {
        //     printf("%4d:%4d %lf\n", i, dp[N][i], dpd[N][i] );
        //     if (dpd[N][i] > dpd[N][maxindex])
        //         maxindex = i;
        // }
        printf("%d\n", dp[N][sum[N]/2]);
    }
    return 0;
}

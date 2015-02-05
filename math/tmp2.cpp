#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const int N = 2005;

LL C[N][N];
LL B[N],Inv[N];
LL Tmp[N];
LL n;

void Init()
{
    //预处理组合数
    for(int i=0; i<N; i++)
    {
        C[i][0] = C[i][i] = 1;
        if(i == 0) continue;
        for(int j=1; j<i; j++)
            C[i][j] = (C[i-1][j] % MOD + C[i-1][j-1] % MOD) % MOD;
    }
    //预处理逆元
    Inv[1] = 1;
    for(int i=2; i<N; i++)
        Inv[i] = (MOD - MOD / i) * Inv[MOD % i] % MOD;
    //预处理伯努利数
    B[0] = 1;
    for(int i=1; i<N; i++)
    {
        LL ans = 0;
        if(i == N - 1) break;
        for(int j=0; j<i; j++)
        {
            ans += C[i+1][j] * B[j];
            ans %= MOD;
        }
        ans *= -Inv[i+1];
        ans = (ans % MOD + MOD) % MOD;
        B[i] = ans;
    }
}

LL Work(int k)
{
    LL ans = Inv[k+1];
    LL sum = 0;
    for(int i=1; i<=k+1; i++)
    {
        sum += C[k+1][i] * Tmp[i] % MOD * B[k+1-i] % MOD;
        sum %= MOD;
    }
    ans *= sum;
    ans %= MOD;
    return ans;
}

int main()
{
    int T;
    Init();
	for(int i=0;i<20;++i){
		cout<<B[i]<<' ';
	}
	cout<<endl;
    //scanf("%d", &T);
    //while(T--)
    //{
    //    int k;
    //    scanf("%I64d %d", &n, &k);
    //    n %= MOD;
    //    Tmp[0] = 1;
    //    for(int i=1; i<N; i++)
    //        Tmp[i] = Tmp[i-1] * (n + 1) % MOD;
    //    printf("%I64d\n", Work(k));
    //}
    return 0;
}


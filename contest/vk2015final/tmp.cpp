#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1000000;
int N, ANS;
int dp[MAXN + 1];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= MAXN; i++)
		dp[i] = 0;
	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		dp[x]  = 1 ;
	}
	ANS = 0;
	for (int i = MAXN; i >= 1; i--)
		if (dp[i])
		{
			for (int j = i + i; j <= MAXN; j += i)
				dp[i] = max(dp[i], dp[j] + 1);
			ANS = max(ANS, dp[i]);
		}

	printf("%d\n", ANS);
	return 0;
}

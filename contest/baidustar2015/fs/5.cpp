#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 0x3f3f3f3f;
const int MOD = 1000000007;
int T;
char str[100009];
int right_first[100009][26];
int dp[100009];//以该点结尾子序列最短长度
int way[100009];
int main()
{
	scanf("%d", &T);
	for (int TT = 1; TT <= T; TT++)
	{
		scanf("%s", str + 1);
		int len = strlen(str + 1);
		memset(right_first, 0x3f, sizeof(right_first));
		for (int i = len; i > 0; i--)
		{
			for (int j = 0; j < 26; j++)
				right_first[i][j] = right_first[i + 1][j];
			right_first[i][str[i] - 'a'] = i;
		}
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		for (int j = 0; j < 26; j++)
			right_first[0][j] = right_first[1][j];
		memset(way, 0, sizeof(way));
		way[0] = 1;
		int ans = MAX;
		int ans_way = 0;
		for (int i = 0; i <= len; i++)
		{
			for (int j = 0; j < 26; j++)
				if (right_first[i + 1][j] != MAX)
				{
					if (dp[i] + 1 <= dp[right_first[i + 1][j]])
					{
						if (dp[i] + 1 < dp[right_first[i + 1][j]])
						{
							dp[right_first[i + 1][j]] = dp[i] + 1;
							way[right_first[i + 1][j]] = 0;
						}
						way[right_first[i + 1][j]] = (way[right_first[i + 1][j]] + way[i]) % MOD;
					}

				}
				else
					ans = min(ans, dp[i] + 1);
		}
		// for (int i = 0; i <= len; i++)
		// 	printf("%4d\n",way[i] );
		// printf("\n");
		for (int i = 0; i <= len; i++)
			if (dp[i] + 1 == ans)
				for (int j = 0; j < 26 ; j ++)
					if (right_first[i + 1][j] == MAX)
						ans_way = (ans_way + way[i])  % MOD;
		printf("Case #%d:\n%d %d\n", TT, ans, ans_way);
	}
	return 0;
}


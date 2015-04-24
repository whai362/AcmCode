#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int n, a[100], flag[100];
int cmp(int x, int y)
{
	return x > y;
}
int dfs(int len, int k, int s)
{
	if(s == len)
		return 1;
	if(k == n && s != len)
		return 0;
	for(int i = k;i < n;i++)
	{
		if(len - s >= a[i] && !flag[i])
		{
			flag[i] = a[i];
			if(dfs(len, i+1, s+a[i]))
			{
				printf("%d ", a[i]);
				return 1;
			}
			else
				flag[i] = 0;
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d", &n), n)
	{
		int sum = 0;
		memset(a, 0, sizeof(a));
		memset(flag, 0, sizeof(flag));
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		printf("sum%d\n", sum);
		sort(a, a+n, cmp);
		for(int i = 0;i < n;i++)
			printf("%d%c", a[i], " \n"[i==n-1]);
		for(int ans = a[0]; ans <= sum;ans++)
		{
			if(ans == sum)
			{
				printf("%d\n", ans);
				break;
			}
			if(sum % ans)
				continue;
			memset(flag, 0, sizeof(flag));
			int v = 0;
			for(int i = 0;i < sum/ans;i++)
			{
				if(!dfs(ans, 0, 0))
				{
					v = 1;
					printf("\n");
					for(int j = 0;j < n;j++)
						if(flag[j]==0)
							printf("%d ", a[j]);
					printf("\n");
					break;
				}
				printf("\n");
			}
			if(!v)
			{
				printf("%d\n", ans);
				break;
			}
		}
	}
	return 0;
}

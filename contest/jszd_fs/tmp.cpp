/*
* @Author: Comzyh
* @Date:   2015-07-25 19:39:52
* @Last Modified by:   Comzyh
* @Last Modified time: 2015-07-25 20:42:47
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
int T;
int N, M;
int vis[10009];
vector<int> tab[10009];
vector<int> nums;

int dfs(int x, int c)
{
	int ans = 1;
	vis[x] = 1;
	for (int i = 0; i < tab[x].size(); i++)
		if (!vis[tab[x][i]])
			ans -= dfs(tab[x][i], c ^ 1);
	return ans;
}
inline int abs(int x)
{
	return x > 0 ? x : -x;
}
int dp_process()
{
	set<int> dp[2];
	dp[0].clear();
	dp[1].clear();
	int pre = 0, cur = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		swap(pre, cur);
		dp[cur].clear();
		for (set<int>::iterator it = dp[pre].begin(); it != dp[pre].end(); it++)
		{
			dp[cur].insert(abs(nums[i] + *it));
			dp[cur].insert(abs(nums[i] - *it));
		}
	}
	return *(dp[cur].begin());
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++)
			tab[i].clear();
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < M; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			tab[a].push_back(b);
			tab[b].push_back(a);
		}
		nums.clear();
		for (int i = 1; i <= N; i++)
			if (!vis[i])
				nums.push_back(abs(dfs(i, 0)));
		int detla = dp_process();
		// printf("detla = %d\n", detla);
		long long a = (N + detla) / 2;
		long long b = (N - detla) / 2;
		printf("%I64d\n", a * b - M);
		// for (int i = 0; i < nums.size(); i++)
		// 	printf("%d\n", nums[i]);
		// printf("\n");
	}
	return 0;
}

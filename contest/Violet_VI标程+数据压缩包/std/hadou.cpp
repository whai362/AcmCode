#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 5000010;
const int TN = 2000010;
int mr, smr, inv = -1;
int c_son[N], rn[N], rs[N], sp45[N], res[N], son[TN][10];
int dp[N][2], d45[N]; bool is4[N];
inline int new_node (void)
{
	c_son[mr] = -1, rn[mr] = rs[mr] = sp45[mr] = 0, is4[mr] = false; return mr++;
}
inline int new_son (void)
{
	for (int i = 0; i < 10; i++) son[smr][i] = -1; return smr++;
}
void init (void)
{
	mr = 1, smr = 0;
	c_son[0] = -1, res[0] = 0;
}
inline int& S (int a, int b)
{
	return c_son[a] == -1 ? inv : son[c_son[a]][b];
}
void ins (char *a)
{
	int now = 0, pre = -1, suc = -1, cnt = 0, cpre = 0, csuc = 0;
	while (*a)
	{
		int k = *a - '0';
		if (c_son[now] == -1) c_son[now] = new_son();
		if (k < 5)
		{
			for (int i = 0; i < 5; i++)
			{
				if (S(now, i) == -1) S(now, i) = new_node();
				rn[S(now, i)] += cnt;
			}
			if (pre != -1)
			{
				if (c_son[pre] == -1) c_son[pre] = new_son();
				for (int i = 5; i < 10; i++)
				{
					if (S(pre, i) == -1) S(pre, i) = new_node();
					rs[S(pre, i)] += cpre;
				}
				if (cpre == 2) ++sp45[pre], is4[pre] = true;
			}
		}
		else
		{
			for (int i = 5; i < 10; i++)
			{
				if (S(now, i) == -1) S(now, i) = new_node();
				rn[S(now, i)] += cnt;
			}
			if (suc != -1)
			{
				if (c_son[suc] == -1) c_son[suc] = new_son();
				for (int i = 0; i < 5; i++)
				{
					if (S(suc, i) == -1) S(suc, i) = new_node();
					rs[S(suc, i)] += csuc;
				}
				if (csuc == 2) ++sp45[suc];
			}
		}
		if (!cnt) cnt = 1;
		if (k == 0)
		{
			if (pre != -1) pre = S(pre, 9);
			suc = S(now, 1);
		}
		else if (k == 9)
		{
			pre = S(now, 8);
			if (suc != -1) suc = S(suc, 0);
		}
		else
		{
			if (S(now, k - 1) == -1) S(now, k - 1) = new_node();
			pre = S(now, k - 1);
			if (S(now, k + 1) == -1) S(now, k + 1) = new_node();
			suc = S(now, k + 1);
		}
		if (k == 4 && csuc) csuc = 2, cpre = 1;
		else if (k == 5 && cpre) cpre = 2, csuc = 1;
		else cpre = 1, csuc = 1;
		now = S(now, k);
		++a;
	}
}
void proc (int x)
{
	res[x] = rn[x] + rs[x];
	dp[x][0] = dp[x][1] = d45[x] = res[x];
	if (c_son[x] == -1) return;
	for (int i = 0; i < 10; i++)
	{
		if (S(x, i) != -1)
		{
			dp[x][0] = max(dp[x][0], res[x] + dp[S(x, i)][0]);
			int c = res[x] + dp[S(x, i)][0];
			if (is4[x] == (i >= 5)) d45[x] = max(d45[x], c - sp45[x]);
			else d45[x] = max(d45[x], c);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (S(x, i) == -1) continue;
		for (int j = i + 2; j < 10; j++)
		{
			if (S(x, j) == -1) continue;
			int c;
			if ((i < 5) == (j < 5)) c = dp[S(x, i)][0] + dp[S(x, j)][0] + res[x] - res[S(x, i)];
			else c = d45[S(x, i)] + d45[S(x, j)] + res[x];
			dp[x][1] = max(dp[x][1], c);
		}
		dp[x][1] = max(dp[x][1], res[x] + dp[S(x, i)][1]);
	}
	for (int i = 0; i < 9; i++)
	{
		if (S(x, i) == -1 || S(x, i + 1) == -1) continue;
		int pre = S(x, i), suc = S(x, i + 1), c = res[pre] + res[suc] + res[x];
		bool fst = (i == 4); 
		if ((i < 5) == (i + 1 < 5)) c -= res[pre];
		while (1)
		{
			for (int sp = 0; sp < 10; ++sp)
			{
				if (S(pre, sp) == -1) continue;
				for (int sc = 0; sc < 10; ++sc)
				{
					if (S(suc, sc) == -1 || (sp == 9 && sc == 0)) continue;
					else if (sp >= 5 && sc < 5)
					{
						int dlt = dp[S(pre, sp)][0] + dp[S(suc, sc)][0] - rs[S(suc, sc)] - rs[S(pre, sp)];
						dp[x][1] = max(dp[x][1], c + dlt);
					}
					else
					{
						int dlt = 0;
						if (sp < 5 && sc < 5) dlt = d45[S(pre, sp)] + dp[S(suc, sc)][0];
						else if (sp >= 5 && sc >= 5) dlt = dp[S(pre, sp)][0] + d45[S(suc, sc)];
						else dlt = dp[S(pre, sp)][0] + dp[S(suc, sc)][0];
						if (fst)
						{
							if (sp >= 5) dlt -= sp45[pre];
							if (sc < 5) dlt -= sp45[suc];
						}
						dp[x][1] = max(dp[x][1], c + dlt);
					}
				}
			}
			if (S(pre, 9) == -1 || S(suc, 0) == -1) break;
			c += rn[S(pre, 9)] + rn[S(suc, 0)];
			pre = S(pre, 9), suc = S(suc, 0);
			fst = false;
		}
	}
}
char str[500010];
int main ()
{
	freopen("hadou.in", "r", stdin), freopen("hadou.out", "w", stdout);
	int n; while (scanf("%d", &n) == 1)
	{
		init();
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			int len = strlen(str);
			str[len++] = '0', str[len] = 0;
			ins(str + 2);
		}
		for (int i = mr - 1; i >= 0; i--) proc(i);
		printf("%d %d\n", dp[0][0], dp[0][1]);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}

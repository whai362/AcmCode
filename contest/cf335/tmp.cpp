/*======================================================
# Author: whai
# Last modified: 2015-12-10 01:41
# Filename: tmp.cpp
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

const int N = 100005;

struct edge
{
	int l, v, id, a, b;
} a[N];

int top[N];

bool cmp(edge a, edge b)
{
	if (a.l == b.l) return a.v > b.v;
	return a.l < b.l;
}
bool cmp1(edge a, edge b)
{
	return a.id < b.id;
}

vector<int> V;
P ans[N];

LL get_id(LL a, LL b) {
	return a * N + b;
}

int n, m;
int main()
{
	int i, j, k;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 1; i <= m; i++) {scanf("%d%d", &a[i].l, &a[i].v); a[i].id = i;}
		int now = 1, vi = 2, vj = 3;
		int st = 0;
		sort(a + 1, a + 1 + m, cmp);
		for (i = 1; i <= n; i++) top[i] = i + 1;
		for (i = 1; i <= m; i++)
		{
			if (a[i].v)
			{
				a[i].a = 1;
				a[i].b = ++now;
				st += now - 1;
			}
			else
			{
				if (i > st) break;
				if (top[vi] <= now)
				{
					a[i].a = vi;
					a[i].b = top[vi]++;
				}
				else
				{
					for (vi++;; vi++)
					{
						if (vi == now) vi = 2;
						if (top[vi] <= now)
							break;
					}
					a[i].a = vi;
					a[i].b = top[vi]++;
				}
			}
		}

		if (i != m + 1) {printf("-1\n"); continue;}
		sort(a + 1, a + 1 + m, cmp1);
		for (i = 1; i <= m; i++) printf("%d %d\n", a[i].a, a[i].b);
	}
	return 0;
}

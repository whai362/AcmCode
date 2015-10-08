// run: $exec < input > output
// opt: 0
#include <iostream>
#include <vector>

int const maxn = 60000;
int count[maxn];
int value[maxn];

int n, m;

std::vector<int> tree[maxn];

int gcd(int x, int y)
{
	return (!y) ? (x) : gcd(y, x % y);
}

void calc(int u, int p, int now)
{
	if (u != now) count[now] += (gcd(value[now], value[u]) == 1);
	for (int i = 0; i < (int)tree[u].size(); i++) {
		int v = tree[u][i];
		if (v == p) continue;
		calc(v, u, now);
	}
}

void dfs(int u, int p)
{
	calc(u, p, u);
	for (int i = 0; i < (int)tree[u].size(); i++) {
		int v = tree[u][i];
		if (v == p) continue;
		dfs(v, u);
	}
}

int main()
{
	for (int ti = 1; std::cin >> n ; ti++) {
		for (int i = 0; i <= n; i++) tree[i].clear();
		for (int i = 0; i <= n; i++) count[i] = 0;
		for (int i = 1, x, y; i < n; i++) {
			std::cin >> x >> y;
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) std::cin >> value[i];

		dfs(1, 0);

		std::cout << "Case #" << ti << ":";
		for (int i = 1; i <= n; i++) std::cout << ' ' << count[i];
		std::cout << '\n';
	}
}


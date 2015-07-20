#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

struct person
{
	std::string name;
	int ability;
	std::string position;
};

struct pair
{
	std::string s1, s2;
	int p;
};

std::istream & operator>>(std::istream & is, person & a)
{
	is >> a.name >> a.ability >> a.position;
	return is;
}

bool operator<(person const & a, person const & b)
{
	return a.position < b.position;
}

int const n = 23;
int m, ans;
int pos_goal, pos_def, pos_mid, pos_s; // 4-4-2

std::vector<person> da(n);
std::vector<pair> extra;
std::map<std::string, int> index;

bool check_possible()
{
	pos_goal = pos_def = pos_mid = 0, pos_s = n;
	for (pos_def = 0; pos_def < n && da[pos_def].position == "defender"; pos_def++);
	if (pos_def < 4) return false;

	for (pos_goal = pos_def; pos_goal < n && da[pos_goal].position == "goalkeeper"; pos_goal++);
	if (pos_goal - pos_def < 1) return false;

	for (pos_mid = pos_goal; pos_mid < n && da[pos_mid].position == "midfielder"; pos_mid++);
	if (pos_mid - pos_goal < 4) return false;

	if (pos_s - pos_mid < 2) return false;
	return true;
}

bool vis[n + 4];

void check()
{
	int g = 0, d = 0, mid = 0, s = 0, sum = 0;
	for (int i = 0; i < n; i++)
		if (vis[i]) {
			sum += da[i].ability;
			if (da[i].position[0] == 'g') g++;
			else
			if (da[i].position[0] == 'd') d++;
			else
			if (da[i].position[0] == 'm') mid++;
			else
			if (da[i].position[0] == 's') s++;
		}
	if (g < 1 || mid < 4 || s < 2 || d < 4) return;
	for (int i = 0; i < m; i++) {
		int p1 = index[extra[i].s1], p2 = index[extra[i].s2];
		if (vis[p1] && vis[p2]) sum += extra[i].p;
	}
	ans = std::max(ans, sum);
}

void dfs(int index, int deep, int d, int m, int s, int g)
{
	if (index >= 23) return ; 
	if (deep == 11) {
		check();
		return;
	}
	if (index >= pos_def && d < 4) return;
	if (index >= pos_goal && g < 1) return;
	if (index >= pos_mid && m < 4) return;
	if (index >= pos_s && s < 2) return;
	for (int i = index; i < n; i++) {
		if (!vis[i]) {
			int td = d, tm = m, ts = s, tg = g;
			if (da[i].position[0] == 'd') td++;
			if (da[i].position[0] == 'm') tm++;
			if (da[i].position[0] == 's') ts++;
			if (da[i].position[0] == 'g') tg++;
			vis[i] = true;
			dfs(i+1, deep+1, td, tm, ts, tg);
			vis[i] = false;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	while (std::cin >> da[0]) {
		index.clear();
		for (int i = 1; i < n; i++) std::cin >> da[i];
		std::cin >> m;
		extra.resize(m);
		for (int i = 0; i < m; i++) {
			std::cin >> extra[i].s1 >> extra[i].s2 >> extra[i].p;
		}

		std::sort(da.begin(), da.end());
		for (int i = 0; i < n; i++) index[da[i].name] = i;

		if (!check_possible()) {
			std::cout << "impossible\n";
			continue;
		}

		for (int i = 0; i < n; i++) vis[i] = false;
		ans=-100000000;
		dfs(0, 0, 0, 0, 0, 0);
		std::cout << ans << '\n';
	}

}

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>

int n = 7;
std::string t(n, 'z');
std::map<int, std::string> count;
std::string magic = "aababb";

bool judge(std::string const & s)
{
	std::string t = s;
	std::reverse(t.begin(), t.end());
	return s == t;
}

void dfs(int d, std::string s)
{
	if (d == n) {
		std::set<std::string> all;
		for (int i = 0; i < n; i++)
			for (int j = 1; i + j - 1 < n; j++) {
				std::string tmp = s.substr(i, j);
				if (judge(tmp)) all.insert(tmp);
			}
		int t = all.size();
		if (count.find(t) != count.end()) {
			if (count[t] > s) count[t] = s;
		} else count[t] = s;
		return;
	}
	dfs(d + 1, s+'a');
	dfs(d + 1, s+'b');
}

int main()
{
	std::string ss = "AABABBAABABBAABABBAABABB";
	std::set<std::string> all;
	n = ss.size();
	for (int i = 0; i < n; i++)
		for (int j = 1; i + j - 1 < n; j++) {
			std::string tmp = ss.substr(i, j);
			if (judge(tmp)) all.insert(tmp);
		}
	std::cout << "::" << all.size() << '\n';
	return 0;
	//std::string s;
	//std::cout << " n = " << n << '\n';
	//dfs(0, s);
	//for (auto i : count) std::cout << i.second << ' ' << i.first << '\n';
}


// run: $exec < input
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
string t;

bool vis[30];

bool judge()
{
	if (t.size() < s.size() || (s.size() == t.size() && s != t)) return false;
	int cnt = 0;
	int i = 0, j = 0;
	int op_cnt = 0;
	s += '#';
	while(j < t.size()) {
		//cout<<i<<' '<<j<<endl;
		if(s[i] == t[j]){
			++i;
			++j;
			if(vis[s[i - 1] - 'a'] == 0) {
				++cnt;
				vis[s[i - 1] - 'a'] = 1;
			}
		} else {
			if(i == 0) return false;
			else if(s[i - 1] == t[j]) {
				if(cnt <= 1) return false;
				++op_cnt;
			} else {
				if(cnt == 0) return false;
				++op_cnt;
			}
			++j;
			if(s[i] != '#' && vis[s[i] - 'a'] == 0) {
				++cnt;
				vis[s[i] - 'a'] = 1;
			}
			if(vis[t[j - 1] - 'a'] == 0) {
				++cnt;
				vis[t[j - 1] - 'a'] = 1;
			}
		}
	}
	//cout<<op_cnt<<endl;
	return s.size() - 1 + op_cnt == t.size();
}

int main()
{
	ios::sync_with_stdio(false);
	int T; cin >> T;

	while (T--) {
		cin >> s >> t;
		memset(vis, 0, sizeof(vis));
		if (judge())
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}


/*======================================================
# Author: whai
# Last modified: 2015-11-14 16:29
# Filename: judge.cpp
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

bool judge(string const & s)
{
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}


int main() {
	string ss;
	int ans;
	while(cin>>ss) {
		if(ss == "Impossible") continue;
		cin>>ans;
		set<std::string> all;
		int n = ss.size();
		for (int i = 0; i < n; i++)
			for (int j = 1; i + j - 1 < n; j++) {
				string tmp = ss.substr(i, j);
				if (judge(tmp)) all.insert(tmp);
			}
		//std::cout << "::" << all.size() << '\n';
		if(all.size() == ans) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<' '<<ss<<' '<<ans<<' '<<all.size()<<endl;
		}
	}
	return 0;
}


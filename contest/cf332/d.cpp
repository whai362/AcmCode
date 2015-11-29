/*======================================================
# Author: whai
# Last modified: 2015-11-23 21:28
# Filename: d.cpp
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
#define P pair<LL, LL>
#define X first
#define Y second

set<P> ans;
set<P>::iterator it;
int main() {
	LL x;
	while(cin>>x) {
		ans.clear();
		LL sub = 0;
		LL div = 1;
		LL cnt = 1;
		while(sub <= x) {
			if((x - sub) % div == 0) {
				LL A = cnt;
				LL B = (x - sub) / div + A - 1;
				ans.insert(P(A, B));
				ans.insert(P(B, A));
			}
			++cnt;
			sub += cnt * (cnt - 1);
			div += cnt;
			//cout<<sub<<' '<<div<<endl;
		}
		cout<<ans.size()<<endl;
		for(it = ans.begin(); it != ans.end(); ++it) {
			cout<<(*it).X<<' '<<(*it).Y<<endl;
		}
	}
	return 0;
}


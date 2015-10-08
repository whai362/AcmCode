#include <iostream>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

map<int, set<int>> c1, c2;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		init();
		for(int i = 0; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(c1.find(u) == c1.end()) {
				set<int> tmp;
				tmp.clear();
				c1[u] = tmp;
			}
			c1[u].insert(v);

			if(c2.find(v) == c2.end()) {
				set<int> tmp;
				tmp.clear();
				c2[v] = tmp;
			}
			c2[v].insert(u);
		}
		int c1 = 0, c2 = 0, c3 = 0;
		for(it = c1.begin(); it != c1.end(); ++it) {
			set<int> tmp = (*it).Y;
			for(it1 = tmp.begin(); it1 != tmp.end(); ++it1) {
				int id = (*it1);

			}
		}
	}
}

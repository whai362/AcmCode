#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(u == 1) {
			a.insert(lower_bound(a.begin(), a.end(), v), v);
		} else if(u == 2) {
			a.erase(lower_bound(a.begin(), a.end(), v));
		} else if(u == 3) {
			int ans = lower_bound(a.begin(), a.end(), v) - a.begin() + 1;
			printf("%d\n", ans);
		} else if(u == 4) {
			printf("%d\n", a[v - 1]);
		} else if(u == 5) {
			int pos = lower_bound(a.begin(), a.end(), v) - 1 - a.begin();
			printf("%d\n", a[pos]);
		} else {
			int pos = upper_bound(a.begin(), a.end(), v) - a.begin();
			printf("%d\n", a[pos]);
		}
	}
	return 0;
}

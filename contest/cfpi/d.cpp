#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int N = 2 * 1e5 + 5;

int x[N];

set<int> pos;
set<int> :: iterator it;

void gao(int n, int k, int a, int m) {
	pos.insert(0);
	pos.insert(n + 1);
	++a;
	int all = (n + 1) / a;
	for(int i = 0; i < m; ++i) {
		it = pos.lower_bound(x[i]);
		int R = *it;
		--it;
		int L = *it;
		//cout<<L<<' '<<R<<endl;
		int len = R - L;
		all -= len / a;
		pos.insert(x[i]);
		all += (x[i] - L) / a;
		all += (R - x[i]) / a;
		//cout<<all<<endl;
		if(all < k) {
			printf("%d\n", i + 1);
			return ;
		}
	}
	puts("-1");
}


int main() {
	int n, k, a;
	scanf("%d%d%d", &n, &k, &a);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
		scanf("%d", &x[i]);
	gao(n, k, a, m);
	return 0;
}

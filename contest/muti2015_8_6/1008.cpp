#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
#define LL __int64
#define P pair<int, int>
#define PP pair<P, int>
#define X first
#define Y second
const int N = 1e5 + 5;
PP e[N];

set<P> my_set;
set<P> :: iterator it;

int ans[N], tot;
bool used[N];

void gao(int n) {
	int pi = 0;
	while(1){
		while(pi < n && e[pi].X.X <= tot) {
			my_set.insert(P(e[pi].X.Y, e[pi].Y));
			//cout<<"!"<<e[pi].X.Y<<' '<<e[pi].Y<<endl;
			++pi;
		}
		//cout<<"?"<<my_set.size()<<endl;
		if(my_set.empty()) break;
		it = my_set.begin();
		if((*it).X >= tot){
			ans[tot] = (*it).Y + 1;
			used[ans[tot]] = 1;
			++tot;
		}
		my_set.erase(it);
	}
	printf("%d\n", tot);
	for(int i = 1; i <= n; ++i) {
		if(used[i] == 0) ans[tot++] = i;
	}
	for(int i = 0; i < tot; ++i) {
		printf("%d%c", ans[i], i == tot - 1 ? '\n':' ');
	}
}

void init(int n) {
	my_set.clear();
	tot = 0;
	memset(used, 0, sizeof(used));
}

int main() {
	int n;
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		init(n);
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%I64d", &e[i].X.X);
		}
		for(int i = 0; i < n; ++i) {
			scanf("%I64d", &e[i].X.Y);
			e[i].Y = i;
		}
		sort(e, e + n);
		//for(int i = 0; i < n; ++i) {
		//	cout<<e[i].X.X<<' '<<e[i].X.Y<<' '<<e[i].Y<<endl;
		//}
		gao(n);
	}
	return 0;
}

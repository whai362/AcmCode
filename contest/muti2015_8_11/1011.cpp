#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <cassert>
using namespace std;
#pragma comment(linker,"/STACK:102400000,102400000")
#define LL __int64
#define PB push_back
const int N = 1e5 + 5;
const int MOD = 1000000007;
vector<int> G[N];

int dfs(int u, int fa) {
	int c1 = 0, c2 = 0;
	for(int i = 0; i < G[u].size(); ++i) {
		if(G[u][i] == fa) continue;
		ret = max(ret, dfs(G[u][i], u));
	}
}

void gao() {
	int len = dfs(1, -1);
	cout<<ans<<endl;
}
void init(int n) {
	for(int i = 0; i <= n; ++i)
		G[i].clear();
}
int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		int n;
		scanf("%d", &n);
		init(n);
		for(int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].PB(v);
			G[v].PB(u);
		}
		printf("Case #%d: ", ++cas);
		gao();
	}
	return 0;
}

/*hdu 5329 Question for the Leader
  题意：
  给出一个有n个点的图，这个图是由一个基环 + 若干外向树组成，问能否把这个图分成 k个 大小为n/k 的 连通的子图，问k有多少种。
  限制：
  1 <= n <= 1e5
  思路：
  主要是一个性质：
  对于一棵树，如果可以把这棵树分成大小都为k的n/k份，那子树大小是k的倍数的节点恰好有n/k个。(任意选定一个根)
  详细见多校官方题解
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define PB push_back
const int N = 1e5 + 5;
int a[N];

int cir[N], cir_tot;
bool in_cir[N];

int tree_sz[N];
int cnt[N];

vector<int> G[N];

int fa[N];
void init_bcj(int n) {
	for(int i = 0; i <= n; ++i)
		fa[i] = i;
}
int get_fa(int x) {
	if(x != fa[x]) return fa[x] = get_fa(fa[x]);
	return x;
}

int dfs(int u, int fa) {
	tree_sz[u] = 1;
	for(int i = 0; i < G[u].size(); ++i) {
		int ch = G[u][i];
		if(ch == fa || in_cir[ch]) continue;
		tree_sz[u] += dfs(ch, u);
	}
	return tree_sz[u];
}

int sum[N], sum_cnt[N];
bool ok(int bei, int have, int n) {
	for(int i = 0; i < bei; ++i)
		sum_cnt[i] = 0;
	sum[0] = tree_sz[cir[0]] % bei;
	++sum_cnt[sum[0]];
	for(int i = 1; i < cir_tot; ++i) {
		sum[i] = (sum[i - 1] + tree_sz[cir[i]]) % bei;
		++sum_cnt[sum[i]];
	}
	if(sum_cnt[0] + have == n / bei) return true;
	int last = cir_tot - 1;
	for(int i = 0; i < cir_tot - 1; ++i) {
		--sum_cnt[sum[i]];
		int tmp = sum[i];
		sum[i] = (sum[last] + tree_sz[cir[i]]) % bei;
		++sum_cnt[sum[i]];
		if(sum_cnt[tmp] + have == n / bei) return true;
		last = i;
	}
	return false;
}

void gao(int n) {
	cir_tot = 0;
	for(int i = 1; i <= n; ++i) {
		G[i].PB(a[i]);
		G[a[i]].PB(i);
		int fx = get_fa(i);
		int fy = get_fa(a[i]);
		if(fx != fy) fa[fy] = fx;
		else if(cir_tot == 0){
			cir[cir_tot++] = i;
			in_cir[i] = 1;
		}
	}

	int nxt = a[cir[0]];
	while(nxt != cir[0]) {
		cir[cir_tot++] = nxt;
		in_cir[nxt] = 1;
		nxt = a[nxt];
	}
	
	for(int i = 1; i <= n; ++i) {
		if(in_cir[i]) dfs(i, -1);
	}

	for(int i = 1; i <= n; ++i)
		if(!in_cir[i]) ++cnt[tree_sz[i]];

	for(int i = 1; i <= n; ++i) {
		for(int j = 2 * i; j <= n; j += i) {
			cnt[i] += cnt[j];
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(n % i) continue;
		if(ok(i, cnt[i], n)){
			++ans;
		}
	}
	printf("%d\n", ans);
}

void init(int n) {
	init_bcj(n);
	memset(in_cir, 0, sizeof(in_cir));
	memset(tree_sz, 0, sizeof(tree_sz));
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i <= n; ++i)
		G[i].clear();
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		init(n);
		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		gao(n);
	}
	return 0;
}

/*poj 1330 Nearest Common Ancestors
  题意：
  给出一棵大小为n的树和一个询问(u,v), 问(u,v)的最近公共祖先。
  限制：
  2 <= n <= 10000
  思路：
  离线tarjan
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define PB push_back
const int N = 10005;

int fa[N];
vector<int> tree[N], query[N];
int anc[N];	//ancestor
bool vis[N];
int get_fa(int x) {
	if (x != fa[x]) return fa[x] = get_fa(fa[x]);
	return x;
}

void merge(int x, int y) {
	int fa_x = get_fa(x);
	int fa_y = get_fa(y);
	if (fa_x == fa_y) return ;
	fa[fa_y] = fa_x;
}
//就是把搜过的合并在一起
void LCA(int rt) {
	anc[rt] = rt;
	for (int i = 0; i < tree[rt].size(); ++i) {
		int ch = tree[rt][i];
		LCA(ch);
		merge(rt, ch);
		//cout<<rt<<' '<<ch<<' '<<get_fa(ch)<<endl;
		anc[get_fa(ch)] = rt;
	}
	vis[rt] = true;
	for (int i = 0; i < query[rt].size(); ++i) {
		if (vis[query[rt][i]]) {
			cout << anc[get_fa(query[rt][i])] << endl;
			return ;
		}
	}
}
void init(int n) {
	memset(vis, 0, sizeof(vis));
	memset(anc, 0, sizeof(anc));
	for (int i = 0; i <= n; ++i) {
		fa[i] = i;
		tree[i].clear();
		query[i].clear();
	}
}

int indeg[N];
void gao(int n) {
	for (int i = 1; i <= n; ++i) {
		if (indeg[i] == 0) {
			LCA(i);
			break;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		init(n);
		int u, v;
		for (int i = 0; i < n - 1; ++i) {
			scanf("%d%d", &u, &v);
			tree[u].PB(v);
			++indeg[v];
		}
		scanf("%d%d", &u, &v);
		query[u].PB(v);
		query[v].PB(u);
		gao(n);
	}
	return 0;
}

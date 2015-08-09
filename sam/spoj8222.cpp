#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 250005;

//注意，后缀自动机的节点要开2倍n，根是从1开始的
struct SAM {
	struct Node {
		int fa, ch[27];
		int val, ans;
		void init() {
			fa = 0;
			memset(ch, 0, sizeof(ch));
			val = 0;
			ans = 0;
		}
	} node[2*N];
	
	int tot;
	int new_node() {
		node[++tot].init();
		return tot;
	}

	int root, last;
	void init() {
		tot = 1;
		root = last = 1;
		node[0].init();
		node[root].init();
	}
	void add(int x) {
		int p = last;
		int np = new_node(); node[np].val = node[p].val + 1;
		while(p && node[p].ch[x] == 0)
			node[p].ch[x] = np, p = node[p].fa;
		if(p == 0)
			node[np].fa = root;
		else {
			int q = node[p].ch[x];
			if(node[p].val + 1 == node[q].val)
				node[np].fa = q;
			else {
				int nq = new_node(); node[nq].val = node[p].val + 1;
				memcpy(node[nq].ch, node[q].ch, sizeof(node[nq].ch));
				node[nq].fa = node[q].fa;
				node[q].fa = node[np].fa = nq;
				while(p && node[p].ch[x] == q)
					node[p].ch[x] = nq, p = node[p].fa;
			}
		}
		last = np;
	}
}sam;

char str[N];
int cnt[N];
int dp[N];

void init() {
	sam.init();
	memset(cnt, 0, sizeof(cnt));
	memset(dp, 0, sizeof(dp));
}

int b[2*N];

int main() {
	while(scanf("%s", str) != EOF) {
		int n = strlen(str);
		init();
		for(int i = 0; i < n; ++i)
			sam.add(str[i] - 'a');
		for(int i = 1; i <= sam.tot; ++i)
			++cnt[sam.node[i].val];
		for(int i = 1; i <= n; ++i)
			cnt[i] += cnt[i - 1];
		for(int i = 0; i < n; ++i) {
			sam.root = sam.node[sam.root].ch[str[i] - 'a'];
			++sam.node[sam.root].ans;
		}
		for(int i = 1; i <= sam.tot; ++i)
			b[--cnt[sam.node[i].val]] = i;
		for(int i = sam.tot - 1; i > 0; --i) {
			dp[sam.node[b[i]].val] = max(dp[sam.node[b[i]].val], sam.node[b[i]].ans);
			if(sam.node[b[i]].fa)
				sam.node[sam.node[b[i]].fa].ans += sam.node[b[i]].ans;
		}
		for(int i = n - 1; i > 0; --i)
			dp[i] = max(dp[i], dp[i + 1]);
		for(int i = 1; i <= n; ++i)
			printf("%d\n", dp[i]);
	}
	return 0;
}

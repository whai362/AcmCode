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
	void debug() {
		for(int i = 1; i <= tot; ++i) {
			printf("id=%d, fa=%d, step=%d, ch=[ ", i, node[i].fa, node[i].val);
			for(int j = 0; j < 26; ++j) {
				if(node[i].ch[j])
					printf("%c,%d ", j+'a', node[i].ch[j]);
			}
			puts("]");
		}
	}
	void gao(int);
}sam;

char str[N];
int cnt[N];
int dp[N];
int b[2*N];

void init() {
	sam.init();
	memset(cnt, 0, sizeof(cnt));
	memset(dp, 0, sizeof(dp));
}

void SAM::gao(int n) {
	for(int i = 1; i <= tot; ++i)
		++cnt[node[i].val];
	for(int i = 1; i <= n; ++i)
		cnt[i] += cnt[i - 1];
	for(int i = 0; i < n; ++i) {
		root = node[root].ch[str[i] - 'a'];
		++node[root].ans;
	}
	for(int i = 1; i <= tot; ++i)
		b[--cnt[node[i].val]] = i;
	for(int i = tot - 1; i > 0; --i) {
		dp[node[b[i]].val] = max(dp[node[b[i]].val], node[b[i]].ans);
		if(node[b[i]].fa)
			node[node[b[i]].fa].ans += node[b[i]].ans;
	}
	for(int i = n - 1; i > 0; --i)
		dp[i] = max(dp[i], dp[i + 1]);
	for(int i = 1; i <= n; ++i)
		printf("%d\n", dp[i]);
}

int main() {
	while(scanf("%s", str) != EOF) {
		int n = strlen(str);
		init();
		for(int i = 0; i < n; ++i)
			sam.add(str[i] - 'a');
		//sam.debug();
		sam.gao(n);
	}
	return 0;
}

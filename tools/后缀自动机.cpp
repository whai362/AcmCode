/*spoj 8222
  题意：
  给一个字符串S，令F(x)表示S的所有长度为x的子串中，出现次数的最大值。求F(1)..F(Length(S))。
  限制：
  |S| <= 250000
  思路：
  后缀自动机
  后缀自动机理解关键点：
  1. 根到任意一个结点都可以形成S的一个子串，并且S的所有子串都可以通过这种方式形成;
  2. 到达该节点是所有路径就是一个right集合，一个拥有相同后缀的right集合;
  3. 设某子串为str，这后缀自动机读入str后能到达的状态为right(str)，即str在S中出现的位置的集合;
  4. 假设node[b].fa = a，则状态a可以代替状态b进行识别。
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
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
	} node[2 * N];

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
		while (p && node[p].ch[x] == 0)
			node[p].ch[x] = np, p = node[p].fa;
		if (p == 0)
			node[np].fa = root;
		else {
			int q = node[p].ch[x];
			if (node[p].val + 1 == node[q].val)
				node[np].fa = q;
			else {
				int nq = new_node(); node[nq].val = node[p].val + 1;
				memcpy(node[nq].ch, node[q].ch, sizeof(node[nq].ch));
				node[nq].fa = node[q].fa;
				node[q].fa = node[np].fa = nq;
				while (p && node[p].ch[x] == q)
					node[p].ch[x] = nq, p = node[p].fa;
			}
		}
		last = np;
	}
	void debug() {
		for (int i = 1; i <= tot; ++i) {
			printf("id=%d, fa=%d, step=%d, ch=[ ", i, node[i].fa, node[i].val);
			for (int j = 0; j < 26; ++j) {
				if (node[i].ch[j])
					printf("%c,%d ", j + 'a', node[i].ch[j]);
			}
			puts("]");
		}
	}
	void gao(int);
} sam;

char str[N];

int du[2 * N];
int cnt[2 * N];
int ans[N];

void init() {
	sam.init();
	memset(du, 0, sizeof(du));
	memset(ans, 0, sizeof(ans));
	memset(cnt, 0, sizeof(cnt));
}

int que[2 * N], fr, ta;

void SAM::gao(int n) {
	for (int i = 1; i <= tot; ++i) {
		++du[node[i].fa];
	}
	int tmp = root;
	for (int i = 0; i < n; ++i) {
		tmp = node[tmp].ch[str[i] - 'a'];
		cnt[tmp] = 1;
	}
	fr = ta = 0;
	for (int i = 1; i <= tot; ++i) {
		if (du[i] == 0) {
			que[ta++] = i;
		}
	}
	while (fr != ta) {
		int now = que[fr++];
		--du[node[now].fa];
		cnt[node[now].fa] += cnt[now];
		if (du[node[now].fa] == 0) {
			que[ta++] = node[now].fa;
		}
	}

	for (int i = 2; i <= tot; ++i) {
		ans[node[i].val] = max(ans[node[i].val], cnt[i]);
	}
	for (int i = n - 1; i >= 1; --i) {
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", ans[i]);
	}
}

int main() {
	while (gets(str)) {
		int n = strlen(str);
		init();
		for (int i = 0; i < n; ++i)
			sam.add(str[i] - 'a');
		//sam.debug();
		sam.gao(n);
	}
	return 0;
}

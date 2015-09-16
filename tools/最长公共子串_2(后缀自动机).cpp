/*spoj 1811 LCS - Longest Common Substring
  题意：
  给出两个串S, T, 求最长公共子串。
  限制：
  |S|, |T| <= 1e5
  思路：
  dp O(n^2) 铁定超时
  后缀数组 O(nlog(n)) 在spoj上没试过，感觉也会被卡掉
  后缀自动机 O(n)

  我们考虑用SAM读入字符串B;
  令当前状态为s，同时最大匹配长度为len;
  我们读入字符x。如果s有标号为x的边，那么s=trans(s,x),len = len+1;
  否则我们找到s的第一个祖先a，它有标号为x的边，令s=trans(a,x),len=Max(a)+1;
  如果没有这样的祖先，那么令s=root,len=0;
  在过程中更新状态的最大匹配长度。

  详情参考clj论文
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 3 * 1e5;
char S[N], T[N];

struct SAM {
	struct Node {
		int fa, ch[27];
		int val;
		void init() {
			fa = val = 0;
			memset(ch, 0, sizeof(ch));
		}
	} node[2 * N];

	int tot;
	int new_node() {
		node[++tot].init();
		return tot;
	}

	int root, last;
	void init() {
		tot = root = last = 1;
		node[0].init();
		node[1].init();
	}

	void add(int x) {
		int p = last;
		int np = new_node(); node[np].val = node[p].val + 1;
		while (p && node[p].ch[x] == 0) {
			node[p].ch[x] = np;
			p = node[p].fa;
		}
		if (p == 0) node[np].fa = root;
		else {
			int q = node[p].ch[x];
			if (node[p].val + 1 == node[q].val)
				node[np].fa = q;
			else {
				int nq = new_node(); node[nq].val = node[p].val + 1;
				memcpy(node[nq].ch, node[q].ch, sizeof(node[q].ch));
				node[nq].fa = node[q].fa;
				node[q].fa = node[np].fa = nq;
				while (p && node[p].ch[x] == q) {
					node[p].ch[x] = nq;
					p = node[p].fa;
				}
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

	void gao();
} sam;

void SAM::gao() {
	int len_s = strlen(S);
	int len_t = strlen(T);

	init();
	for (int i = 0; i < len_s; ++i) {
		add(S[i] - 'a');
	}
	//debug();
	int p = root;
	int ans = 0;
	int tmp = 0;
	for (int i = 0; i < len_t; ++i) {
		if (node[p].ch[T[i] - 'a']) {
			++tmp;
			p = node[p].ch[T[i] - 'a'];
		} else {
			while (p && node[p].ch[T[i] - 'a'] == 0)
				p = node[p].fa;
			if (p) {
				tmp = node[p].val + 1;
				p = node[p].ch[T[i] - 'a'];
			} else {
				p = root;
				tmp = 0;
			}
		}
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);
}

int main() {
	scanf("%s%s", S, T);
	sam.gao();
	return 0;
}

/*bzoj 3224
  题意：
  您需要写一种数据结构（可参考题目标题），来维护一些数，其中需要提供以下操作：
  1. 插入x数
  2. 删除x数(若有多个相同的数，因只删除一个)
  3. 查询x数的排名(若有多个相同的数，因输出最小的排名)
  4. 查询排名为x的数
  5. 求x的前驱(前驱定义为小于x，且最大的数)
  6. 求x的后继(后继定义为大于x，且最小的数)
  限制：
  n的数据范围：n<=100000
  每个数的数据范围：[-1e7,1e7]
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define LS(x) node[(x)].l
#define RS(x) node[(x)].r

const int N = 1e5 + 5;

struct Treap {
	struct Node {
		int l, r;
		int val, cnt, rnd, size;
	} node[N];

	int root, tot;
	void init() {
		//root一开始是0，插入一个元素后都是1
		root = tot = 0;
	}

	void up(int x) {
		node[x].size = node[LS(x)].size + node[RS(x)].size + node[x].cnt;
	}
	void r_turn(int &x) {
		int tmp = LS(x); LS(x) = RS(tmp); RS(tmp) = x;
		node[tmp].size = node[x].size;
		up(x);
		x = tmp;
	}
	void l_turn(int &x) {
		int tmp = RS(x); RS(x) = LS(tmp); LS(tmp) = x;
		node[tmp].size = node[x].size;
		up(x);
		x = tmp;
	}
	void insert(int &x, int val) {
		if (x == 0) {
			++tot; x = tot;
			node[x].size = node[x].cnt = 1;
			node[x].val = val;
			node[x].rnd = rand();
			return ;
		}
		++node[x].size;
		if (node[x].val == val) ++node[x].cnt;
		else if (val > node[x].val) {
			insert(RS(x), val);
			if (node[RS(x)].rnd < node[x].rnd) l_turn(x);
		} else {
			insert(LS(x), val);
			if (node[LS(x)].rnd < node[x].rnd) r_turn(x);
		}
	}
	void del(int &x, int val) {
		if (x == 0) return ;
		if (node[x].val == val) {
			if (node[x].cnt > 1) {
				--node[x].cnt;
				--node[x].size;
				return ;
			}
			if (LS(x) * RS(x) == 0) x = LS(x) + RS(x);
			else if (node[LS(x)].rnd < node[RS(x)].rnd) {
				r_turn(x);
				del(x, val);
			} else {
				l_turn(x);
				del(x, val);
			}
		} else if (val > node[x].val) {
			--node[x].size;
			del(RS(x), val);
		} else {
			--node[x].size;
			del(LS(x), val);
		}
	}

	int query_rank(int x, int val) {
		if (x == 0) return 0;
		if (node[x].val == val) return node[LS(x)].size + 1;
		else if (val > node[x].val) {
			return node[LS(x)].size + node[x].cnt + query_rank(RS(x), val);
		} else {
			return query_rank(LS(x), val);
		}
	}
	int query_num(int x, int pos) {
		if (x == 0) return 0;
		if (pos <= node[LS(x)].size) {
			return query_num(LS(x), pos);
		} else if (pos > node[LS(x)].size + node[x].cnt) {
			return query_num(RS(x), pos - node[LS(x)].size - node[x].cnt);
		} else {
			return node[x].val;
		}
	}
	void query_pre(int x, int val, int &ans) {
		if (x == 0) return ;
		if (node[x].val < val) {
			ans = x;
			query_pre(RS(x), val, ans);
		} else {
			query_pre(LS(x), val, ans);
		}
	}
	void query_nxt(int x, int val, int &ans) {
		if (x == 0) return ;
		if (node[x].val > val) {
			ans = x;
			query_nxt(LS(x), val, ans);
		} else {
			query_nxt(RS(x), val, ans);
		}
	}
} treap;

int main() {
	int n;
	scanf("%d", &n);
	int op, x;
	treap.init();
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &op, &x);
		if (op == 1) treap.insert(treap.root, x);
		else if (op == 2) treap.del(treap.root, x);
		else if (op == 3) printf("%d\n", treap.query_rank(treap.root, x));
		else if (op == 4) printf("%d\n", treap.query_num(treap.root, x));
		else if (op == 5) {
			int ans = 0;
			treap.query_pre(treap.root, x, ans);
			printf("%d\n", treap.node[ans].val);
		} else {
			int ans = 0;
			treap.query_nxt(treap.root, x, ans);
			printf("%d\n", treap.node[ans].val);
		}
	}
	return 0;
}

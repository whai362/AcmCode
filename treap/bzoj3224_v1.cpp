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

	int tot;

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
		if(x == 0) {
			++tot; x = tot;
			node[x].size = node[x].cnt = 1;
			node[x].val = val;
			node[x].rnd = rand();
			return ;
		}
		++node[x].size;
		if(node[x].val == val) ++node[x].cnt;
		else if(val > node[x].val) {
			insert(RS(x), val);
			if(node[RS(x)].rnd < node[x].rnd) l_turn(x);
		} else {
			insert(LS(x), val);
			if(node[LS(x)].rnd < node[x].rnd) r_turn(x);
		}
	}
	void del(int &x, int val) {
		if(x == 0) return ;
		if(node[x].val == val) {
			if(node[x].cnt > 1) {
				--node[x].cnt;
				--node[x].size;
				return ;
			}
			if(LS(x) * RS(x) == 0) x = LS(x) + RS(x);
			else if(node[LS(x)].rnd < node[RS(x)].rnd) {
				r_turn(x);
				del(x, val);
			} else {
				l_turn(x);
				del(x, val);
			}
		} else if(val > node[x].val) {
			--node[x].size;
			del(RS(x), val);
		} else {
			--node[x].size;
			del(LS(x), val);
		}
	}

	int query_rank(int x, int val) {
		if(x == 0) return 0;
		if(node[x].val == val) return node[LS(x)].size + 1;
		else if(val > node[x].val) {
			return node[LS(x)].size + node[x].cnt + query_rank(RS(x), val);
		} else {
			return query_rank(LS(x), val);
		}
	}
	int query_num(int x, int pos) {
		if(x == 0) return 0;
		if(pos <= node[LS(x)].size) {
			return query_num(LS(x), pos);
		} else if(pos > node[LS(x)].size + node[x].cnt) {
			return query_num(RS(x), pos - node[LS(x)].size - node[x].cnt);
		} else {
			return node[x].val;
		}
	}
	void query_pre(int x, int val, int &ans) {
		if(x == 0) return ;
		if(node[x].val < val) {
			ans = x;
			query_pre(RS(x), val, ans);
		} else {
			query_pre(LS(x), val, ans);
		}
	}
	void query_nxt(int x, int val, int &ans) {
		if(x == 0) return ;
		if(node[x].val > val) {
			ans = x;
			query_nxt(LS(x), val, ans);
		} else {
			query_nxt(RS(x), val, ans);
		}
	}
} treap;

int main() {
	int n, root = 0;
	scanf("%d", &n);
	int op, x;
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &op, &x);
		if(op == 1) treap.insert(root, x);
		else if(op == 2) treap.del(root, x);
		else if(op == 3) printf("%d\n", treap.query_rank(root, x));
		else if(op == 4) printf("%d\n", treap.query_num(root, x));
		else if(op == 5) {
			int ans = 0;
			treap.query_pre(root, x, ans);
			printf("%d\n", treap.node[ans].val);
		} else {
			int ans = 0;
			treap.query_nxt(root, x, ans);
			printf("%d\n", treap.node[ans].val);
		}
	}
	return 0;
}

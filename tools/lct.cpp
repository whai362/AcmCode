/*bzoj 2049 Cave 洞穴勘测
  题意：
  有n个点，一开始都是彼此分开的。给m个操作，操作有三种类型：
  1. 加边;
  2. 删边;
  3. 求在某状态下两点之间的联通状态。
  限制：
  n <= 10000; m <= 2000000
  思路：
  lct
 */
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e4 + 5;

#define LS(x) node[(x)].ch[0]
#define RS(x) node[(x)].ch[1]

struct LCT {
	struct Node {
		int fa, ch[2];
		bool rev;
		void init() {
			fa = 0;
			rev = ch[0] = ch[1] = 0;
		}
	} node[N];

	bool is_root(int x) {
		return (LS(node[x].fa) != x && RS(node[x].fa) != x);
	}

	void down(int x) {
		if(node[x].rev) {
			node[LS(x)].rev ^= 1;
			node[RS(x)].rev ^= 1;
			swap(LS(x), RS(x));
			node[x].rev = 0;
		}
	}

	void rotate(int x, bool kind) {
		int fx = node[x].fa;
		int ffx = node[fx].fa;
		node[fx].ch[!kind] = node[x].ch[kind];
		node[node[x].ch[kind]].fa = fx;
		
		if(!is_root(fx))
			node[ffx].ch[RS(ffx) == fx] = x;
		node[x].fa = ffx;

		node[x].ch[kind] = fx;
		node[fx].fa = x;
	}

	int down_stack[N], ds_top;

	void splay(int x) {
		ds_top = -1;
		down_stack[++ds_top] = x;
		for(int i = x; !is_root(i); i = node[i].fa)
			down_stack[++ds_top] = node[i].fa;
		for(int i = ds_top; i >= 0 ; --i) down(down_stack[i]);

		while(!is_root(x)) {
			int fx = node[x].fa;
			int ffx = node[fx].fa;
			bool rotate_x = (LS(fx) == x);
			bool rotate_fx = (LS(ffx) == fx);
			if(is_root(fx)) rotate(x, rotate_x);
			else {
				if(rotate_x == rotate_fx) rotate(fx, rotate_fx);
				else rotate(x, rotate_x);
				rotate(x, rotate_fx);
			}
		}
	}

	void access(int x) {
		int last = 0;
		while(x) {
			splay(x);
			RS(x) = last;
			last = x;
			x = node[x].fa;
		}
	}

	int find(int x) {
		access(x); splay(x);
		while(LS(x)) x = LS(x);
		return x;
	}

	void make_root(int x) {
		access(x); splay(x);
		node[x].rev ^= 1;
	}

	void cut(int x, int y) {
		make_root(x);
		access(y); splay(y);
		LS(y) = node[x].fa = 0;
	}

	void link(int x, int y) {
		make_root(x);
		node[x].fa = y;
	}
	void init(int n) {
		for(int i = 0; i <= n; ++i)
			node[i].init();
	}
} lct;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	lct.init(n);
	for(int i = 0; i < m; ++i) {
		char op[10];
		int x, y;
		scanf("%s%d%d", op, &x, &y);
		if(op[0] == 'Q') {
			int fx = lct.find(x);
			int fy = lct.find(y);
			if(fx == fy) puts("Yes");
			else puts("No");
		}
		else if(op[0] == 'C') lct.link(x, y);
		else lct.cut(x, y);
	}
	return 0;
}

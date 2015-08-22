#include <iostream>
#include <cstdio>
using namespace std;

#define LS(x) node[(x)].ch[0]
#define RS(x) node[(x)].ch[1]

const int N = 1e5 + 5;

struct Splay {
	struct Node {
		int fa, ch[2];
		bool rev;
		int val, size;
		void init(int _val) {
			val = _val;
			size = 1;
			rev = ch[0] = ch[1] = 0;
		}
	} node[N];

	int root;

	void up(int x) {
		node[x].size = node[LS(x)].size + node[RS(x)].size + 1;
	}

	void rotate(int x, bool kind) {
		int fx = node[x].fa;
		int ffx = node[fx].fa;
		node[fx].ch[!kind] = node[x].ch[kind];
		node[node[x].ch[kind]].fa = fx;

		node[x].ch[kind] = fx;
		node[fx].fa = x;

		node[ffx].ch[RS(ffx) == fx] = x;
		node[x].fa = ffx;
		up(fx);
	}

	void down(int x) {
		if(x == 0) return ;
		if(node[x].rev) {
			if(LS(x)) node[LS(x)].rev ^= 1;
			if(RS(x)) node[RS(x)].rev ^= 1;
			swap(LS(x), RS(x));
			node[x].rev = 0;
		}
	}

	void splay(int x, int goal) {
		while(node[x].fa != goal) {
			int fx = node[x].fa;
			int ffx = node[fx].fa;
			down(ffx); down(fx); down(x);
			bool rot_x = (LS(fx) == x);
			bool rot_fx = (LS(ffx) == fx);
			if(ffx == goal) rotate(x, rot_x);
			else {
				if(rot_x == rot_fx) rotate(fx, rot_fx);
				else rotate(x, rot_x);
				rotate(x, rot_fx);
			}
		}
		up(x);
		if(goal == 0) root = x;
	}

	int select(int pos) {
		int u = root;
		down(u);
		while(node[LS(u)].size != pos) {
			if(pos < node[LS(u)].size)
				u = LS(u);
			else {
				pos -= node[LS(u)].size + 1;
				u = RS(u);
			}
			down(u);
		}
		return u;
	}

	void rev(int L, int R) {
		int u = select(L - 1), v = select(R + 1);
		splay(u, 0); splay(v, u);
		node[LS(v)].rev ^= 1;
	}

	int build(int L, int R) {
		if(L > R) return 0;
		if(L == R) return L;
		int mid = (L + R) >> 1;
		int r_L, r_R;
		LS(mid) = r_L = build(L, mid - 1);
		RS(mid) = r_R = build(mid + 1, R);
		node[r_L].fa = node[r_R].fa = mid;
		up(mid);
		return mid;
	}

	void init(int n) {
		node[0].init(0); node[0].size = 0;
		node[1].init(0);
		node[n + 2].init(0);
		for(int i = 2; i <= n + 1; ++i)
			node[i].init(i - 1);
		root = build(1, n + 2);
	}
	void print(int);
} splay;

int ans[N], tot;

void Splay :: print(int u) {
	if(u == 0) return ;
	down(u);
	print(LS(u));
	if(node[u].val)
		ans[tot++] = node[u].val;
	print(RS(u));
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	splay.init(n);
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		splay.rev(u, v);
	}
	splay.print(splay.root);
	for(int i = 0; i < tot; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}

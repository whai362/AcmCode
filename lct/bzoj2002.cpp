#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2 * 1e5 + 5;

#define LS(x) node[(x)].ch[0]
#define RS(x) node[(x)].ch[1]

int nxt[N];

struct LCT {
	struct Node {
		int fa, ch[2];
		bool rev;
		int size;
		void init() {
			fa = 0;
			rev = ch[0] = ch[1] = 0;
			size = 1;
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

	void up(int x) {
		node[x].size = node[LS(x)].size + node[RS(x)].size + 1;
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
		up(fx);
	}

	int d_st[N], ds_top;

	void splay(int x) {
		ds_top = -1;
		d_st[++ds_top] = x;
		for(int i = x; !is_root(i); i = node[i].fa)
			d_st[++ds_top] = node[i].fa;
		for(int i = ds_top; i >= 0 ; --i) down(d_st[i]);

		while(!is_root(x)) {
			int fx = node[x].fa;
			int ffx = node[fx].fa;
			bool rot_x = (LS(fx) == x);
			bool rot_fx = (LS(ffx) == fx);
			if(is_root(fx)) rotate(x, rot_x);
			else {
				if(rot_x == rot_fx) rotate(fx, rot_fx);
				else rotate(x, rot_x);
				rotate(x, rot_fx);
			}
		}
		up(x);
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

	//access(x); splay(x); 后x在根的位置，此时x只有左子树，没有右子树，打翻转标记就是使得左子树变到右子树上。
	void make_root(int x) {
		access(x); splay(x);
		node[x].rev ^= 1;
	}

	void cut(int x, int y) {
		make_root(x);
		access(y); splay(y);
		LS(y) = node[x].fa = 0;
		up(y);
	}

	void link(int x, int y) {
		make_root(x);
		node[x].fa = y;
	}

	void init(int n) {
		for(int i = 0; i <= n; ++i)
			node[i].init();
		node[0].size = 0;
	}

	void debug(int n) {
		for(int i = 1; i <= n; ++i) {
			cout<<i<<": "<<node[i].size<<' '<<node[i].fa<<' '<<node[i].ch[0]<<' '<<node[i].ch[1]<<endl;
		}
	}

	void op1(int x, int n) {
		make_root(n + 1);
		access(x); splay(x);
		printf("%d\n", node[LS(x)].size);
	}

	void op2(int x, int y, int n) {
		int u = x, v = min(n + 1, x + y), z = nxt[x];
		cut(u, z);
		link(u, v);
		nxt[x] = v;
	}
} lct;

int main() {
	int n;
	scanf("%d", &n);
	lct.init(n + 1);
	for(int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		lct.node[i].fa = i + a;
		if(lct.node[i].fa > n) lct.node[i].fa = n + 1;
		nxt[i] = lct.node[i].fa;
	}
	//lct.debug(n + 1);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		int op, x, y;
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d", &x);
			++x;
			lct.op1(x, n);
		} else {
			scanf("%d%d", &x, &y);
			++x;
			lct.op2(x, y, n);
		}
		//lct.debug(n + 1);
	}
	return 0;
}

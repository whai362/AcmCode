#include <iostream>
#include <cstdio>
using namespace std;

#define LS(x) node[(x)].ch[0]
#define RS(x) node[(x)].ch[1]

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int delta, minn, quit;

struct Splay {
	struct Node {
		int fa, ch[2];
		int val, size;
		void init(int _val) {
			val = _val;
			size = 1;
		}
	} node[N];
	int root, tot;
	
	void up(int x){
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

	void splay(int x, int goal) {
		while(node[x].fa != goal) {
			int fx = node[x].fa;
			int ffx = node[fx].fa;
			bool rotate_x = (LS(fx) == x);
			bool rotate_fx = (LS(ffx) == fx);
			if(ffx == goal) rotate(x, rotate_x);
			else {
				if(rotate_x == rotate_fx) rotate(fx, rotate_fx);
				else rotate(x, rotate_x);
				rotate(x, rotate_fx);
			}
		}
		up(x);
		if(goal == 0) root = x;
	}

	void find_pos(int x, int u, int &p) {
		if(u == 0) return ;
		if(x <= node[u].val) {
			if(node[u].val < node[p].val)
				p = u;
			else if(node[u].val == node[p].val)
				p = max(p, u);
			find_pos(x, LS(u), p);
		} else {
			find_pos(x, RS(u), p);
		}
	}

	void insert(int x) {
		if(x < minn) return ;
		x -= delta;
		int u = 2;
		find_pos(x, root, u);
		splay(u, root);
		int tmp = LS(u);
		node[tot].init(x);
		LS(u) = tot;
		node[tot].fa = u;
		LS(tot) = tmp;
		if(tmp) node[tmp].fa = tot;
		up(tot);
		up(u);
		up(root);
		++tot;
	}

	void del() {
		int gz = minn - delta;
		int u = 2;
		find_pos(gz, root, u);
		splay(u, root);
		quit += node[LS(u)].size;
		LS(u) = 0;
		up(u);
		up(root);
	}

	int find_k(int x, int u) {
		if(x <= node[LS(u)].size)
			find_k(x, LS(u));
		else{
			x -= node[LS(u)].size + 1;
			if(x == 0) return u;
			else find_k(x, RS(u));
		}
	}
	
	bool ok(int x) {
		if(x > node[root].size - 2) return false;
		return true;
	}

	void init() {
		node[0].init(-INF); node[0].size = 0;
		node[1].init(-INF);
		node[2].init(INF);
		
		root = 1;
		node[root].fa = 0;
		RS(root) = 2;
		node[2].fa = root;
		up(root);

		node[0].fa = 0;
		LS(0) = root;

		tot = 3;
	}
	void debug() {
		cout<<"root: "<<root<<endl;
		for(int i = 0; i < tot; ++i) {
			cout<<i<<": "<<node[i].val<<' '<<node[i].size<<' '<<node[i].fa<<' '<<node[i].ch[0]<<' '<<node[i].ch[1]<<endl;
		}
	}
} spl;

void init() {
	spl.init();
	delta = 0;
	quit = 0;
}

int main() {
	int n;
	scanf("%d%d", &n, &minn);
	init();
	for(int i = 0; i < n; ++i) {
		char op[5];
		int x;
		scanf("%s%d", op, &x);
		if(op[0] == 'I') {
			spl.insert(x);
		} else if(op[0] == 'A') {
			delta += x;
			spl.del();
		} else if(op[0] == 'S') {
			delta -= x;
			spl.del();
		} else {
			if(spl.ok(x)) {
				x = spl.node[spl.root].size - x;
				int p = spl.find_k(x, spl.root);
				printf("%d\n", spl.node[p].val + delta);
			} else {
				puts("-1");
			}
		}
	}
	printf("%d\n", quit);
	return 0;
}

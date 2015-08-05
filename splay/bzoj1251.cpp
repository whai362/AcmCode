/*bzoj 1251 序列终结者
  题意：
  给定一个长度为N的序列，每个序列的元素是一个整数。要支持以下三种操作：
  1. 将[L,R]这个区间内的所有数加上V;
  2. 将[L,R]这个区间翻转，比如1 2 3 4变成4 3 2 1;
  3. 求[L,R]这个区间中的最大值;
  最开始所有元素都是0。
  限制：
  N <= 50000, M <= 100000
  思路：
  伸展树

  关键点：
  1. 伸展树为左小右大的二叉树，所以旋转操作不会影响树的性质
  2. 区间操作为：
		int u = select(L - 1), v = select(R + 1);
		splay(u, 0); splay(v, u);	//通过旋转操作把询问的区间聚集到根的右子树的左子树下
	 因为伸展树为左小右大的二叉树，旋转操作后的所以对于闭区间[L, R]之间的所有元素都聚集在根的右子树的左子树下
	 因为闭区间[L, R]，
	 1) 所以每次都要查开区间(L - 1, R + 1)，
	 2) 所以伸展树元素1对应的标号为2，
	 3) 所以node[0]对应空节点，node[1]对应比所以元素标号都小的点，node[2 ~ n + 1]对应元素1 ~ n，node[n + 2]对应比所有元素标号都打的点，其中node[0], node[1], node[n + 2]都是虚节点，不代表任何元素。
 */
#include <iostream>
#include <cstdio>
using namespace std;

#define LS(n) node[(n)].ch[0]
#define RS(n) node[(n)].ch[1]

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
struct Splay {
	struct Node{
		int fa, ch[2];
		bool rev;
		int val, add, maxx, size;
		void init(int _val) {
			val = maxx = _val;
			size = 1;
			add = rev = ch[0] = ch[1] = 0;
		}
	} node[N];
	int root;

	void up(int n) {
		node[n].maxx = max(node[n].val, max(node[LS(n)].maxx, node[RS(n)].maxx));
		node[n].size = node[LS(n)].size + node[RS(n)].size + 1;
	}

	void down(int n) {
		if(n == 0) return ;
		if(node[n].add) {
			if(LS(n)) {
				node[LS(n)].val += node[n].add;
				node[LS(n)].maxx += node[n].add;
				node[LS(n)].add += node[n].add;
			}
			if(RS(n)) {
				node[RS(n)].val += node[n].add;
				node[RS(n)].maxx += node[n].add;
				node[RS(n)].add += node[n].add;
			}
			node[n].add = 0;
		}
		if(node[n].rev) {
			if(LS(n)) node[LS(n)].rev ^= 1;
			if(RS(n)) node[RS(n)].rev ^= 1;
			swap(LS(n), RS(n));
			node[n].rev = 0;
		}
	}

	void rotate(int n, bool kind) {
		int fn = node[n].fa;
		int ffn = node[fn].fa;
		node[fn].ch[!kind] = node[n].ch[kind];
		node[node[n].ch[kind]].fa = fn;
		
		node[n].ch[kind] = fn;
		node[fn].fa = n;

		node[ffn].ch[RS(ffn) == fn] = n;
		node[n].fa = ffn;
		up(fn);
	}

	void splay(int n, int goal) {
		while(node[n].fa != goal) {
			int fn = node[n].fa;
			int ffn = node[fn].fa;
			down(ffn); down(fn); down(n);
			bool rotate_n = (LS(fn) == n);
			bool rotate_fn = (LS(ffn) == fn);
			if(ffn == goal) rotate(n, rotate_n);
			else {
				if(rotate_n == rotate_fn) rotate(fn, rotate_fn);
				else rotate(n, rotate_n);
				rotate(n, rotate_fn);
			}
		}
		up(n);
		if(goal == 0) root = n;
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

	int query(int L, int R) {
		int u = select(L - 1), v = select(R + 1);
		splay(u, 0); splay(v, u);	//通过旋转操作把询问的区间聚集到根的右子树的左子树下
		return node[LS(v)].maxx;
	}

	void update(int L, int R, int val) {
		int u = select(L - 1), v = select(R + 1);
		splay(u, 0); splay(v, u);
		node[LS(v)].val += val;
		node[LS(v)].maxx += val;
		node[LS(v)].add += val;
	}

	void reverse(int L, int R) {
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
		node[0].init(-INF); node[0].size = 0;
		node[1].init(-INF);
		node[n + 2].init(-INF);
		for(int i = 2; i <= n + 1; ++i)
			node[i].init(0);
		
		root = build(1, n + 2);
		node[root].fa = 0;

		node[0].fa = 0;
		LS(0) = root;
	}
} splay_tree;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	splay_tree.init(n);
	for(int i = 0; i < m; ++i) {
		int op, l, r, v;
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d%d%d", &l, &r, &v);
			splay_tree.update(l, r, v);
		} else if(op == 2) {
			scanf("%d%d", &l, &r);
			splay_tree.reverse(l, r);
		} else {
			scanf("%d%d", &l, &r);
			printf("%d\n",splay_tree.query(l, r));
		}
	}
	return 0;
}

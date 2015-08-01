#include <iostream>
#include <cstdio>
using namespace std;
#define ls n * 2
#define rs n * 2 + 1
const int N = 2 * 1e5 + 5;
int fa[N];
void init(int n) {
	for(int i = 0; i <= n; ++i) {
		fa[i] = i;
	}
}



struct Seg {
	int l, r;
	int fa;
}seg[3 * N];

void build(int l, int r, int n) {
	seg[n].l = l;
	seg[n].r = r;
	seg[n].fa = 0;
	if(l == r) {
		seg[n].fa = fa[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
}

int get_fa(int);

void down(int n) {
	int fx = get_fa(seg[ls].fa);
	fa[fx] = seg[n].fa;
	seg[ls].fa = seg[n].fa;

	fx = get_fa(seg[rs].fa);
	fa[fx] = seg[n].fa;
	seg[rs].fa = seg[n].fa;
	return ;
}

int query(int x, int n) {
	if(seg[n].l == seg[n].r) {
		return seg[n].fa;
	}
	if(seg[n].fa)
		down(n);
	int mid = (seg[n].l + seg[n].r) >> 1;
	if(x <= mid) return query(x, ls);
	else return query(x, rs);
}

int get_fa(int x) {
	if(x == 1) cout<<"!"<<endl;
	fa[x] = query(x, 1);
	if(x != fa[x]) return fa[x] = get_fa(fa[x]);
	return x;
}

void update(int l, int r, int fx, int n) {
	if(seg[n].l == l && seg[n].r == r) {
		if(seg[n].fa) {
			int fy = get_fa(seg[n].fa);
			fa[fy] = fx;
		}
		cout<<seg[n].l<<' '<<seg[n].r<<' '<<fx<<endl;
		seg[n].fa = fx;
		return ;
	}
	if(seg[n].fa)
		down(n);
	int mid = (seg[n].l + seg[n].r) >> 1;
	if(r <= mid) update(l, r, fx, ls);
	else if(l > mid) update(l, r, fx, rs);
	else {
		update(l, mid, fx, ls);
		update(mid + 1, r, fx, rs);
	}
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	init(n);
	build(1, n, 1);
	for(int i = 0; i < q; ++i) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1) {
			int fx = get_fa(x);
			int fy = get_fa(y);
			if(fx == fy) continue;
			//fa[fy] = fx;
			update(fy, fy, fx, 1);
		} else if(op == 2){
			int fx = get_fa(x);
			update(x, y, fx, 1);
			cout<<"!"<<endl;
		} else {
			int fx = get_fa(x);
			cout<<fx<<endl;
			int fy = get_fa(y);
			//cout<<fx<<' '<<fy<<endl;
			if(fx == fy) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}

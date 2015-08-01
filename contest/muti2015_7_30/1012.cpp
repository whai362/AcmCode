#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
#define ls 2 * n
#define rs 2 * n + 1
int a[N];
int p[N];
int ans[N];

int qu[N];

set<int> index;

struct Seg {
	int l, r;
	int maxx, pos;
}seg[4 * N];

void up(int n) {
	if(seg[ls].maxx > seg[rs].maxx) {
		seg[n].maxx = seg[ls].maxx;
		seg[n].pos = seg[ls].pos;
	} else {
		seg[n].maxx = seg[rs].maxx;
		seg[n].pos = seg[rs].pos;
	}
}

void build(int l, int r, int n) {
	seg[n].l = l;
	seg[n].r = r;
	if(l == r) {
		seg[n].maxx = a[l];
		seg[n].pos = l;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	up(n);
}

Seg query(int l, int r, int n) {
	if(seg[n].l == l && seg[n].r == r) {
		return seg[n];
	}
	int mid = (seg[n].l + seg[n].r) >> 1;
	if(r <= mid) return query(l, r, ls);
	else if(l > mid) return query(l, r, rs);
	else {
		Seg ret, tmp1, tmp2;
		tmp1 = query(l, mid, ls);
		tmp2 = query(mid + 1, r, rs);
		if(tmp1.maxx > tmp2.maxx) {
			ret.maxx = tmp1.maxx;
			ret.pos = tmp1.pos;
		} else {
			ret.maxx = tmp2.maxx;
			ret.pos = tmp2.pos;
		}
		return ret;
	}
}

void update(int pos, int x, int n) {
	if(seg[n].l == seg[n].r) {
		seg[n].maxx = x;
		return ;
	}
	int mid = (seg[n].l + seg[n].r) >> 1;
	if(pos <= mid) update(pos, x, ls);
	else update(pos, x, rs);
	up(n);
}

int get_l(int x) {
	set<int> :: iterator it = index.lower_bound(x);
	if(it == index.begin()) return 0;
	--it;
	return (*it) + 1;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(ans, 0, sizeof(ans));
		memset(qu, 0, sizeof(qu));
		index.clear();
		int n;
		int cnt = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			p[a[i]] = i;
		}
		build(0, n - 1, 1);
		for(int i = 1; i <= n; ++i) {
			if(ans[i]) continue;
			int r = min(p[i] + 1, n - 1);
			//if(qu[r]) --r;
			//int l = p[i];
			//while(l >= 0 && (qu[l] == 0 || qu[l] == 1)) --l;
			int l = get_l(p[i]);

			//if(l < 0) ++l;
			//else if(qu[l] == 2) ++l;
			Seg tmp = query(l, r, 1);
			int pos = tmp.pos;
			//cout<<i<<' '<<l<<' '<<r<<' '<<pos<<endl;
			if(pos <= p[i]) {
				ans[i] = a[pos];
				update(pos, -INF, 1);
				for(int j = pos; j < p[i]; ++j) {
					if(ans[a[j]]) continue;
					ans[a[j]] = a[j + 1];
					update(j + 1, -INF, 1);
					++cnt;
				}
				qu[pos] = 2;
				qu[p[i]] = 2;
				index.insert(p[i]);
			} else {
				ans[i] = a[pos];
				update(pos, -INF, 1);
				qu[p[i]] = 1;
				++cnt;
			}
		}
		printf("%d", ans[1]);
		for(int i = 2; i <= n; ++i) {
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}

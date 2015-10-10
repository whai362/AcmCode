/*poj 3289
  题意：
  给出n个点的坐标，求这n个点的曼哈顿距离最小生成树的第k小边
  限制：
  n <= 10000; k <= n
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

struct Pt {
	int x, y, id;
}p[N];

bool cmp1(Pt a, Pt b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

struct BIT {
	int minn, p;
	void init() {
		minn = INF;
		p = -1;
	}
}bit[N];

int lowbit(int x) { return x & -x; }

void update(int x, int v, int p) {
	while(x > 0) {
		if(v < bit[x].minn)
			bit[x].minn = v, bit[x].p = p;
		x -= lowbit(x);
	}
}

int query(int x, int limit) {
	int minn = INF, p = -1;
	while(x <= limit) {
		if(bit[x].minn < minn)
			minn = bit[x].minn, p = bit[x].p;
		x += lowbit(x);
	}
	return p;
}

struct E {
	int u, v, d;
}e[N * 2];
int e_tot;
void add_edge(int u, int v, int d) {
	e[e_tot++] = (E){u, v, d};
}

bool cmp2(E a, E b) {
	return a.d < b.d;
}

int fa[N];
int get_fa(int x) {
	if(x != fa[x]) return fa[x] = get_fa(fa[x]);
	return x;
}

int _abs(int x) {
	if(x < 0) return -x;
	return x;
}

int dis(Pt a, Pt b) {
	return _abs(a.x - b.x) + _abs(a.y - b.y);
}

int mmst(int n, int k) {
	int a[N], b[N];
	for(int dir = 0; dir < 4; ++dir) {
		if(dir == 1 || dir == 3) {
			for(int i = 0; i < n; ++i)
				swap(p[i].x, p[i].y);
		} else if(dir == 2) {
			for(int i = 0; i < n; ++i)
				p[i].x = -p[i].x;
		}
		sort(p, p + n, cmp1);
		for(int i = 0; i < n; ++i)
			a[i] = b[i] = p[i].y - p[i].x;
		sort(b, b + n);
		int m = unique(b, b + n) - b;
		for(int i = 1; i <= m; ++i)
			bit[i].init();
		for(int i = n - 1; i >= 0; --i) {
			int pos = lower_bound(b, b + m, a[i]) - b + 1;
			int ans = query(pos, m);
			if(ans != -1)
				add_edge(p[i].id, p[ans].id, dis(p[i], p[ans]));
			update(pos, p[i].x + p[i].y, i);
		}
	}
	sort(e, e + e_tot, cmp2);
	int cnt = n - k;
	for(int i = 0; i < n; ++i)
		fa[i] = i;
	for(int i = 0; i < e_tot; ++i) {
		int u = e[i].u, v = e[i].v;
		int fu = get_fa(u), fv = get_fa(v);
		if(fu != fv) {
			--cnt;
			fa[fv] = fu;
			if(cnt == 0)
				return e[i].d;
		}
	}
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].id = i;
	}
	printf("%d\n", mmst(n, k));
	return 0;
}


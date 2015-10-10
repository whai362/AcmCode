/*bzoj 3289
  题意：
  给出n个数，q个询问，每个询问是求区间[l, r]的逆序对的数目。
  限制：
  n, q <= 50000
  思路：
  莫队算法 + 树状数组
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

const int N = 5 * 1e5 + 5;

struct Q {
	int l, r, id;
}q[N];

int unit;
int unit_id(Q a) { return (a.l - 1) / unit + 1; }
bool cmp(Q a, Q b) {
	if(unit_id(a) == unit_id(b)) return a.r < b.r;
	return unit_id(a) < unit_id(b);
}

P a[N];

LL ans[N];
LL cur = 0;

int BIT[N];
int lowbit(int x) { return x & -x; }
LL sum(int x) {
	LL ret = 0;
	while (x > 0) {
		ret += BIT[x];
		x -= lowbit(x);
	}
	return ret;
}

void update(int x, int v) {
	while (x < N) {
		BIT[x] += v;
		x += lowbit(x);
	}
}

void add(int x, int flag) {
	int tmp;
	if(flag) tmp = sum(N - 10) - sum(x);
	else tmp = sum(x - 1);
	cur += tmp;
	//cout<<"add"<<' '<<flag<<' '<<x<<' '<<tmp<<endl;
	update(x, 1);
}

void del(int x, int flag) {
	int tmp;
	if(flag) tmp = sum(N - 10) - sum(x);
	else tmp = sum(x - 1);
	cur -= tmp;
	//cout<<"del"<<' '<<flag<<' '<<x<<' '<<tmp<<endl;
	update(x, -1);
}

bool cmp1(P a, P b) {
	return a.Y < b.Y;
}

void gao(int n, int m) {

	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++i) {
		a[i].X = i;
	}
	sort(a + 1, a + 1 + n, cmp1);

	unit = sqrt(n);
	sort(q, q + m, cmp);

	int L = 1, R = 0;
	for(int i = 0; i < m; ++i) {
		while(R < q[i].r) {
			++R;
			add(a[R].X, 1);
		}
		while(R > q[i].r) {
			del(a[R].X, 1);
			--R;
		}
		while(L < q[i].l) {
			del(a[L].X, 0);
			++L;
		}
		while(L > q[i].l) {
			--L;
			add(a[L].X, 0);
		}
		//cout<<q[i].l<<' '<<q[i].r<<' '<<cur<<endl;
		ans[q[i].id] = cur;
	}
	for(int i = 0; i < m; ++i) {
		printf("%lld\n", ans[i]);
	}
}

int main() {
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].X);
		a[i].Y = i;
	}

	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	gao(n, m);
	return 0;
}


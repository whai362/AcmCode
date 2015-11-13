/*======================================================
# Author: whai
# Last modified: 2015-10-25 15:53
# Filename: tmp.cpp
======================================================*/
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
/*======================================================
# Author: whai
# Last modified: 2015-10-25 10:10
# Filename: g.cpp
======================================================*/
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
#define MP make_pair

const int N = 1e6 + 5;

struct node {
	int l, r, cnt;
	LL sum;
} nd[20 * N];
int tot;
int a[N], root[N];

void build(int l, int r, int &rt) {
	rt = ++tot;
	nd[rt].sum = nd[rt].cnt = 0;
	if (l == r) return ;
	int mid = (l + r) >> 1;
	build(l, mid, nd[rt].l);
	build(mid + 1, r, nd[rt].r);
}

void update(int pre, int &rt, int l, int r, int val) {
	rt = ++tot;
	nd[rt] = nd[pre];
	++nd[rt].cnt;
	nd[rt].sum += val;
	if (l == r) return ;
	int mid = (l + r) >> 1;
	if (val <= mid) update(nd[pre].l, nd[rt].l, l, mid, val);
	else update(nd[pre].r, nd[rt].r, mid + 1, r, val);
}

pair<LL, int> query(int r1, int r2, int l, int r, int val) {
	LL lsum = nd[nd[r2].l].sum - nd[nd[r1].l].sum;
	int lcnt = nd[nd[r2].l].cnt - nd[nd[r1].l].cnt;
	//cout<<lsum<<' '<<lcnt<<endl;
	if (l == r)
		return MP(lsum, lcnt);
	int mid = (l + r) >> 1;
	if (val <= mid)
		return query(nd[r1].l, nd[r2].l, l, mid, val);
	else {
		pair<LL, int> tmp = query(nd[r1].r, nd[r2].r, mid + 1, r, val);
		tmp.X += lsum;
		tmp.Y += lcnt;
		return tmp;
	}
}

LL sum[N];

bool ok(int x, int d, int r) {
	pair<LL, int> low = query(root[0], root[x], 1, N, d);
	//cout<<x<<' '<<d<<' '<<r<<' '<<low.X<<' '<<low.Y<<endl;
	if(sum[x] - low.X - (x - low.Y) * d >= r) return true;
	return false;
}

int gao(int d, int r, int m) {
	int L = 1, R = m + 1;
	while(L < R) {
		int mid = (L + R) >> 1;
		if(ok(mid, d, r)) R = mid;
		else L = mid + 1;
	}
	if(R == m + 1) return 0;
	return R;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	build(1, N, root[0]);
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		update(root[i - 1], root[i], 1, N, a[i]);
	}
	for(int i = 0; i < n; ++i) {
		int d, r;
		scanf("%d%d", &d, &r);
		cout<<gao(d, r, m)<<' ';
	}
	cout<<endl;

	return 0;
}

const int N = 105;
const int K = 15;

int p[10][105];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m, b, k, r, t;
		cin>>n>>m>>b>>k>>r>>t;
		for(int i = 0; i < k; ++i) {
			for(int j = 0; j < n; ++j) {
				cin>>p[i][j];
			}
		}

	}
	return 0;
}


#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define P pair<int ,int>
#define PB push_back
#define X first
#define Y second
#define LL __int64

const int N = 1e5 + 5;

vector<P> pool;
int pool_cnt;

int u[N], v[N];

int id[N * 4];
int num[N * 4];

int BIT[N * 4];
int lowbit(int x) { return x & -x; }
int sum(int x) {
	int s = 0;
	while (x > 0) {
		s += BIT[x];
		x -= lowbit(x);
	}
	return s;
}
void update(int x, int c) {
	while (x <= pool_cnt) {
		BIT[x] += c;
		x += lowbit(x);
	}
}

int get_p(int x) {
	return lower_bound(pool.begin(), pool.begin() + pool_cnt, P(x, 0)) - pool.begin() + 1;
}

int main() {
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i) {
		cin>>u[i]>>v[i];
		pool.PB(P(u[i], 1));
		pool.PB(P(v[i], 1));
	}
	sort(pool.begin(), pool.end());
	pool_cnt = unique(pool.begin(), pool.end()) - pool.begin();
	for(int i = 0; i < pool_cnt - 1; ++i) {
		int x = pool[i].X + 1;
		if(x == pool[i + 1].X) continue;
		int y = pool[i + 1].X - x;
		pool.PB(P(x, y));
	}
	sort(pool.begin(), pool.end());
	pool_cnt = unique(pool.begin(), pool.end()) - pool.begin();
	for(int i = 0; i < pool_cnt; ++i) {
		id[i + 1] = i + 1;
		num[i + 1] = pool[i].Y;
	}
	for(int i = 0; i < n; ++i) {
		u[i] = get_p(u[i]);
		v[i] = get_p(v[i]);
		swap(id[u[i]], id[v[i]]);
	}
	LL ans = 0;
	for(int i = pool_cnt; i > 0; --i) {
		LL tmp = sum(id[i]);
		ans += tmp * num[id[i]];
		update(id[i], num[id[i]]);
	}
	cout<<ans<<endl;
	return 0;
}

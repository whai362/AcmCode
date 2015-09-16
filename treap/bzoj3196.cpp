#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define PB push_back

const int N = 1005;
const int INF = 0x3f3f3f3f;

int SZ;
int B_cnt;
vector<int> B[N];
int a[N * N];

int query_rank(int L, int R, int x) {
	int ret = 0;
	--L, --R;
	int LB = L / SZ + 1;
	int RB = R / SZ;
	if(LB < RB) {
		for(int i = L; i < LB * SZ; ++i) {
			if(a[i] < x) ++ret;
		}
		for(int i = RB * SZ; i <= R; ++i) {
			if(a[i] < x) ++ret;
		}
		for(int i = LB; i < RB; ++i) {
			ret += lower_bound(B[i].begin(), B[i].end(), x) - B[i].begin();
		}
	} else {
		for(int i = L; i <= R; ++i) {
			if(a[i] < x) ++ret;
		}
	}
	return ret + 1;
}

bool ok(int x, int L, int R, int rank) {
	return query_rank(L, R, x + 1) - 1 >= rank;
}

void query_x(int L, int R, int rank) {
	int l = 0, r = 1e8 + 5;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(ok(mid, L, R, rank)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);
}

void update(int p, int x) {
	--p;
	int tmp = a[p];
	a[p] = x;
	int bl = p / SZ;
	int pos = lower_bound(B[bl].begin(), B[bl].end(), tmp) - B[bl].begin();
	B[bl][pos] = x;
	sort(B[bl].begin(), B[bl].end());
}

int query_pre(int L, int R, int x) {
	int ret = 0;
	--L, --R;
	int LB = L / SZ + 1;
	int RB = R / SZ;
	if(LB < RB) {
		for(int i = L; i < LB * SZ; ++i) {
			if(a[i] < x) ret = max(ret, a[i]);
		}
		for(int i = RB * SZ; i <= R; ++i) {
			if(a[i] < x) ret = max(ret, a[i]);
		}
		for(int i = LB; i < RB; ++i) {
			int pos = lower_bound(B[i].begin(), B[i].end(), x) - B[i].begin() - 1;
			if(pos >= 0) ret = max(ret, B[i][pos]);
		}
	} else {
		for(int i = L; i <= R; ++i) {
			if(a[i] < x) ret = max(ret, a[i]);
		}
	}
	return ret;	
}

int query_nxt(int L, int R, int x) {
	int ret = INF;
	--L, --R;
	int LB = L / SZ + 1;
	int RB = R / SZ;
	if(LB < RB) {
		for(int i = L; i < LB * SZ; ++i) {
			if(a[i] > x) ret = min(ret, a[i]);
		}
		for(int i = RB * SZ; i <= R; ++i) {
			if(a[i] > x) ret = min(ret, a[i]);
		}
		for(int i = LB; i < RB; ++i) {
			int pos = upper_bound(B[i].begin(), B[i].end(), x) - B[i].begin();
			if(pos < B[i].size()) ret = min(ret, B[i][pos]);
		}
	} else {
		for(int i = L; i <= R; ++i) {
			if(a[i] > x) ret = min(ret, a[i]);
		}
	}
	return ret;	
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	SZ = sqrt(n) + 1;
	B_cnt = n / SZ;
	for(int i = 0 ; i < n; ++i) {
		int x;
		scanf("%d", &a[i]);
		int bl = i / SZ;
		B[bl].PB(a[i]);
	}
	for(int i = 0; i <= B_cnt; ++i) {
		sort(B[i].begin(), B[i].end());
	}
	for(int i = 0; i < m; ++i) {
		int op, a, b, c;
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d%d%d", &a, &b, &c);
			printf("%d\n", query_rank(a, b, c));
		} else if(op == 2) {
			scanf("%d%d%d", &a, &b, &c);
			query_x(a, b, c);
		} else if(op == 3) {
			scanf("%d%d", &a, &b);
			update(a, b);
		} else if(op == 4) {
			scanf("%d%d%d", &a, &b, &c);
			printf("%d\n", query_pre(a, b, c));
		} else if(op == 5) {
			scanf("%d%d%d", &a, &b, &c);
			printf("%d\n", query_nxt(a, b, c));
		}
	}
	return 0;
}

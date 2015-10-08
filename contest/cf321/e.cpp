#include <iostream>
#include <cstdio>
using namespace std;

#define LL unsigned long long

#define LS n * 2
#define RS n * 2 + 1

const int N = 1e5 + 5;
const int B = 233;
const LL MOD = 1234567899;

LL B_pow[N];
LL h_val[10][N];

char str[N];

struct Seg {
	int l, r, flag;
	LL val;
}seg[N * 4];

void up(int n) {
	int r_len = seg[RS].r - seg[RS].l + 1;
	LL mul = B_pow[r_len];
	seg[n].val = (seg[LS].val * mul % MOD + seg[RS].val) % MOD;
}

void build(int l, int r, int n) {
	seg[n].l = l; seg[n].r = r; seg[n].flag = -1;
	if(l == r) {
		seg[n].val = str[l] - '0';
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, LS);
	build(mid + 1, r, RS);
	up(n);
}

void down(int n) {
	if(seg[n].flag != -1) {
		int d = seg[n].flag;
		seg[n].flag = -1;
		seg[LS].flag = seg[RS].flag = d;
		int len = seg[LS].r - seg[LS].l + 1;
		seg[LS].val = h_val[d][len];
		len = seg[RS].r - seg[RS].l + 1;
		seg[RS].val = h_val[d][len];
	}
}

void update(int l, int r, int d, int n) {
	if(seg[n].l == l && seg[n].r == r) {
		int len = r - l + 1;
		seg[n].val = h_val[d][len];
		seg[n].flag = d;
		return ;
	}
	down(n);
	int mid = (seg[n].l + seg[n].r) >> 1;
	if(r <= mid) update(l, r, d, LS);
	else if(l > mid) update(l, r, d, RS);
	else {
		update(l, mid, d, LS);
		update(mid + 1, r, d, RS);
	}
	up(n);
}

LL query(int l, int r, int n) {
	if(seg[n].l == l && seg[n].r == r) {
		return seg[n].val;
	}
	down(n);
	int mid = (seg[n].l + seg[n].r) >> 1;
	if(r <= mid) return query(l, r, LS);
	else if(l > mid) return query(l, r, RS);
	else {
		int r_len = r - mid;
		LL mul = B_pow[r_len];
		return (query(l, mid, LS) * mul % MOD + query(mid + 1, r, RS)) % MOD;
	}
}

void predo() {
	B_pow[0] = 1;
	for(int i = 1; i < N; ++i) {
		B_pow[i] = B_pow[i - 1] * B % MOD;
	}
	for(int i = 0; i < 10; ++i) {
		h_val[i][0] = 0;
	}
	for(int i = 0; i < 10; ++i) {
		for(int j = 1; j < N; ++j) {
			h_val[i][j] = (h_val[i][j - 1] * B % MOD + i) % MOD;
		}
	}
}

void print(int n) {
	for(int i = 1; i <= n; ++i) {
		cout<<query(i, i, 1)<<' ';
	}
	cout<<endl;
}

int main() {
	predo();

	int n, m, k;
	cin>>n>>m>>k;
	cin>>str + 1;
	build(1, n, 1);

	for(int i = 0; i < m + k; ++i) {
		int op, l, r, d;
		cin>>op>>l>>r>>d;
		if(op == 1) {
			update(l, r, d, 1);
			//print(n);
		} else {
			if(r - l + 1 == d) {
				puts("YES");
				continue;
			}
			LL x = query(l, r - d, 1);
			LL y = query(l + d, r, 1);
			//cout<<x<<' '<<y<<endl;
			if(x == y) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}

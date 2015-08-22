#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 210040
#define lowbit(x) x&-x
#define LL long long

using namespace std;

int h[N], ls[N << 5], rs[N << 5], sum[N << 5];
int cnt, n, m, gs, num;
int a[N], bh[N];
int dat[N][4], ln[N], rn[N], lc, rc;

int newnode(int s, int l, int r) {
	++cnt;
	sum[cnt] = s;
	ls[cnt] = l;
	rs[cnt] = r;
	return cnt;
}

void build(int l, int r, int &rt) {
	rt = newnode(0, 0, 0);
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	build(l, mid, ls[rt]);
	build(mid + 1, r, rs[rt]);
}

void updata(int last, int pos, int val, int l, int r, int &rt) {
	rt = newnode(sum[last] + val, ls[last], rs[last]);
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	if (pos <= mid)
		updata(ls[last], pos, val, l, mid, ls[rt]);
	else
		updata(rs[last], pos, val, mid + 1, r, rs[rt]);
}

void modify(int x, int pos, int val) {
	int tmp;
	while (x <= n) {
		updata(h[x], pos, val, 1, num, tmp);
		h[x] = tmp;
		x += lowbit(x);
	}
}

int query(int l, int r, int k) {
	if (l == r)
		return l;
	int tr = 0, tl = 0;
	for (int i = 1; i <= rc; i++)
		tr += sum[ls[rn[i]]];
	for (int i = 1; i <= lc; i++)
		tl += sum[ls[ln[i]]];
	tr -= tl;
	int mid = (l + r) >> 1;
	if (k <= tr) {
		for (int i = 1; i <= rc; i++)
			rn[i] = ls[rn[i]];
		for (int i = 1; i <= lc; i++)
			ln[i] = ls[ln[i]];
		return query(l, mid, k);
	} else {
		for (int i = 1; i <= rc; i++)
			rn[i] = rs[rn[i]];
		for (int i = 1; i <= lc; i++)
			ln[i] = rs[ln[i]];
		return query(mid + 1, r, k - tr);
	}
}

int getans(int l, int r, int k) {
	rc = lc = 0;
	while (r) {
		rn[++rc] = h[r];
		r -= lowbit(r);
	}
	while (l) {
		ln[++lc] = h[l];
		l -= lowbit(l);
	}
	return query(1, num, k);
}

void In(int &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

void In(LL &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

void Out(int x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

void Out(LL x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}



void gao() {
	sort(bh + 1, bh + 1 + gs);
	num = unique(bh + 1, bh + 1 + gs) - bh - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(bh + 1, bh + 1 + num, a[i]) - bh;
	build(1, num, h[0]);
	for (int i = 1; i <= n; i++)
		modify(i, a[i], 1);
	for (int i = 1; i <= m; i++) {
		if (dat[i][0] == 0) {
			//printf("%d\n", bh[getans(dat[i][1] - 1, dat[i][2], dat[i][3])]);
			Out(bh[getans(dat[i][1] - 1, dat[i][2], dat[i][3])]);
			puts("");
		}
		else {
			int pos = lower_bound(bh + 1, bh + 1 + num, dat[i][2]) - bh;
			modify(dat[i][1], a[dat[i][1]], -1);
			a[dat[i][1]] = pos;
			modify(dat[i][1], a[dat[i][1]], 1);
		}
	}
}

void init() {
	lc = rc = cnt = gs = num = 0;
	memset(h, 0,sizeof(h));
}

int main() {
	//while(scanf("%d", &n) != EOF) {
	int T;
	In(T);
	while(T--) {
		In(n);
		In(m);
		init();
		for (int i = 1; i <= n; i++) {
			//scanf("%d", &a[i]);
			In(a[i]);
			bh[++gs] = a[i];
		}
		//int op;
		//scanf("%d", &m);
		char op[4];
		for (int i = 1; i <= m; i++) {
			//scanf("%d", &op);
			//In(op);
			scanf("%s", op);
			if (op[0] == 'Q') {
				dat[i][0] = 0;
				for (int j = 1; j <= 3; j++)
					In(dat[i][j]);
					//scanf("%d", &dat[i][j]);
			} else {
				dat[i][0] = 1;
				//scanf("%d%d", &dat[i][1], &dat[i][2]);
				In(dat[i][1]);
				In(dat[i][2]);
				bh[++gs] = dat[i][2];
			}
		}
		gao();
	}
	return 0;
}

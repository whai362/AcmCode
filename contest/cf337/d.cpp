#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define N 1000005

#define LL __int64

struct line {
	LL f;
	LL x, y1, y2;
} l[N];
struct node {
	LL l, r, f;
	LL ml, mr, len;
} v[N * 4];
LL y[N];
bool cmp(line a, line b) {
	return a.x < b.x;
}
void build(LL l, LL r, LL i) {
	v[i].l = l;
	v[i].r = r;
	v[i].ml = y[l - 1];	//赋值的时候要注意一下
	v[i].mr = y[r - 1];	//
	v[i].f = 0;
	v[i].len = 0;
	if (v[i].l + 1 == v[i].r) {
		return ;
	}
	LL mid = (l + r) >> 1;
	build(l, mid, i * 2);
	build(mid, r, i * 2 + 1); //建树时注意这里不是mid+1，因为做相减的时候如果mid+1这么建回到值左孩子的右边与有孩子的左边无法进行运算
}
void callen(LL i) {
	if (v[i].f > 0) {
		v[i].len = v[i].mr - v[i].ml;
	}
	else if (v[i].r - v[i].l == 1) {
		v[i].len = 0;
	}
	else {
		v[i].len = v[i * 2].len + v[i * 2 + 1].len;
	}
	return ;
}
void update(LL i, line a) {
	if (v[i].ml == a.y1 && v[i].mr == a.y2) {
		v[i].f += a.f;
		callen(i);
		return ;
	}
	if (a.y2 <= v[i * 2].mr) update(i * 2, a);
	else if (a.y1 >= v[i * 2 + 1].ml) update(i * 2 + 1, a);
	else {
		line tmp = a;
		tmp.y2 = v[i * 2].mr;
		update(i * 2, tmp);
		tmp = a;
		tmp.y1 = v[i * 2 + 1].ml;
		update(i * 2 + 1, tmp);
	}
	callen(i);
	return ;
}
int main() {
	LL cas = 0, cnt, i, n;
	LL x1, x2, y1, y2, sum;
	while (scanf("%I64d", &n) != EOF ) {
		cnt = 0;
		for (i = 0; i < n; ++i) {
			scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
			if(x1 == x2) {
				if(y1 > y2) {
					swap(y1, y2);
				}
				++x2; ++y2;
			}
			if(y1 == y2) {
				if(x1 > x2) {
					swap(x1, x2);
				}
				++y2; ++x2;
			}
			l[cnt].x = x1;
			l[cnt].y1 = y1;
			l[cnt].y2 = y2;
			l[cnt].f = 1;
			y[cnt++] = y1;
			l[cnt].x = x2;
			l[cnt].y1 = y1;
			l[cnt].y2 = y2;
			l[cnt].f = -1;
			y[cnt++] = y2;
		}
		sort(l, l + cnt, cmp);
		sort(y, y + cnt);
		build(1, cnt, 1);
		update(1, l[0]);
		sum = 0;
		for (i = 1; i < cnt; ++i) {
			sum += v[1].len * (l[i].x - l[i - 1].x);
			update(1, l[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}

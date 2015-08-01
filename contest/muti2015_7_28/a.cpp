#include <iostream>
#include <cstdio>
using namespace std;
#define LL __int64
const int N = 1e5 + 5;
const LL INF = 10000000000000000LL;
struct Dt {
	int L, R;
	LL maxx[4];
}seg[3*N];
LL a[3*N];

void up(int n) {
	seg[n].maxx[0] = max(seg[n*2].maxx[0], seg[n*2 + 1].maxx[0]);
	if(seg[n*2].maxx[2] != -INF) {
		seg[n].maxx[0] = max(seg[n].maxx[0], seg[n*2].maxx[2] + seg[n*2 + 1].maxx[0]);
	}
	if(seg[n*2 + 1].maxx[3] != -INF) {
		seg[n].maxx[0] = max(seg[n].maxx[0], seg[n*2].maxx[0] + seg[n*2 + 1].maxx[3]);
	}

	seg[n].maxx[1] = max(seg[n*2].maxx[1], seg[n*2 + 1].maxx[1]);
	if(seg[n*2].maxx[3] != -INF) {
		seg[n].maxx[1] = max(seg[n].maxx[1], seg[n*2].maxx[3] + seg[n*2 + 1].maxx[1]);
	}
	if(seg[n*2 + 1].maxx[2] != -INF) {
		seg[n].maxx[1] = max(seg[n].maxx[1], seg[n*2].maxx[1] + seg[n*2 + 1].maxx[2]);
	}

	seg[n].maxx[2] = max(max(seg[n*2].maxx[2], seg[n*2 + 1].maxx[2]), seg[n*2].maxx[0] + seg[n*2 + 1].maxx[1]);
	if(seg[n*2].maxx[2] != -INF && seg[n*2 + 1].maxx[2] != -INF) {
		seg[n].maxx[2] = max(seg[n].maxx[2], seg[n*2].maxx[2] + seg[n*2 + 1].maxx[2]);
	}
	

	seg[n].maxx[3] = max(max(seg[n*2].maxx[3], seg[n*2 + 1].maxx[3]), seg[n*2].maxx[1] + seg[n*2 + 1].maxx[0]);
	if(seg[n*2].maxx[3] != -INF && seg[n*2 + 1].maxx[3] != -INF) {
		seg[n].maxx[3] = max(seg[n].maxx[3], seg[n*2].maxx[3] + seg[n*2 + 1].maxx[3]);
	}
}

void build(int l, int r, int n){
	seg[n].L = l;
	seg[n].R = r;
	if(l == r){
		for(int i = 0; i < 4; ++i)
			seg[n].maxx[i] = -INF;
		if(l % 2) {
			seg[n].maxx[0] = a[l];
		}
		else {
			seg[n].maxx[1] = a[l];
		}
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, 2 * n);
	build(mid + 1, r, 2 * n + 1);
	up(n);
}
Dt query(int l, int r, int n){
	//cout<<l<<' '<<r<<endl;
	if(seg[n].L == l && seg[n].R == r) {
		return seg[n];
	}
	int mid = (seg[n].L + seg[n].R) >> 1;
	if(r <= mid) return query(l, r, 2*n);
	else if(l > mid) return query(l, r, 2*n + 1);
	else{
		Dt tmp1 = query(l, mid, 2*n);
		Dt tmp2 = query(mid + 1, r, 2*n + 1);
		Dt ret;
		ret.maxx[0] = max(
				max(tmp1.maxx[0], tmp2.maxx[0]), 
				max(tmp1.maxx[0] + tmp2.maxx[3], tmp1.maxx[2] + tmp2.maxx[0])
				);
		ret.maxx[1] = max(
				max(tmp1.maxx[1], tmp2.maxx[1]),
				max(tmp1.maxx[1] + tmp2.maxx[2], tmp1.maxx[3] + tmp2.maxx[1])
				);
		ret.maxx[2] = max(
				max(tmp1.maxx[2], tmp2.maxx[2]),
				max(tmp1.maxx[2] + tmp2.maxx[2], tmp1.maxx[0] + tmp2.maxx[1])
				);
		ret.maxx[3] = max(
				max(tmp1.maxx[3], tmp2.maxx[3]),
				max(tmp1.maxx[3] + tmp2.maxx[3], tmp1.maxx[1] + tmp2.maxx[0])
				);
		return ret;
	}
}

void update(int p, int a, int n){
	if(seg[n].L ==seg[n].R){
		if(seg[n].L % 2) seg[n].maxx[0] = a;
		else seg[n].maxx[1] = a;
		return ;
	}
	int mid = (seg[n].L + seg[n].R) >> 1;
	if(p <= mid) update(p, a, 2*n);
	else update(p, a, 2*n + 1);
	up(n);
}

void debug(int l,int r){
	cout<<"debug"<<endl;
	cout<<l<<' '<<r<<endl;
	Dt tmp = query(l, r, 1);
	for(int i = 0; i < 4; ++i)
		cout<<tmp.maxx[i]<<' ';
	cout<<endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i){
			scanf("%I64d", &a[i]);
		}
		build(0, n-1, 1);
		//debug(0, 1);
		//cout<<"!"<<endl;
		for(int i = 0; i < m; ++i) {
			int op, l, r;
			scanf("%d%d%d", &op, &l, &r);
			if(op == 0){
				//cout<<op<<endl;
				Dt tmp = query(l - 1, r - 1, 1);
				//cout<<"?"<<endl;
				//for(int i = 0; i < 4; ++i)
				//	cout<<tmp.maxx[i]<<' ';
				//cout<<endl;
				LL ans = tmp.maxx[0];
				for(int i = 1; i < 4; ++i)
					ans = max(ans, tmp.maxx[i]);
				printf("%I64d\n", ans);
			}
			else{
				//cout<<op<<endl;
				update(l - 1, r, 1);
			}
		}
	}
	return 0;
}

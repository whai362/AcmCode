#include <iostream>
#include <cstdio>
using namespace std;
const int N = 200005;
int fa[N];
int R[N];
void init(int n) {
	for(int i = 0; i <= n; ++i)
		fa[i] = R[i] = i;
}

int get_fa(int x) {
	if(x != fa[x]) return fa[x] = get_fa(fa[x]);
	return x;
}

int get_r(int x) {
	if(x != R[x]) return R[x] = get_r(R[x]);
	return x;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	init(n);
	for(int i = 0; i < q; ++i) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if(x > y) swap(x, y);
		if(op == 1) {
			int fx = get_fa(x);
			int fy = get_fa(y);
			int rx = get_r(x);
			int ry = get_r(y);
			
			if(rx > y) {
				R[rx] = max(rx, ry);
				R[ry] = max(rx, ry);
			}

			fa[fy] = fx;

		} else if(op == 2) {
			int fx = get_fa(x);
			int rx = get_r(x);
			int j = rx + 1;
			for(; j <= y; ++j) {
				int fj = get_fa(j);
				fa[fj] = fx;
				int rj = get_r(j);
				R[rx] = rj;
				j = rj;
				rx = rj;
			}
		} else {
			int fx = get_fa(x);
			int fy = get_fa(y);
			//cout<<fx<<' '<<fy<<endl;
			if(fx == fy) puts("YES");
			else puts("NO");
		}	
	}
	return 0;
}

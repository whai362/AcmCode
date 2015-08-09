#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 55;
struct Pt {
	int x, y;
}a[N], t[N];

int sqr(int x) {
	return x * x;
}

int dis(Pt a, Pt b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int vis[4][4];

bool ok(int a1, int a2, int a3, int a4) {
	t[0] = a[a1];
	t[1] = a[a2];
	t[2] = a[a3];
	t[3] = a[a4];
	int d[N], cnt = 0;
	for(int i = 0; i < 4; ++i) {
		for(int j = i + 1; j < 4; ++j) {
			d[cnt++] = dis(t[i], t[j]);
		}
	}
	sort(d, d + cnt);
	int bj = d[0];
	for(int i = 0; i < 4; ++i) {
		if(d[i] != bj) return false;
	}
	for(int i = 4; i < 6; ++i) {
		if(d[i] != bj * 2) return false;
	}
	return true;
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		int ans = 0;
		if(n <= 3){
			puts("0");
			continue;
		}
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				for(int k = j + 1; k < n; ++k) {
					for(int l = k + 1; l < n; ++l) {
						if(ok(i, j, k, l)) ++ans;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

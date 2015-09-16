#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n;
	int q;
	scanf("%d%d", &n, &q);
	vector<P> w(n);
	vector<P> h(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &w[i].X);
		w[i].Y = i;
	}
	for(int i = 0; i < n; ++i) {
		scanf("%d", &h[i].X);
		h[i].Y = i;
	}
	sort(w.begin(), w.end());
	sort(h.begin(), h.end());
	vector<LL> c(n), c2(n), c3(n);
	for(int i = 0; i < n; ++i) {
		c[i] = w[i].X * (LL)h[i].X;
		if(i > 0) {
			c2[i] = w[i].X * (LL)h[i - 1].X + w[i - 1].X * h[i].X;
		}
		if(i > 1) {
			c3[i] = max(w[i].X * (LL)h[i - 2].X + w[i - 1].X *
				    (LL)h[i].X + w[i - 2].X * (LL)h[i].X +
				    w[i].X * (LL)h[i - 1].X + w[i - 1].X + (LL)
		}
	}
}

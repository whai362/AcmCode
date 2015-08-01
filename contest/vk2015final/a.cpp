#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int tab[N];
int maxx[21];
int fac_cnt[N];
bool used[N];
int deal(int x) {
	memset(maxx, 0, sizeof(maxx));
	for(int i = 1; i * i <= x; ++i) {
		if(x % i == 0) {
			int tmp = fac_cnt[i];
			maxx[tmp] = max(maxx[tmp], tab[i]);
			tmp = fac_cnt[x / i];
			maxx[tmp] = max(maxx[tmp], tab[x / i]);
			used[i] = used[x / i] = 1;
		}
	}
	int ret = 0;
	for(int i = 1; i <= 21; ++i) {
		cout<<maxx[i]<<' ';
		ret += maxx[i];
	}
	cout<<endl;
	return ret;
}

int get_cnt(int x) {
	int ret = 1;
	for(int i = 2; i * i <= x; ++i) {
		while(x % i == 0){
		   x /= i;
		   ++ret;
		}
	}
	if(x > 1) ++ret;
	return ret;
}

void predo() {
	for(int i = 1; i < N; ++i) {
		fac_cnt[i] = get_cnt(i);
	}
}

bool cmp(int a, int b) {
	return a > b;
}

void gao(int n) {
	sort(a, a+n, cmp);
	for(int i = 0; i < n; ++i)
		++tab[a[i]];
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(used[a[i]]) continue;
		ans = max(ans, deal(a[i]));
	}
	cout<<ans<<endl;
}
int main() {
	predo();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	gao(n);
	return 0;
}

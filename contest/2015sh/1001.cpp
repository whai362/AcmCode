#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#pragma comment(linker,"/STACK:102400000,102400000")
#define PB push_back

const int N = 1e5 + 5;

struct E {
	int v, next;
} p[2 * N];

int head[N], tot;

void addEdge(int u, int v) {
	p[tot].v = v;
	p[tot].next = head[u];
	head[u] = tot ++;
}

vector<int> fac[N];
int a[N];
int ans[N];
int cnt[N];

int mu[N];
//O(nlog(n))
void getMu() {
	for (int i = 1; i < N; ++i) {
		int target = i == 1 ? 1 : 0;
		int delta = target - mu[i];
		mu[i] = delta;
		for (int j = 2 * i; j < N; j += i)
			mu[j] += delta;
	}
}


int cal(int x) {
	int ret = 0;
	//
	for(int i = 0; i < fac[x].size(); ++i) {
		int val = fac[x][i];
		ret += mu[val] * cnt[val];
	}
	return ret;
}

void dfs(int u, int fa, int pre) {
	for(int i = head[u]; i != -1; i = p[i].next) {
		int v = p[i].v;
		if(v == fa) continue;
		dfs(v, u, cal(a[u]));

		ans[u] = cal(val) - pre;
	}
	int val = a[u];
	for(int i = 0; i < fac[val].size(); ++i) {
		++cnt[fac[val][i]];
	}
}

void gao(int n) {
	dfs(1, -1, 0);
	for(int i = 1; i <= n; ++i) {
		printf(" %d", ans[i]);
	}
	printf("\n");
}

void init(int n) {
	memset(cnt, 0, sizeof(cnt));
	memset(head, -1, sizeof(head));
	memset(ans, 0, sizeof(ans));
	tot = 0;
}

void deal(int x) {
	for(int i = 1; i * i <= x; ++i) {
		if(x % i == 0) {
			fac[x].PB(i);
			int tmp = x / i;
			if(tmp != i) fac[x].PB(tmp);
		}
	}
}

void getFac() {
	for(int i = 1; i < N; ++i) {
		deal(i);
	}
}

int main() {
	getMu();
	getFac();
	int n;
	int cas = 0;
	while(scanf("%d", &n) != EOF) {
		init(n);
		for(int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v);
			addEdge(v, u);
		}

		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}

		printf("Case #%d:", ++cas);
		gao(n);
	}
	return 0;
}

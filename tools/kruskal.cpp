struct Edge {
	int u, v, len;
} edge[Maxm];
int fa[Maxn];
int n, m;
bool cmp(Edge a, Edge b) {
	return a.len < b.len;
}
int getFa(int x) {
	if (x != fa[x]) return fa[x] = getFa(fa[x]);
	return fa[x];
}
int Kruskal() {
	int ans = 0, u, v;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		u = getFa(edge[i].u); v = getFa(edge[i].v);
		if (u == v) continue;
		fa[v] = u;
		ans += edge[i].len;
	}
	return ans;
}


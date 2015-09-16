/*树上的分治
  poj 1741
  题意：题意就是求树上距离小于等于K的点对有多少个。
  限制：n<=1e5
  树上的分治
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define pb push_back
const int N = 10005,
          INF = 0x3f3f3f3f;
struct Data {
	int to, w;
	Data() {}
	Data(int _to, int _w) {
		to = _to;
		w = _w;
	}
};
int ans, n, k, cnt, root, size;
bool vis[N];
vector<Data> _map[N];
int sum[N], _max[N], dis[N];

void getRoot(int u, int fa) {
	sum[u] = 1;
	_max[u] = 0;
	for (int i = 0; i < _map[u].size(); ++i) {
		int to = _map[u][i].to,
		    w = _map[u][i].w;
		if (to != fa && !vis[to]) {
			getRoot(to, u);
			sum[u] += sum[to];
			_max[u] = max(_max[u], sum[to]);
		}
	}
	_max[u] = max(_max[u], size - sum[u]);
	if (_max[u] < _max[root])
		root = u;
}

void dfsDis(int u, int d, int fa) {
	dis[cnt++] = d;
	for (int i = 0; i < _map[u].size(); ++i) {
		int to = _map[u][i].to,
		    w = _map[u][i].w;
		if (to != fa && !vis[to]) dfsDis(to, d + w, u);
	}
}

int cal(int u, int d) {
	int ret = 0;
	cnt = 0;
	dfsDis(u, d, 0);
	sort(dis, dis + cnt);
	int i = 0, j = cnt - 1;
	while (i < j) {
		while (dis[i] + dis[j] > k && i < j) j--;
		ret += j - i;
		++i;
	}
	return ret;
}

void deal(int u) {
	ans += cal(u, 0);
	vis[u] = true;
	for (int i = 0; i < _map[u].size(); ++i) {
		int to = _map[u][i].to,
		    w = _map[u][i].w;
		if (!vis[to]) {
			ans -= cal(to, w);
			_max[0] = size = sum[to];
			getRoot(to, root = 0);
			deal(root);
		}
	}
}

void init() {
	for (int i = 0; i <= n; ++i) {
		_map[i].clear();
	}
	memset(vis, 0, sizeof(vis));
}

//输入输出外挂
void In(int &x) {
	char ch;
	while (ch = getchar(), ch < '0' || ch > '9');
	x = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - '0';
}

void Out(int x) {
	if (x > 9)
		Out(x / 10);
	putchar(x % 10 + '0');
}

void gao() {
	_max[0] = size = n;
	getRoot(1, root = 0);
	ans = 0;
	deal(root);
	printf("%d\n", ans);
	//Out(ans);
	//puts("");
}

int main() {
	while (scanf("%d%d", &n, &k) && (n || k)) {
		init();
		int u, v, w;
		for (int i = 0; i < n - 1; ++i) {
			In(u), In(v), In(w);
			//scanf("%d%d%d",&u,&v,&w);
			_map[u].pb(Data(v, w));
			_map[v].pb(Data(u, w));
		}
		//cout<<getZx(1)<<endl;
		gao();
	}
	return 0;
}


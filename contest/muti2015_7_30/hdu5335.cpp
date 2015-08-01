#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
const int N = 1005;

struct E {
	int v, c;
};

char mp[N][N];
bool rch[N][N];

//int level[N*N];
vector<E> G[N*N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int get_id(int x, int y, int n, int m) {
	return x * m + y;
}

int level0;

int get_level(int x, int y, int n, int m) {
	if(x == 0 && y == 0) return level0;
	return n - 1 - x + m - 1 - y;
}

bool in(int x, int y, int n, int m) {
	if(x >= 0 && x < n && y >= 0 && y < m) return true;
	return false;
}

void bfs(P u, int n, int m) {
	queue<P> que;
	que.push(u);
	rch[u.X][u.Y] = 1;
	while(!que.empty()) {
		P now = que.front(); que.pop();
		for(int i = 0; i < 4; ++i) {
			int tmpx = now.X + dx[i];
			int tmpy = now.Y + dy[i];
			if(in(tmpx, tmpy, n, m) && rch[tmpx][tmpy] == 0) {
				rch[tmpx][tmpy] = 1;
				if(mp[tmpx][tmpy] == '0')
					que.push(P(tmpx, tmpy));
			}
		}
	}
}

int path[3*N];
char minn[N*N];

void dij(int n, int m) {
	memset(path, 0x3f, sizeof(path));
	fill(minn, minn + n*m + 5, 3);
	queue<E> que;
	que.push((E){0, mp[0][0]});
	while(!que.empty()) {
		E now = que.front(); que.pop();
		int now_level = get_level(now.v / m, now.v % m, n, m) ;
		if(now.c > path[now_level])
			continue;
		for(int i = 0; i < G[now.v].size(); ++i) {
			E ch = G[now.v][i];
			if(get_level(ch.v / m, ch.v % m, n, m) == now_level - 1 && ch.c <= path[now_level - 1]) {
				path[now_level - 1] = ch.c;
				if(ch.c < minn[ch.v]) {
					minn[ch.v] = ch.c;
					que.push(ch);
				}
			}
		}
	}
}

void gao(int n,int m) {
	if(mp[0][0] == '0') {
		bfs(P(0, 0), n, m);
		if(rch[n - 1][m - 1]) {
			putchar(mp[n - 1][m - 1]);
			puts("");
			return ;
		}
	}
	level0 = n - 1 + m -1;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(rch[i][j]) {
				int u = 0;
				int v = get_id(i, j, n, m);
				G[u].PB((E){v, 0});
				level0 = min(level0, get_level(i, j, n, m) + 1);
			}
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			if(rch[i][j] && mp[i][j] == '0') continue;
			if(get_id(i, j, n, m) !=0 && get_level(i, j, n, m) >= level0) continue;
			for(int k = 0; k < 2; ++k) {
				int tmpx = i + dx[k];
				int tmpy = j + dy[k];
				if(in(tmpx, tmpy, n, m)) {
					int u = get_id(i, j, n, m);
					int v = get_id(tmpx, tmpy, n, m);
					G[u].PB((E){v, mp[i][j] - '0'});
				}
			}
		}
	dij(n, m);
	//cout<<"rch"<<endl;
	//for(int i = 0; i < n; ++i) {
	//	for(int j = 0; j < m; ++j) {
	//		cout<<rch[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}

	//cout<<"level"<<endl;
	//for(int i = 0; i < n; ++i) {
	//	for(int j = 0; j < m; ++j) {
	//		cout<<get_level(i, j, n, m)<<' ';
	//	}
	//	cout<<endl;
	//}
	int d = level0 - 1;
	//cout<<d<<endl;
	while(d >=0 && path[d] == 0) --d;
	for(d; d >= 0; --d) {
		printf("%d",path[d]);
	}
	putchar(mp[n - 1][m - 1]);
	puts("");
}

void init(int n, int m) {
	for(int i = 0; i <= n*m; ++i)
		G[i].clear();
	memset(rch, 0, sizeof(rch));
}

int main() {
	int T;
	int n, m;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		init(n, m);
		for(int i = 0; i < n; ++i)
			scanf("%s", mp[i]);
		gao(n, m);
	}
	return 0;
}

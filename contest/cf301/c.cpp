#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define P pair<int, int>
#define X first
#define Y second

const int N = 505;
char G[N][N];
bool used[N][N];

bool in(int x, int y, int n, int m) {
	if(x >= 0 && x < n && y >= 0 && y < m) return true;
	return false;
}
bool ok(int x, int y, int n, int m) {
	if(in(x, y, n, m) && G[x][y] == '.' && !used[x][y]) return true;
	return false;
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int count_adj(P a, int n, int m) {
	int ret = 0;
	for(int i = 0; i < 4; ++i) {
		int tmpx = a.X + dx[i];
		int tmpy = a.Y + dy[i];
		if(in(tmpx, tmpy, n, m) && G[tmpx][tmpy] == '.') ++ret;
	}
	return ret;
}

bool is_adj(P S, P T) {
	for(int i = 0; i < 4; ++i) {
		int tmpx = S.X + dx[i];
		int tmpy = S.Y + dy[i];
		if(tmpx == T.X && tmpy == T.Y) return true;
	}

	return false;
}

void gao(int n, int m, P S, P T) {
	int cnt = count_adj(T, n, m);
	int con = 0;
	queue<P> q;
	q.push(S);
	used[S.X][S.Y] = 1;
	while(!q.empty()) {
		P now = q.front(); q.pop();
		for(int i = 0; i < 4; ++i) {
			int tmpx = now.X + dx[i];
			int tmpy = now.Y + dy[i];
			if(tmpx == T.X && tmpy == T.Y) {
				con = 1;
				break;
			}
			if(ok(tmpx, tmpy, n, m)) {
				q.push(P(tmpx, tmpy));
				used[tmpx][tmpy] = 1;
			}
		}
	}
	//cout<<cnt<<' '<<con<<endl;

	if(G[T.X][T.Y] == 'X') {
		if(S.X == T.X && S.Y == T.Y) {
			if(cnt > 0) puts("YES");
			else puts("NO");
		} else {
			if(con == 1) puts("YES");
			else puts("NO");
		}
	} else {
		if(!is_adj(S, T)) --cnt;
		if(cnt > 0 && con == 1) puts("YES");
		else puts("NO");
	}
}

int main() {
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < n; ++i) {
		cin>>G[i];
	}
	P a, b;
	cin>>a.X>>a.Y;
	--a.X; --a.Y;
	cin>>b.X>>b.Y;
	--b.X; --b.Y;
	gao(n, m, a, b);
	return  0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Dt{
	int x, y, dir, ok, s;
};
int G[21][21];
int vis[21][21][4][2];

queue<Dt> que;

bool ok(Dt tmp, int n, int m){
	if(tmp.x >= 0 && tmp.x <= m && tmp.y >=0 && tmp.y <= n && (G[tmp.y][tmp.x] == 0 || G[tmp.y][tmp.x] == 3) && vis[tmp.y][tmp.x][tmp.dir][tmp.ok] < tmp.s) return true;
	return false;
}

void forword(Dt now, Dt &tmp){
	tmp = now;
	tmp.s -= 10;
	if(tmp.dir == 0){
		++tmp.y;
	} else if(tmp.dir == 1){
		++tmp.x;
	} else if(tmp.dir == 2){
		--tmp.y;
	} else if(tmp.dir == 3){
		--tmp.x;
	}
}

void turn_l(Dt now, Dt &tmp){
	tmp = now;
	tmp.s -= 10;
	tmp.dir = (tmp.dir - 1 + 4) % 4;
}

void turn_r(Dt now, Dt &tmp){
	tmp = now;
	tmp.s -= 10;
	tmp.dir = (tmp.dir + 1) % 4;
}

void get_gold(Dt now, Dt &tmp){
	tmp = now;
	//tmp.s += 1000;
	tmp.s -= 10;
	tmp.ok = 1;
}

void out(Dt now, Dt &tmp){
	tmp = now;
	tmp.s -= 10;
}

void gao(int n, int m) {
	if(G[0][0] == 1 || G[0][0] == 2) {
		puts("-1");
		return ;
	}
	if(G[0][0] == 3) {
		puts("980");
		return ;
	}
	int ans = -INF;
	que.push((Dt){0,0,1,0,0});
	while(!que.empty()){
		Dt now = que.front(); que.pop();
		Dt tmp;
		forword(now, tmp);
		if(ok(tmp, n, m)) {
			que.push(tmp);
			vis[tmp.y][tmp.x][tmp.dir][tmp.ok] = tmp.s;
		}
		turn_l(now, tmp);
		if(ok(tmp, n, m)){
			que.push(tmp);
			vis[tmp.y][tmp.x][tmp.dir][tmp.ok] = tmp.s;
		}
		turn_r(now, tmp);
		if(ok(tmp, n, m)){
			que.push(tmp);
			vis[tmp.y][tmp.x][tmp.dir][tmp.ok] = tmp.s;
		}
		if(G[now.y][now.x] == 3){
			get_gold(now, tmp);
			if(ok(tmp, n, m)){
				que.push(tmp);
				vis[tmp.y][tmp.x][tmp.dir][tmp.ok] = tmp.s;
			}
		}
		
		if(now.x == 0 && now.y == 0 && now.ok == 1){
			out(now, tmp);
			ans = max(ans, tmp.s);
			//if(ok(tmp, n, m)){
			//	vis[tmp.y][tmp.x][tmp.dir][tmp.ok] = tmp.s;
			//}
		}
	}
	if(ans == -INF) puts("-1");
	else printf("%d\n", 1000 + ans);
}

void init() {
	memset(G, 0, sizeof(G));
	for(int i = 0; i < 21; ++i)
		for(int j = 0; j < 21; ++j)
			for(int k = 0; k < 4; ++k)
				vis[i][j][k][0] = vis[i][j][k][1] = -INF;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		init();
		int type, x, y;
		while(scanf("%d%d%d", &type, &x, &y) && type != -1)
			G[y][x] = type;
		gao(n, n);
	}
	return 0;
}

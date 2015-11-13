/*======================================================
# Author: whai
# Last modified: 2015-11-07 21:17
# Filename: d.cpp
======================================================*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int INF = 0x3f3f3f3f;
const int N = 3005;

int S[2], T[2], L[2];

vector<int> G[N];

int dis[N][N];

void bfs(int id) {
	queue<P> q;
	q.push(P(id, 0));
	dis[id][id] = 0;
	while(!q.empty()) {
		P u = q.front(); q.pop();
		for(int i = 0; i < G[u.X].size(); ++i) {
			int v = G[u.X][i];
			if(dis[id][v] == INF) {
				q.push(P(v, u.Y + 1));
				dis[id][v] = u.Y + 1;
			}
		}
	}
}

int gao(int n, int m) {

	memset(dis, 0x3f, sizeof(dis));

	for(int i = 1; i <= n; ++i) {
		bfs(i);
	}

	int min_d1 = dis[S[0]][T[0]], min_d2 = dis[S[1]][T[1]];
	if(min_d1 > L[0] || min_d2 > L[1]) return -1;
	int minn = min_d1 + min_d2;
	//cout<<minn<<endl;

	//for(int i = 1; i <= n; ++i) {
	//	for(int j = 1; j <= n; ++j) {
	//		cout<<dis[i][j]<<' ';
	//	}
	//	cout<<endl;
	//}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			int mid = dis[i][j];
			if(mid == INF) continue;
			int line1 = dis[j][S[0]] + mid + dis[i][T[0]];
			int line2 = dis[j][S[1]] + mid + dis[i][T[1]];
			int left, right;
			if(line1 <= L[0] && line2 <= L[1]) {
				left = dis[i][T[0]] + dis[i][T[1]];
				right = dis[j][S[0]] + dis[j][S[1]];
				if(left < INF && right < INF)
					minn = min(minn, left + mid + right);
			}

			line1 = dis[j][S[0]] + mid + dis[i][T[0]];
			line2 = dis[i][S[1]] + mid + dis[j][T[1]];
			if(line1 <= L[0] && line2 <= L[1]) {
				left = dis[i][T[0]] + dis[i][S[1]];
				right = dis[j][S[0]] + dis[j][T[1]];
				if(left < INF && right < INF)
					minn = min(minn, left + mid + right);
			}

			line1 = dis[i][S[0]] + mid + dis[j][T[0]];
			line2 = dis[i][S[1]] + mid + dis[j][T[1]];
			if(line1 <= L[0] && line2 <= L[1]) {
				left = dis[j][T[0]] + dis[j][T[1]];
				right = dis[i][S[0]] + dis[i][S[1]];
				if(left < INF && right < INF)
					minn = min(minn, left + mid + right);
			}

			line1 = dis[i][S[0]] + mid + dis[j][T[0]];
			line2 = dis[j][S[1]] + mid + dis[i][T[1]];
			if(line1 <= L[0] && line2 <= L[1]) {
				left = dis[j][T[0]] + dis[j][S[1]];
				right = dis[i][S[0]] + dis[i][T[1]];
				if(left < INF && right < INF)
					minn = min(minn, left + mid + right);
			}
		}
	}
	return minn;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].PB(v);
		G[v].PB(u);
	}
	for(int i = 0; i < 2; ++i) {
		scanf("%d%d%d", &S[i], &T[i], &L[i]);
	}
	int ans = gao(n, m);
	if(ans == -1) puts("-1");
	else {
		ans = m - ans;
		cout<<ans<<endl;
	}
	return 0;
}

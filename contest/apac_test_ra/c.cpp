#include <iostream>
#include <cstdio>
using namespace std;

#define LL long long

const int N = 105;
const int M = 1e4 + 5;
const LL INF = 10000000000000LL;

int U[M], V[M];
LL C[M];

LL dis[N][N];

int ans[M], tot;

void init(int n) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}
	}
	tot = 0;
}

void floyd(int n){
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i) {
			if(dis[i][k] == INF) continue;
			for(int j = 0; j < n; ++j){
				if(dis[k][j] == INF) continue;
				if(dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
}

int main() {
	int T;
	cin>>T;
	int cas = 0;
	while(T--) {
		int n, m;
		cin>>n>>m;
		init(n);
		for(int i = 0; i < m; ++i) {
			cin>>U[i]>>V[i]>>C[i];
			dis[U[i]][V[i]] = dis[V[i]][U[i]] = min(dis[U[i]][V[i]], C[i]);
		}
		
		floyd(n);

		//for(int i = 0; i < n; ++i) {
		//	for(int j = 0; j < n; ++j) {
		//		cout<<dis[i][j]<<' ';
		//	}
		//	cout<<endl;
		//}

		for(int i = 0; i < m; ++i) {
			if(dis[U[i]][V[i]] < C[i]) {
				ans[tot++] = i;
			}
		}
		printf("Case #%d:\n", ++cas);
		if(tot == 0) puts("");
		else {
			for(int i = 0; i < tot; ++i) {
				printf("%d%c", ans[i], i == tot - 1 ? '\n' : ' ');
			}
		}
	}
	return 0;
}

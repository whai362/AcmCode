#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define P pair<int, int>
#define X first
#define Y second

const int N = 105;

int G[N][N];

bool used[N][N];

const int MAX_LEN = N * N;
struct S {
	P a[MAX_LEN];
	int head, tail;
	int dir, len;
	void init() {
		head = tail = 0;
		a[head] = P(0, 0);
		dir = len = 1;
		used[0][0] = 1;
	}

	bool push(P x) {
		if(used[x.X][x.Y]) return false;
		head = (head - 1 + MAX_LEN) % MAX_LEN;
		a[head] = x;
		used[x.X][x.Y] = 1;
		return true;
	}
	void pop() {
		used[a[tail].X][a[tail].Y] = 0;
		tail = (tail - 1 + MAX_LEN) % MAX_LEN;
	}
	bool eat(int, int);
	bool deal(int, int, int);
} sn;

int op[3000];

void init(int n, int m) {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if((i + j) % 2) G[i - 1][j - 1] = 1;
			else G[i - 1][j - 1] = 0;
		}
	}
	sn.init();
	memset(used, 0, sizeof(used));
	memset(op, 0, sizeof(op));
}

void turn(int &x, int &y, int dir, int n, int m) {
	if(dir == 0) {
		--x;
	} else if(dir == 1) {
		++y;
	} else if(dir == 2) {
		++x;
	} else {
		--y;
	}
	x = (x + n) % n;
	y = (y + m) % m;
}

bool S :: eat(int x, int y) {
	if(G[x][y] == 1){
		G[x][y] = 0;
		return true;
	}
	return false;
}

bool S :: deal(int op, int n, int m) {
	int x = a[head].X;
	int y = a[head].Y;
	if(op == 1){
		dir = (dir + 3) % 4;
	} else if(op == 2) {
		dir = (dir + 1) % 4;
	}
	turn(x, y, dir, n, m);
	if(!eat(x, y)) pop();
	else ++len;
	//cout<<x<<' '<<y<<' '<<a[tail].X<<' '<<a[tail].Y<<' '<<len<<endl;;
	if(!push(P(x, y)))
		return false;
	else 
		return true;
}
int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while(T--) {
		int s, n, m;
		scanf("%d%d%d", &s, &n, &m);
		init(n, m);
		//for(int i = 0; i < n; ++i) {
		//	for(int j = 0; j < m; ++j) {
		//		cout<<G[i][j]<<' ';
		//	}
		//	cout<<endl;
		//}
		//cout<<endl;
		for(int i = 0; i < s; ++i) {
			int t;
			char str[5];
			scanf("%d%s", &t, str);
			if(str[i] == 'L') op[t] = 1;
			else op[t] = 2;
		}
		printf("Case #%d: ", ++cas);
		for(int i = 1; i < 3000; ++i) {
			if(!sn.deal(op[i], n, m)) break;
		}
		cout<<sn.len<<endl;
	}
	return 0;
}

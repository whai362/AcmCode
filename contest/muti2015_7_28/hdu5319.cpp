#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 55;
char str[N][N];

int dx[] = {1, 1};
int dy[] = {1, -1};

bool ok(int type, int x, int y) {
	if(str[x][y] == 'G') return true;
	if(type == 0) {
		if(str[x][y] == 'R') return true;
		return false;
	} else {
		if(str[x][y] == 'B') return true;
		return false;
	}
}

bool in(int x, int y, int n, int m) {
	if(x >= 0 && x < n && y >= 0 && y < m) return true;
	return false;
}

void deal(int type, int x, int y, int n, int m, int &cnt) {
	while(in(x, y, n, m)) {
		while(in(x, y, n, m) && !ok(type, x, y)) {
			x += dx[type];
			y += dy[type];
		}
		if(in(x, y, n, m)) {
			++cnt;
			while(in(x, y, n, m) && ok(type, x, y)) {
				x += dx[type];
				y += dy[type];
			}
		}
	}
	//cout<<cnt<<endl;
}

void gao(int n, int m) {
	int red = 0;
	int blue = 0;
	for(int i = 0; i < m; ++i) {
		int x = 0, y = i;
		deal(0, x, y, n, m, red);
	}
	for(int i = 1; i < n; ++i) {
		int x = i, y = 0;
		deal(0, x, y, n, m, red);
	}
	for(int i = 0; i < m; ++i) {
		int x = 0, y = i;
		deal(1, x, y, n, m, blue);
	}
	for(int i = 1; i < n; ++i) {
		int x = i, y = m - 1;
		deal(1, x, y, n, m, blue);
	}
	printf("%d\n", red + blue);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%s", str[i]);
		int m = strlen(str[0]);
		gao(n, m);
	}
	return 0;
}

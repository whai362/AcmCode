#include <iostream>
#include <cstdio>
using namespace std;

void splay(int x) {
}

void access(int x) {
	int last = 0;
	while(x) {
		splay(x);
		child[x][1] = last;
		last = x;
		x = parent[x];
	}
}

int find(int x) {
	access(x);
	splay(x);
	while(child[x][0]) x = child[x][0];
	return x;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		char op[10];
		int x, y;
		scanf("%s%d%d", op, &x, &y);
		if(op[0] == 'Q') {
			int fx = find(x);
			int fy = find(y);
			if(fx == fy) puts("Yes");
			else puts("No");
		}
		else if(op[0] == 'C') link(x, y);
		else cut(x, y);
	}
	return 0;
}

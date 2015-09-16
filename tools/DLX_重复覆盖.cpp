/*poj 1084
  题意：n*n的矩形阵(n<=5)，由2*n*(n+1)根火柴构成，那么其中会有很多诸如边长为1，为2...为n的正方形，现在可以拿走一些火柴，那么就会有一些正方形被破坏掉。问，在已经拿走一些火柴的情况下，还需要拿走至少多少根就可以把所有的正方形破坏掉。
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define pb push_back
const int N = 5;

//重复覆盖模板
//最小覆盖
const int MaxM = 105;
const int MaxN = 105;
const int maxnode = MaxN * MaxM;
const int INF = 0x3f3f3f3f;
struct DLX {
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];
	int H[MaxN], S[MaxM];
	int ansd;
	void init(int _n, int _m) {
		ansd = INF;
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++) {
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)H[i] = -1;
	}
	void Link(int r, int c) {
		++S[Col[++size] = c];
		Row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0)H[r] = L[size] = R[size] = size;
		else {
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c) {
		for (int i = D[c]; i != c; i = D[i])
			L[R[i]] = L[i], R[L[i]] = R[i];
	}
	void resume(int c) {
		for (int i = U[c]; i != c; i = U[i])
			L[R[i]] = R[L[i]] = i;
	}
	bool v[MaxM];
	int f() {
		int ret = 0;
		for (int c = R[0]; c != 0; c = R[c])v[c] = true;
		for (int c = R[0]; c != 0; c = R[c])
			if (v[c]) {
				ret++;
				v[c] = false;
				for (int i = D[c]; i != c; i = D[i])
					for (int j = R[i]; j != i; j = R[j])
						v[Col[j]] = false;
			}
		return ret;
	}
	void Dance(int d) {
		if (d + f() >= ansd)return;
		if (R[0] == 0) {
			if (d < ansd)ansd = d;
			return;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
			if (S[i] < S[c])
				c = i;
		for (int i = D[c]; i != c; i = D[i]) {
			remove(i);
			for (int j = R[i]; j != i; j = R[j])remove(j);
			Dance(d + 1);
			for (int j = L[i]; j != i; j = L[j])resume(j);
			resume(i);
		}
	}
};
DLX g;

int n;
int hash[105];
void init() {
	vector<int> rec[105];
	vector<int> cell;
	int cnt = 1;
	for (int i = 1; i <= n; ++i) {
		cell.clear();
		for (int j = 1; j <= i; ++j) cell.pb(j), rec[cnt].pb(j);	//上
		for (int j = (2 * n + 1) * i + 1; j <= (2 * n + 1)*i + i; ++j) cell.pb(j), rec[cnt].pb(j);	//下
		for (int j = n + 1; j <= n + 1 + (2 * n + 1) * (i - 1); j += 2 * n + 1) cell.pb(j), rec[cnt].pb(j);	//左
		for (int j = n + i + 1; j <= n + i + 1 + (2 * n + 1) * (i - 1); j += 2 * n + 1) cell.pb(j), rec[cnt].pb(j);	//右
		++cnt;
		int sz = cell.size();
		for (int j = 1; j <= n - i + 1; ++j) {
			for (int k = 1; k <= n - i + 1; ++k) {
				if (j == 1 && k == 1) continue;
				int id = (2 * n + 1) * (k - 1) + j;
				for (int l = 0; l < sz; ++l) {
					rec[cnt].pb(cell[l] - cell[0] + id);
				}
				++cnt;
			}
		}
	}
	--cnt;
	g.init(2 * n * (n + 1), cnt);

	int m, rm;
	scanf("%d", &m);
	memset(hash, 0, sizeof(hash));
	for (int i = 0; i < m; ++i) {
		scanf("%d", &rm);
		hash[rm] = 1;
	}

	for (int i = 1; i <= cnt; ++i) {
		int flag = 0;
		for (int j = 0; j < rec[i].size(); ++j) {
			if (hash[rec[i][j]]) {
				flag = 1;
				break;
			}
		}
		if (flag) {	//去掉某些情况
			g.R[g.L[i]] = g.R[i];
			g.L[g.R[i]] = g.L[i];
			continue;
		}
		for (int j = 0; j < rec[i].size(); ++j) {
			g.Link(rec[i][j], i);
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		init();
		g.Dance(0);
		printf("%d\n", g.ansd);
	}
	return 0;
}

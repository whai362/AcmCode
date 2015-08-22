#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 6005;
const int MOD = 10007;

int que[N], fr, ta;

struct ACM {
	int cnt;
	int nxt[N][26], sum[N], fail[N];
	void init() {
		for(int i = 1; i <= cnt; ++i) {
			sum[i] = fail[i] = 0;
			for(int j = 0; j < 26; ++j)
				nxt[i][j] = 0;
		}
		cnt = 1;
		for(int i = 0; i < 26; ++i) nxt[0][i] = 1;
	}
	void insert(string str) {
		int now = 1;
		int len = str.length();
		for(int i = 0; i < len; ++i) {
			if(nxt[now][str[i] - 'A'] == 0) nxt[now][str[i] - 'A'] = ++cnt;
			now = nxt[now][str[i] - 'A'];
		}
		sum[now] = 1;
	}
	void build_fail() {
		fr = ta = 0;
		que[ta++] = 1;
		fail[1] = 0;
		while(fr != ta) {
			int now = que[fr++];
			for(int i = 0; i < 26; ++i) {
				int x = nxt[now][i];
				if(x == 0) continue;
				int tmp = fail[now];
				while(nxt[tmp][i] == 0) tmp = fail[tmp];
				fail[x] = nxt[tmp][i];
				que[ta++] = x;
			}
		}
	}
	void debug() {
		for(int i = 1; i <= cnt; ++i) {
			cout<<i<<": "<<"fail = "<<fail[i]<<" [ ";
			for(int j = 0; j < 26; ++j) {
				if(nxt[i][j]) cout<<char(j + 'A')<<','<<nxt[i][j]<<' ';
			}
			puts("]");
		}
	}
	void gao(int, int);
} acm;

int dp[2][105][N];

void ACM::gao(int n, int m) {
	build_fail();
	//debug();
	memset(dp, 0, sizeof(dp));
	dp[0][0][1] = 1;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= cnt; ++j) {
			int u = j;
			for(int k = 0; k < 26; ++k) {
				int v = u;
				while(nxt[v][k] == 0) v = fail[v];
				v = nxt[v][k];
				if(sum[v]) {
					dp[1][i][v] = (dp[1][i][v] + dp[1][i - 1][u] + dp[0][i - 1][u]) % MOD;
					dp[0][i][v] += 0;
				} else {
					dp[1][i][v] = (dp[1][i][v] + dp[1][i - 1][u]) % MOD;
					dp[0][i][v] = (dp[0][i][v] + dp[0][i - 1][u]) % MOD;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= cnt; ++i)
		ans = (ans + dp[1][m][i]) % MOD;
	cout<<ans<<endl;
}

string str[65];

bool ok(int x, int n) {
	int len = str[x].length();
	for(int i = 0; i < n; ++i) {
		if(i == x) continue;
		int pos = str[x].find(str[i]);
		if(pos >= 0 && pos < len) return false;
	}
	return true;
}

int main() {
	int n, m;
	cin>>n>>m;
	acm.init();
	for(int i = 0; i < n; ++i) {
		cin>>str[i];
	}
	sort(str, str + n);
	n = unique(str, str + n) - str;
	for(int i = 0; i < n; ++i) {
		if(ok(i, n)) acm.insert(str[i]);
	}
	acm.gao(n, m);
	return 0;
}

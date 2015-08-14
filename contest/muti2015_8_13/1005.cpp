#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int N = 500005;
int que[N];
char str[N];
string A[N];
struct acm {
	int cnt;
	int next[N][26], sum[N], fail[N];
	void clear() {
		for (int i = 1; i <= cnt; ++i) {
			sum[i] = fail[i] = 0;
			for (int j = 0; j < 26; ++j)
				next[i][j] = 0;
		}
		cnt = 1;
		for (int i = 0; i < 26; ++i)
			next[0][i] = 1;
	}
	void insert(char str[]) {
		int now = 1;
		int len = strlen(str);
		for (int i = 0; i < len; ++i) {
			if (!next[now][str[i] - 'a'])
				next[now][str[i] - 'a'] = ++cnt;
			now = next[now][str[i] - 'a'];
		}
		++sum[now];
	}
	void buildFail() {
		int head = 0, tail = 1;
		que[0] = 1;
		fail[1] = 0;
		while (head != tail) {
			int now = que[head];
			head++;
			for (int i = 0; i < 26; ++i) {
				int ch = next[now][i];
				if (!ch)
					continue;
				int tmp = fail[now];
				while (!next[tmp][i])
					tmp = fail[tmp];
				fail[ch] = next[tmp][i];
				que[tail++] = ch;
			}
		}
	}
	void gao(int n) {
		for (int l = 0; l < n; ++l) {
			int ans = 0, now = 1, len = A[l].length();
			for (int i = 0; i < len; ++i) {
				while (!next[now][A[l][i] - 'a'])
					now = fail[now];
				now = next[now][A[l][i] - 'a'];
				for (int j = now; j; j = fail[j]) {
					ans += sum[j];
				}
			}
			cout << ans << endl;
		}
	}
	void debug() {
		for (int i = 0; i <= cnt; ++i) {
			printf("id=%3d,fail=%3d,sum=%3d,ch=[\n", i, fail[i], sum[i]);
			for (int j = 0; j < 26; ++j)
				printf("%2c", j + 'a');
			puts("");
			for (int j = 0; j < 26; j++)
				printf("%2d", next[i][j]);
			puts("");
			printf("]\n");
		}
	}
} acm;
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> A[i];

		acm.clear();
		for (int i = 0; i < m; ++i) {
			cin >> str;
			acm.insert(str);
		}
		acm.buildFail();
		//acm.debug();

		acm.gao(n);
	}
	return 0;
}

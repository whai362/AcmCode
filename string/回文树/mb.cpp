const int N = 1e5 + 5;
const int M = 26;

struct PalTree {
	int nxt[N][M];
	int fail[N];
	int num[N];
	int len[N];
	int S[N];
	int last, n, p;

	int new_node(int x) {
		memset(nxt[p], 0, sizeof(nxt[p]));
		cnt[p] = 0;
		num[p] = 0;
		len[p] = x;
	}

	void init() {
		p = 0;
		new_node(0);
		new_node(-1);
		last = 0;
		n = 0;
		S[n] = -1;
		fail[0] = 1;
	}

	int get_fail(int x) {
		while(S[n - len[x] - 1] != S[n]) x = fail[x];
		return x;
	}

	void add(int x) {
		x -= 'a';
		s[++n] = x;
		int cur = get_fail(last);
		if(!nxt[cur][x]) {
			int now = new_node(len[cur] + 2);
			fail[now] = nxt[get_fail(fail[cur])][x];
			nxt[cur][x] = now;
			num[now] = num[fail[now]] + 1;
		}
		last = nxt[cur][x];
		++cnt[last];
	}

	void count() {
		for(int i = p - 1; i >= 0; --i)
			cnt[fail[i]] += cnt[i];
	}
}

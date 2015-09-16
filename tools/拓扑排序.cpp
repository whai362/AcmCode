vector<int> mp;
int in[N];
bool tp() {
	int cnt = 0;
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (in[i] == 0) { q.push(i); ++cnt; }
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < mp[now].size(); ++i) {
			int ch = mp[now][i];
			--in[ch];
			if (in[ch] == 0) { q.push(ch); ++cnt; }
		}
	}
	if (cnt == n) return true;
	return false;
}
void init() {
	for (int i = 1; i <= n; ++i)
		mp[i].clear();
	memset(in, 0, sizeof(in));
}

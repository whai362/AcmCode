int cantor(const vector<int> &v) {
	int ans = 0;
	for (int i = 0; i < (int)v.size() - 1; i++) {
		int small = 0;
		for (size_t j = i + 1; j < v.size(); j++)
			small += v[j] < v[i];
		ans = (ans + small) * (v.size() - i - 1);
	}
	return ans;
}
void uncantor(int x, vector<int> &v) {
	fill(v.begin(), v.end(), 0);
	static int used[8];
	memset(used, 0, sizeof(used));
	for (int i = 0; i < v.size(); i++) {
		int t = x / fact[v.size() - i - 1]; //t：比当前位小的只有t个
		x -= t * fact[v.size() - i - 1]; //删去
		t ++;
		int n = 1;
		while (t) {
			t -= !used[n];
			if (t == 0) {
				used[n] = 1;
				v[i] = n;
			}
			n++;
		}
	}
}

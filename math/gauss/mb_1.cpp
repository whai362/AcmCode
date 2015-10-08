const int N = 105;
struct Gauss {
	int f[N][N], x[N];
	int f_x[N], f_tot;
	
	//n表示等式个数，m表示变元个数
	int gauss(int n, int m) {
		int i, c;
		for(i = 0, c = 0; i < n && c < m; ++c) {
			int k = i;
			while(k < n && !f[k][c]) ++k;
			if(f[k][c] == 0) {
				f_x[f_tot++] = c;
				continue;
			}
			for(int j = c; j <= m; ++j)
				swap(f[i][j], f[k][j]);
			for(int j = 0; j < n; ++j)
				if(i != j && f[j][c])
					for(int k = 0; k <= m; ++k) //
						f[j][k] ^= f[i][k];
			++i;
		}
		for(int j = i; j < n; ++j) if(f[j][m]) return -1;
		if(i < m) return m - i;
		for(int j = m - 1; j >= 0; --j) {
			x[j] = f[j][m] & f[j][j];
		}
		return 0;
	}

	void init() {
		f_tot = 0;
		memset(f, 0, sizeof(f));
	}
}g;

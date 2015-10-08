const int N = 105;
struct Gauss {
	double f[N][N], x[N];
	bool gauss(int n, int m) {
		int i, c;
		for(i = 0, c = 0; i < n && c < m; ++c) {
			int k = i;
			while(k < n && fabs(f[k][c]) <= EPS) ++k;
			if(fabs(f[k][c]) <= EPS) continue;
			for(int j = c; j <= m; ++j)
				swap(f[i][j], f[k][j]);
			for(int j = 0; j < n; ++j)
				if(i != j && fabs(f[j][c]) > EPS) {
					double tmp = f[j][c] / f[i][c];
					for(int k = 0; k <= m; ++k)
						f[j][k] = f[j][k] - f[i][k] * tmp;
				}
			++i;
		}
		for(int j = i; j < n; ++j) if(fabs(f[j][m]) > EPS) return -1;
		if(i < m) return m - i;
		for(int j = m - 1; j >= 0; --j)
			x[j] = f[j][m] / f[j][j];
		return 0;
	}
}g;

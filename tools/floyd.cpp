void floyd(int n) {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++) {
			if (dis[i][k] == INF) continue;
			for (int j = 0; j < n; j++) {
				if (dis[k][j] == INF) continue;
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
}
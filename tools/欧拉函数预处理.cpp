const int N = 1005;
int pri[N], pcnt;
int phi[N];
void getphi() {
	phi[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (!phi[i]) { pri[pcnt++] = i; phi[i] = i - 1; }
		for (int j = 0; i * pri[j] < N && j < pcnt; ++j) {
			if (i % pri[j] == 0) {
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			else phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
}

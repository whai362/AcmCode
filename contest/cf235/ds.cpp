#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
typedef long long LL;
int a[100];
LL f[1 << 18][100];
int main(){
	int m;
	LL n;
	cin >> n >> m;
	int N = 0;
	for ( ; n; n /= 10) a[N++] = n % 10;
	sort(a, a+N);
	f[0][0] = 1;
	for (int mask = 0; mask < (1 << N); mask++)
		for (int k = 0; k < m; k++)
			if (f[mask][k]) {
				LL cnt = f[mask][k], pre = -1;
				for (int i = N-1; i >= 0; i--) if (~mask >> i & 1) {
				if (a[i] == pre) continue;
				if (mask == 0 && a[i] == 0) break;
				f[mask | 1 << i][(k*10+a[i]) % m] += cnt;
				pre = a[i];
			}
		}
	cout << f[(1 << N)-1][0] << endl;

	return 0;
}


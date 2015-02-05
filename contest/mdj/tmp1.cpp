#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

lint s[22];
lint bit[22];
int m;
lint ans, n;

bool judge(lint x) {
	int b[22], bn = 0;
	while (x != 0LL) {
		b[bn++] = x % 10;
		x /= 10;
	}
	bn = unique(b, b + bn) - b;
	for (int i = 0, j = bn - 1; i < j; i++, j--) {
		if (b[i] != b[j]) return false;
	}
	return true;
}

void gao(lint x) {
	m = 0;
	lint y = x;
	int nn = 0;
	while (x != 0LL) {
		bit[m++] = x % 10;
		x /= 10;
		nn += bit[m - 1];
	}
	if (bit[0] == bit[m - 1] && nn == 2) {
		ans = y - 2LL;
		return;
	} else if (bit[m - 1] == 1 && nn == 1) {
		ans = y - 1LL;
		return;
	}
	for (int i = 0; i < m; i++) { // center
		if (i == m - 1 && bit[i] == 1) continue;
		for (int j = i; j >= 0; j--) { // desc
			for (int kk = 1; kk <= 9; kk++) {
				bool ok = true;
				lint tmp = 0;
				x = y;
				x -= s[j] * kk;
				if (x <= 0LL) continue;
				int nm = 0;
				while (x != 0LL) {
					bit[nm++] = x % 10;
					x /= 10;
					if (nm > j) {
						tmp += bit[nm - 1] * s[nm - 1];
					}
				}
				if (nm != m) continue;
				nm = unique(bit + i, bit + nm) - bit;
				bit[nm] = -1;
				int now = i;
				for (int k = i - 1; k >= j; k--) {
					if (bit[k] == bit[now]) {
						continue;
					} else if (bit[k] == bit[now + 1]) {
						now++;
					} else {
						ok = false;
						break;
					}
				}
				if (!ok) continue;
				int o = now;
				while (bit[o] < bit[o + 1]) o++;
				if (nm - now - 1 > j) {
					now++;
					continue;
				}
				int ee = j - 1;
				lint tt = tmp;
				for (int k = now + (o != now); k < o; k++) {
					tt += bit[k] * s[ee--];
				}
				int ss = 0;
				for (int k = nm - 1; k > o; k--) {
					tt += bit[k] * s[ss++];
				}
				for (int k = ss; k <= ee; k++) {
					tt += bit[o] * s[k];
				}
				if (judge(tt) && tt < y) ans = max(tt, ans);
			}
		}
	}
	/*
	   for(int i = p; i >= 0; i--){// center at i
	   vector<int> vi;
	   for(int j = i; j >= 0; ){
	   int k = j;
	   while(k >= 0 && bit[k] == bit[j]) k--;
	   vi.push_back(bit[j]);
	   j = k;
	   }
// vi[0] from 0, vi[i] from 1
for(int j = i; j <= p; j++){ // who down

}
}
*/
}

int main() {
	s[0] = 1;
	for (int i = 1; i < 20; i++) {
		s[i] = s[i - 1] * 10LL;
	}
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%lld", &n);
		if (n <= 10LL) {
			printf("%lld\n", n - 1);
			continue;
		} else if (n == 21LL || n == 22LL) {
			printf("11\n");
			continue;
		}
		ans = -1;
		gao(n);
		printf("%lld\n", ans);
	}
	return 0;
}

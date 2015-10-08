#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 2000005;
const int INF = 0x3f3f3f3f;
int a1[N], a2[N];

bool is_pri[N];
int pri[N], tot;
void get_pri(int n = N) {
	tot = 0;
	memset(is_pri, 1, sizeof(bool) * (n + 1));
	is_pri[0] = is_pri[1] = 0;
	for (int i = 2; i < n; ++i)
		if (is_pri[i]) {
			if (n / i < i) break;
			for (int j = i * i; j <= n; j += i) is_pri[j] = false;
		}
	for (int i = 2; i <= n; ++i) if (is_pri[i]) pri[tot++] = i;
}

void predo() {
	char A[10], B[10];
	int c1 = 0;
	for(int i = 1; i < N; ++i) {
		sprintf(A, "%d", i);
		int len = strlen(A);
		for(int j = 0; j < len; ++j) {
			B[j] = A[len - j - 1];
		}
		B[len] = 0;
		if(strcmp(A, B) == 0) ++c1;
		a1[i] = c1;
	}
	get_pri();
	int c2 = 0;
	for(int i = 1; i < N; ++i) {
		if(is_pri[i]) ++c2;
		a2[i] = c2;
	}
}

bool ok(int i, int p, int q) {
	return a2[i] * q <= p * a1[i];
}

int main() {
	predo();
	int p, q;
	cin>>p>>q;
	int ans = 0;
	for(int i = 1; i < N; ++i) {
		if(ok(i, p, q)) {
			ans = max(ans, i);
		}
	}
	if(ans == 0) puts("Palindromic tree is better than splay tree");
	else cout<<ans<<endl;
	return 0;
}

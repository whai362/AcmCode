#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

#define LL __int64

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
LL p2[N];

map<int, LL> sum;

void predo() {
	p2[0] = 1;
	for(int i = 1; i < N; ++i) {
		p2[i] = p2[i - 1] * 2 % MOD;
	}
}

int main() {
	predo();
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		sum.clear();
		LL ans = 0;
		for(int i = 0; i < n; ++i) {
			int a;
			scanf("%d", &a);
			LL L = (p2[i] - sum[a] + MOD) % MOD;
			LL R = p2[n - i - 1];
			ans = (ans + a * L % MOD * R % MOD) % MOD;
			sum[a] = (sum[a] + p2[i]) % MOD;
		}
		cout<<ans<<endl;
	}
}

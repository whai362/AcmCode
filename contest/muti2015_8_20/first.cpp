#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define LL __int64
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second

const int N = 1e6 + 5;
const int MOD = 1000000007;

int maxx[N];
int cnt[N];

vector<P> fac[N];

void init() {
	memset(maxx, 0, sizeof(maxx));
	memset(cnt, 0, sizeof(cnt));
}

void deal(int x) {
	int id = x;
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			P tmp;
			tmp.X = i;
			tmp.Y = 0;
			while(x % i == 0){
				++tmp.Y;
				x /= i;
			}
			fac[id].PB(tmp);
		}
	}
	if(x > 1) fac[id].PB(P(x, 1));
}

void predo() {
	for(int i = 2; i < N; ++i) {
		deal(i);
	}
}

LL a_b_MOD_c(LL a,LL b,LL mod){
	LL ret = 1;
	a %= mod;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

void gao(int x) {
	for(int i = 1; i <= x / 2; ++i) {
		int mul = x - i + 1;
		int div = i;
		//cout<<mul<<' '<<div<<endl;
		for(int j = 0; j < fac[div].size(); ++j) {
			P tmp = fac[div][j];
			cnt[tmp.X] -= tmp.Y;
		}
		for(int j = 0; j < fac[mul].size(); ++j) {
			P tmp = fac[mul][j];
			cnt[tmp.X] += tmp.Y;
			maxx[tmp.X] = max(maxx[tmp.X], cnt[tmp.X]);
		}
		//for(int j = 1; j < 10; ++j)
		//	cout<<cnt[j]<<' ';
		//cout<<endl;
	}
	LL ans = 1;
	for(int i = 0; i < N; ++i) {
		if(maxx[i] == 0) continue;
		ans = ans * a_b_MOD_c(i, maxx[i], MOD) % MOD;
	}
	printf("%I64d\n", ans);
}

int main() {
	int T;
	predo();
	scanf("%d", &T);
	//for(int i = 0; i < fac[3].size(); ++i) {
	//	cout<<fac[3][i].X<<' '<<fac[3][i].Y<<endl;
	//}
	while(T--) {
		init();
		int n;
		scanf("%d", &n);
		gao(n);
	}
	return 0;
}

#include <iostream>
#include <cstring>
#define  REP(i, n) for (int i = 0; i < int(n); ++i)
#define  FOR(i, n) for (int i = 1; i <= int(n); ++i)

#define  LL  long long
#define  mod 1000000007ll
using namespace std;

inline void add(LL &x, LL y) {
	x = (x + y) % mod;
}

LL n;
int K, R;
struct M {
	LL a[35][35];
	void Z() {memset(a, 0, sizeof a);}
	void E() {Z(); REP(i, R) a[i][i] = 1;}
	friend M operator * (const M &x, const M &y) {
		M z; z.Z();
		REP(i, R) REP(j, R) REP(k, R)
			add(z.a[i][j], x.a[i][k] * y.a[k][j]);
		return z;
	}

};

M r[35];
M o[70];

int main() {
	cin >> n >> K;
	R = K + 1;

	int N[70], B = 0;
	while (n)
		N[B++] = n % K, n /= K;

	r[0].E();
	r[1].Z();
	r[1].a[0][0] = 1;
	FOR(j, K)
		r[1].a[j%K+1][j] = 1;
	FOR(i, K)
		r[i] = r[1] * r[i-1];
	for(int i=0;i<=K;++i){
		for(int j=0;j<R;++j){
			for(int k=0;k<R;++k){
				cout<<r[i].a[j][k]<<' ';
			}
			cout<<endl;
		}
		cout<<"---"<<endl;
	}


	o[0].E();
	REP(i, R)
		o[0].a[1][i] = 1;

	FOR(i, B) {
		o[i].E();
		REP(j, K)
			o[i] = r[j] * o[i-1] * r[K-j] * o[i];
	}

	M res; res.E();
	int s = 0;
	REP(i, B)
		REP(j, N[B-1-i])
			res = r[s%K] * o[B-1-i] * r[K-s%K] * res, s++;

	LL ans = 0;
	REP(i, R)
		add(ans, res.a[i][0]);

	cout << ans << endl;
	return 0;
}

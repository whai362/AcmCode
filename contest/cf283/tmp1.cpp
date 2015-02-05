#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;

struct Matrix {
	static const int MAXN = 32;
	int N;
	int a[MAXN][MAXN];

	void init(int _N, int _V) {
		N = _N;
		fill(a[0], a[N], _V);
	}

	void mul(const Matrix& b) {
		static Matrix l, r;
		REP (i, N) REP (j, N)
			l.a[i][j] = a[i][j], r.a[i][j] = b.a[i][j];
		REP (i, N) REP (j, N) {
			lint t = 0;
			REP (k, N) t += lint(l.a[i][k]) * r.a[k][j] % MOD;
			a[i][j] = t % MOD;
		}
	}
} A[64][32], prefix[64][32], suffix[64][32];

lint n;
int k;

void pre_calc(int i) {
	prefix[i][1] = A[i][0];
	for (int j = 2; j <= k; ++j) {
		prefix[i][j] = prefix[i][j - 1];
		prefix[i][j].mul(A[i][j - 1]);
	}
	suffix[i][k - 1] = A[i][k - 1];
	for (int j = k - 2; j >= 0; --j) {
		suffix[i][j] = A[i][j];
		suffix[i][j].mul(suffix[i][j + 1]);
	}
}

int digsum(lint n) {
	int s = 0;
	for (; n; n /= k) {
		(s += n % k) %= k;
	}
	return s;
}
int tt(lint n){
	int s=0;
	for(;n;n/=k){
		s+=n%k;
	}
	return s;
}
void print(int a,int b){
	cout<<a<<' '<<b<<endl;
	for(int i=0;i<A[a][b].N;++i){
		for(int j=0;j<A[a][b].N;++j){
			cout<<A[a][b].a[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<"-----"<<endl;
}

void prt(Matrix a){
	for(int i=0;i<a.N;++i){
		for(int j=0;j<a.N;++j){
			cout<<a.a[i][j]<<' ';
		}
		cout<<endl;
	}
}
Matrix solve(lint n, int m) {
	if (n < k) {
		Matrix mat = A[m][0];
		//cout<<m<<' '<<0<<endl;
		for (int i = 1; i < n; ++i) {
			mat.mul(A[m][i]);
			//cout<<m<<' '<<i<<endl;
			//cout<<"!!!"<<endl;
			//print(m,i);
		}
		return mat;
	}
	Matrix mat = solve(n / k, m + 1);
	int x = digsum(n / k);
	cout<<n<<' '<<tt(n/k)<<' '<<digsum(n/k)<<endl;
	for (int i = 0; i < n % k; ++i) {
		mat.mul(A[m][(x + i) % k]);
		//cout<<m<<' '<<i<<endl;
		//cout<<"!!!"<<endl;
		//print(m,(x+i)%k);
	}
	return mat;
}

int main() {
	cin >> n >> k;
	REP (i, k) {
		A[0][i].init(k + 1, 0);
		REP (j, k + 1) {
			A[0][i].a[j][j] = 1;
			A[0][i].a[j][i] = 1;
		}
		print(0,i);
	}
	for (int m = 1; pow(k, m) - 1000 <= n; ++m) {
		pre_calc(m - 1);
		REP (x, k) {
			A[m][x] = suffix[m - 1][x];
			if (x > 0) {
				A[m][x].mul(prefix[m - 1][x]);
			}
			print(m,x);
		}
	}
	Matrix mat = solve(n, 0);
	prt(mat);
	int ans = 0;
	REP (i, k + 1) {
		(ans += mat.a[k][i]) %= MOD;
	}
	cout<<endl;
	cout << ans << endl;
	return 0;
}

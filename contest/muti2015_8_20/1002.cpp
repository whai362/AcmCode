#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define LL __int64

const int MOD = 1000000007;
const int N = 1e6 + 5;
bool is_pri[N];
int pri[N], tot;
void get_pri(int n){
	tot = 0;
	memset(is_pri, 1, sizeof(bool) * (n + 1));
	is_pri[0] = is_pri[1] = 0;
	for(int i = 2; i <= n; ++i)
		if(is_pri[i]){
			if(n / i < i) break;
			for(int j = i * i; j <= n; j += i) is_pri[j] = false;
		}
	for(int i = 2; i <= n; ++i) if(is_pri[i]) pri[tot++] = i;
}

bool is_pow[N];
int p[N];
LL ans[N];

void predo() {
	get_pri(N - 1);
	for(int i = 0; i < N; ++i) {
		if(is_pri[i]) {
			LL x = i;
			while(x < N) {
				is_pow[x] = true;
				p[x] = i;
				x *= i;
			}
		}
	}
	ans[1] = 1;
	for(int i = 2; i < N; ++i) {
		if(is_pow[i]) ans[i] = ans[i - 1] * p[i] % MOD;
		else ans[i] = ans[i - 1];
	}
	//for(int i = 1; i < 6; ++i) {
	//	cout<<is_pow[i]<<' '<<p[i]<<endl;
	//}
	//cout<<endl;
	//for(int i = 1; i < 6; ++i) {
	//	cout<<ans[i]<<' ';
	//}
	//cout<<endl;
}

LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}

void gao(int x) {
	++x;
	LL out = ans[x] * inv(x, MOD) % MOD;
	printf("%I64d\n", out);
}

int main() {
	predo();
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		gao(n);
	}
	return 0;
}

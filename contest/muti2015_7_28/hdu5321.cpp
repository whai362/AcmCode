#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL __int64
const int N = 1e5 + 5;
const int MOD = 258280327;
int a[N];
int cnt[N];

int mu[N];
//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
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

void deal(int x) {
	for(int i = 1; i * i <= x; ++i) {
		if(x % i == 0){
			++cnt[i];
			if(i * i != x) ++cnt[x / i];
		}
	}
}

LL F1[N], F2[N];
LL pow2[N];
LL fac[N], ny[N];

LL C(int n, int m) {
	if(m > n) return 0;
	return fac[n] * ny[m] % MOD * ny[n - m] % MOD;
}

void gao(int n) {
	int maxa = 0;
	for(int i = 0; i < n; ++i) {
		deal(a[i]);
		maxa = max(maxa, a[i]);
	}
	
	for(int i = 1; i <= maxa; ++i) {
		F1[i] = 0;
		for(int j = 1; j <= cnt[i]; ++j) {
			F1[i] = (F1[i] + C(cnt[i], j) * fac[j] % MOD * fac[n - j + 1] % MOD) % MOD;
			//cout<<F1[i]<<' ';
		}
		//cout<<endl;
		//cout<<F1[i]<<' ';
	}
	//cout<<endl;
	
	LL ans1 = 0;
	for(int i = 1; i <= maxa; ++i) {
		LL tmp = 0;
		for(int j = 1; i * j <= maxa; ++j) {
			tmp = (tmp + mu[j] * F1[i * j]) % MOD;
		}
		ans1 = (ans1 + i * tmp) % MOD;
	}

	for(int i = 1; i <= maxa; ++i) {
		F2[i] = cnt[i] * pow2[cnt[i] - 1] % MOD;
	}

	LL ans2 = 0;
	for(int i = 1; i <= maxa; ++i) {
		LL tmp = 0;
		for(int j = 1; i * j <= maxa; ++j) {
			tmp = (tmp + mu[j] * F2[i * j]) % MOD;
		}
		ans2 = (ans2 + i * tmp) % MOD;
	}
	//cout<<ans1<<' '<<ans2<<endl;
	if(ans1 == ans2) printf("Equal ");
	else if(ans1 > ans2) printf("Mr. Zstu ");
	else printf("Mr. Hdu ");
	printf("%I64d\n", max(ans1, ans2));
}

void predo() {
	getMu();
	pow2[0] = 1;
	for(int i = 1; i < N; ++i)
		pow2[i] = pow2[i - 1] * 2 % MOD;
	fac[0] = ny[0] = 1;
	for(int i = 1; i < N; ++i) {
		fac[i] = fac[i - 1] * i % MOD;
		ny[i] = inv(fac[i], MOD);
	}
}

void init(int n) {
	memset(cnt, 0, sizeof(cnt));
}

int main() {
	int n;
	predo();
	while(scanf("%d", &n) != EOF) {
		init(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		gao(n);
	}
	return 0;
}

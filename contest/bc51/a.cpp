#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define LL __int64
const int N = 3 * 1e6 + 5;
const LL MOD = 3221225473LL;
int a[N];

bool used[N];
int L[N], tot = 0;
int cnt[N];

LL mul(LL a,LL b,LL m){
    LL ret = 0;
    a %= m;
    while(b){
        if(b & 1) ret = (ret + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return ret;
}
LL a_b_MOD_c(LL a,LL b,LL m){
    LL ret = 1;
    a %= m;
    while(b){
        if(b&1) ret = mul(ret,a,m);
        a = mul(a,a,m);
        b >>= 1;
    }
    return ret;
}

const int BZ = 120 << 20;
char Buf[BZ + 1], *buf = Buf;

template <class T>
inline void scan(T &a) {
	for(a = 0; *buf < '0' || *buf > '9'; ++buf);
	while(*buf >= '0' && *buf <= '9') {
		a = a * 10 + (*buf - '0');
		++buf;
	}
}

void Out(int x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

void Out(LL x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

void deal(int x) {
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			int tmp = 0;
			while(x % i == 0) {
				++tmp;
				x /= i;
			}
			cnt[i] = max(cnt[i], tmp);
		}
	}
	if(x > 1) cnt[x] = max(cnt[x], 1);
}

void gao(int n) {
	memset(used, 0, sizeof(used));
	tot = 0;
	for(int i = 1; i <= n; ++i) {
		if(used[i]) continue;
		int u = i;
		used[u] = 1;
		int len = 1;
		while(used[a[u]] == 0) {
			u = a[u];
			used[u] = 1;
			++len;
		}
		L[tot++] = len;
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < tot; ++i) {
		deal(L[i]);
	}
	LL ans = 1;
	for(int i = 2; i < N; ++i) {
		if(cnt[i] == 0) continue;
		ans = mul(ans, a_b_MOD_c(i, cnt[i], MOD), MOD);
	}
	//printf("%I64d\n", ans);
	Out(ans);
	puts("");
	//for(int i = 0; i < tot; ++i) {
	//	cout<<L[i]<<' ';
	//}
	//cout<<endl;
}

int main() {
	fread(Buf, 1, BZ, stdin);
	int n;
	int T;
	scan(T);
	while(T--) {
		int n;
		scan(n);
		for(int i = 1; i <= n; ++i) {
			scan(a[i]);
		}
		gao(n);
	}
	return 0;
}

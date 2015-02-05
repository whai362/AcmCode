#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<cstring>
using namespace std;
#define LL __int64

const int HASH_MOD=76543;
LL key[HASH_MOD], val[HASH_MOD];
int head[HASH_MOD], next[HASH_MOD];
struct Hash{
	int tot;
	void init(){
		memset(head, -1, sizeof(head));
		tot = 0;
	}
	LL insert(LL x, LL y){
		int k = x % HASH_MOD;
		key[tot] = x;
		val[tot] = y;
		next[tot] = head[k];
		head[k] = tot++;
	}
	LL find(LL x){
		int k = x % HASH_MOD;
		for(int i = head[k]; i != -1; i = next[i])
			if(key[i] == x)
				return val[i];
		return -1;
	}
}hs;

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
LL log_mod(LL a, LL b, LL m){
	if(b == 1) return 0;
	hs.init();
	LL s = sqrt(m);
	LL p = 1;
	for(int i = 0; i < s; ++i){
		hs.insert(p * b % m, i);
		p = p * a % m;
	}
	//cout<<"p"<<p<<endl;
	LL x = 1;
	for(LL i = s; ; i += s){
		x = x * p % m;
		LL fd = hs.find(x);
		if(fd != -1) return i - fd;
		if(i > m) break;
	}
	return -1;
}
int main(){
	int p, b, n;
	while(scanf("%d%d%d", &p, &b, &n) != EOF){
		LL ans = log_mod(b, n, p);
		if(ans == -1) puts("no solution");
		else printf("%I64d\n", ans);
	}
	return 0;
}

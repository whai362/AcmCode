#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
#define LL __int64

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

LL get_phi(LL x) {
	LL ret = 1;
	for(LL i = 2; i * i <= x; ++i)
		if(x % i == 0) {
			ret = ret * (i - 1);
			x /= i;
			while(x % i == 0) x /= i, ret *= i;
		}
	if(x > 1) ret = ret * (x - 1);
	return ret;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        LL k, b, x, p;
        LL ans;
        scanf("%I64d%I64d%I64d%I64d", &k, &b, &x, &p);
        if(k == 0) {
            LL tmp = (x * k + b) % p;
            if(x == tmp) puts("1");
            else puts("-1");
        } else if(k == 1) {
            if(b == 0) {
                puts("1");
            } else {
				LL ans = p / __gcd(p, b);
				printf("%I64d\n", ans);
            }
        } else {
            LL A = k;
            LL B = p * (k - 1);
            B = B / __gcd(x * (k - 1) + b, B);
			if(__gcd(A, B) != 1) puts("-1");
			else {
				LL phi = get_phi(B);
				LL ans = phi;
				for(LL i = 2; i * i <= phi; ++i) {
					if(phi % i == 0) {
						while(phi % i == 0) phi /= i;
						while(ans % i == 0 && a_b_MOD_c(A, ans / i, B) == 1) ans /= i;
					}
				}
				if(phi > 1 && a_b_MOD_c(A, ans / phi, B) == 1) ans /= phi;
				printf("%I64d\n",ans);
			}
		}
    }
    return 0;
}

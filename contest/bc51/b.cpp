#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
#define LL __int64

LL mul(LL a, LL b, LL m) {
	LL ret = 0;
	a %= m;
	while (b) {
		if (b & 1)
			ret = (ret + a) % m;
		a = (a + a) % m;
		b >>= 1;
	}
	return ret;
}
LL a_b_MOD_c(LL a, LL b, LL m) {
	LL ret = 1;
	a %= m;
	while (b) {
		if (b & 1)
			ret = mul(ret, a, m);
		a = mul(a, a, m);
		b >>= 1;
	}
	return ret;
}

bool test(LL n, LL a, LL d) {
	if (n == 2)
		return true;
	if (n == a)
		return true;
	if ((n & 1) == 0)
		return false;
	while (!(d & 1))
		d = d >> 1;
	LL t = a_b_MOD_c(a, d, n);
	while ((d != n - 1) && (t != 1) && (t != n - 1)) {
		t = mul(t, t, n);
		d = d << 1;
	}
	return (t == n - 1 || (d & 1) == 1);
}
const int Times = 10;
bool Miller_Rabin(LL n) {
	if (n < 2)
		return false;
	for (int i = 0; i <= Times; ++i) {
		LL a = rand() % (n - 1) + 1;
		if (!test(n, a, n - 1))
			return false;
	}
	return true;
}
LL pollard_rho(LL n, LL c) {
	LL i = 1, k = 2;
	LL x = rand() % (n - 1) + 1;
	LL y = x;
	while (1) {
		++i;
		x = (mul(x, x, n) + c) % n;
		LL d = __gcd((y - x + n) % n, n);
		if (1 < d && d < n)
			return d;
		if (y == x)
			return n;
		if (i == k) {
			y = x;
			k <<= 1;
		}
	}
}
LL fac[105];
int tot;
void find_fac(LL n, int c) {
	if (n == 1)
		return;
	if (Miller_Rabin(n)) {
		fac[tot++] = n;
		return;
	}
	LL p = n;
	LL k = c;
	while (p >= n)
		p = pollard_rho(p, c--);
	find_fac(p, k);
	find_fac(n / p, k);
}
void init() {
	tot = 0;
}
LL get_phi(LL x) {
	init();
	find_fac(x, 12345);
	sort(fac, fac + tot);
	LL ret = 1;
	for (int i = 0; i < tot; ++i) {
		LL sqr = fac[i] * fac[i];
		if (x % sqr)
			ret *= fac[i] - 1;
		else
			ret *= fac[i];
		x /= fac[i];
	}
	return ret;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		LL k, b, x, p;
		LL ans;
		scanf("%I64d%I64d%I64d%I64d", &k, &b, &x, &p);
		if (k == 0) {
			LL tmp = (x * k + b) % p;
			if (x == tmp)
				puts("1");
			else
				puts("-1");
		} else if (k == 1) {
			if (b == 0) {
				puts("1");
			} else {
				LL ans = p / __gcd(p, b);
				printf("%I64d\n", ans);
			}
		} else {
			LL A = k;
			LL B = p * (k - 1);
			B = B / __gcd(x * (k - 1) + b, B);
			if (__gcd(A, B) != 1)
				puts("-1");
			else {
				LL phi = get_phi(B);
				LL ans = phi;
				for (LL i = 2; i * i <= phi; ++i) {
					if (phi % i == 0) {
						while (phi % i == 0)
							phi /= i;
						while (ans % i == 0 && a_b_MOD_c(A, ans / i, B) == 1)
							ans /= i;
					}
				}
				if (phi > 1 && a_b_MOD_c(A, ans / phi, B) == 1)
					ans /= phi;
				printf("%I64d\n", ans);
			}
		}
	}
	return 0;
}

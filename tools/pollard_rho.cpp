/*poj 1811
  题意：
  给出一个整数n，判断n是不是素数，如果不是素数，输出最小的质因子。
  限制；
  2 <= N < 2^54
  思路：
  miller_rabin算法判素数
  pollard_rho算法求质因子
  复杂度O(log(n))
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define LL __int64
LL mul(LL a, LL b, LL m) {
	LL ret = 0;
	a %= m;
	while (b) {
		if (b & 1) ret = (ret + a) % m;
		a = (a + a) % m;
		b >>= 1;
	}
	return ret;
}
LL a_b_MOD_c(LL a, LL b, LL m) {
	LL ret = 1;
	a %= m;
	while (b) {
		if (b & 1) ret = mul(ret, a, m);
		a = mul(a, a, m);
		b >>= 1;
	}
	return ret;
}
bool test(LL n, LL a, LL d) {
	if (n == 2) return true;
	if (n == a) return true;
	if ((n & 1) == 0) return false;
	while (!(d & 1)) d = d >> 1;
	LL t = a_b_MOD_c(a, d, n);
	while ((d != n - 1) && (t != 1) && (t != n - 1)) {
		t = mul(t, t, n);
		d = d << 1;
	}
	return (t == n - 1 || (d & 1) == 1);
}
//要注意1的情况
const int Times = 10;
bool Miller_Rabin(LL n) {
	if (n < 2) return false;
	for (int i = 0; i <= Times; ++i) {
		LL a = rand() % (n - 1) + 1;
		if (!test(n, a, n - 1)) return false;
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
		if (1 < d && d < n) return d;
		if (y == x) return n;
		if (i == k) {
			y = x;
			k <<= 1;
		}
	}
}
//要注意1的情况
LL ans;
//LL fac[105];
//int tot;
void find_fac(LL n, int c) {
	if (n == 1) return ;
	if (Miller_Rabin(n)) {
		ans = min(ans, n);
		//fac[tot++]=n;
		return ;
	}
	LL p = n;
	LL k = c;
	while (p >= n) p = pollard_rho(p, c--);
	find_fac(p, k);
	find_fac(n / p, k);
}
void init(LL n) {
	ans = n;
	//tot=0;
}
int main() {
	LL n;
	int T;
	srand(12345);
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d", &n);
		init(n);
		find_fac(n, 12345);
		if (ans == n) puts("Prime");
		else printf("%I64d\n", ans);
	}
	return 0;
}

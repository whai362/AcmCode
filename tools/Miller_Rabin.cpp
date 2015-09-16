/*poj 3641
  题意：
  给出p,a, 判断p是不是对于a的伪素数。
  限制：
  2 < p <= 1e9; 1 < a < p;
  思路：
  Miller_Rabin算法
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
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
/*二次探测法：
  定理：如果p是素数，x是小于p的正整数，且(x^2)%p=1，那么要么x=1，要么x=p-1。
  过程：要测试N是否为素数，首先将N-1分解为d*2^s。在每次测试开始时，先随机选一个介于[1,N-1]的整数a，如果对于所有的r(0 <= r <= s-1)，都满足a^d%N!=1且a^(d*2^r)%N!=N-1，则N是合数。否则N有3/4的概率是素数。
 */
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
const int Times = 4;
bool Miller_Rabin(LL n) {
	if (n < 2) return false;
	for (int i = 0; i <= Times; ++i) {
		LL a = rand() % (n - 1) + 1;
		if (!test(n, a, n - 1)) return false;
	}
	return true;
}
bool gao(LL p, LL a) {
	if (Miller_Rabin(p)) puts("no");
	else if (a_b_MOD_c(a, p, p) == a) puts("yes");
	else puts("no");
}
int main() {
	LL p, a;
	srand(12345);
	while (scanf("%I64d%I64d", &p, &a) && (p || a)) {
		gao(p, a);
	}
	return 0;
}

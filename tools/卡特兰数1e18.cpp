/*hdu 5177
  题意：
  求第n个卡特兰数，模3814697265625 (5^18)
  限制：
  有20组数据，1 <= n <= 1e18
  思路：
  1. 卡特兰数的表达式：
  ans = 1/(n+1) * C(2*n,n)
  -> ans = 1/(n+1) * (2n)! / n! / n!    ---1式
  2. 因为要模5^18，求逆元要求互质，所以先把"1式"中的因子5全部去掉
  3. 然后看不含因子5的阶乘，f(n!)
  4. 设g(x,n)=(x+1)(x+2)(x+3)(x+4)(x+6)..(x+n)%M，x+d里面的d不是5的倍数
  5. 则有f(n!)=g(0,n)*g(0,n/5)*g(0,n/25)*…*g(0,0)%M    ---这里需要log(n)的复杂度
  6. 对于每个g(x,n)我们可以把g(x,n)分成尽量均匀的两段来计算
  part1=(x+1)(x+2)(x+3)(x+4)(x+6)*…*(x+5*k-1)
  part2=(x+5*k+1)(x+5*k +2)(x+5*k +3)(x+5*k +4)(x+5*k +6)*…*(x+5*k +5*k-1)
  剩余的项直接暴力乘上来就可以了
  然后不断地递归下去    ---这里需要log(n)的复杂度
  每次计算出part1，通过代入，可以O(1)计算出part2
  这里关键的一点是对于每一个多项式，都可以把它化成这样的形式：
  a1*x^0 + a2*x^1 + ... + an*x^n    ---2式
  可以看到，对于g(x,n)，x总是5的倍数，所以对于每一个part，它所生成的"2式"都不会超过18项。    ---这里需要18的复杂度
  这道题的复杂度为log(2n)*log(2n)*18+log(n)*log(n)*18。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
#define LL __int64
using namespace std;
const LL MOD = 3814697265625LL;
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
struct Po {	//多项式类
	int len;
	LL a[20];
	Po() {
		len = 0;
		memset(a, 0, sizeof(a));
	}
	void print() {
		for (int i = 0; i <= len; ++i)
			cout << a[i] << ' ';
		cout << endl;
	}
};


Po ret, part1, part2;
LL C[20][20];
LL a[20];
Po g(LL n, int p, int q) {
	if (n <= p) {
		ret.len = 1;
		ret.a[0] = 1;
		ret.a[1] = 1;
		for (int i = 2; i <= n; ++i) {
			if (i % p == 0) continue;
			a[0] = 0;
			for (int j = 0; j <= ret.len; ++j) {
				a[j + 1] = ret.a[j];
				ret.a[j] = (a[j] + mul(ret.a[j], i, MOD)) % MOD;
			}
			if (ret.len < q) {
				++ret.len;
				ret.a[ret.len] = a[ret.len];
			}
		}
		return ret;
	}
	LL k = (n + 1) / (2 * p);
	part1 = g(p * k - 1, p, q);
	part2 = Po();
	part2.len = part1.len;
	part2.a[0] = part1.a[0];

	LL tmp[20];
	tmp[0] = 1;
	for (int i = 1; i <= part2.len; ++i)
		tmp[i] = mul(tmp[i - 1], p * k, MOD);
	for (int i = 1; i <= part2.len; ++i) {
		for (int j = 0; j <= i; ++j) {
			part2.a[j] = (part2.a[j] + mul(mul(C[i][j], tmp[i - j], MOD), part1.a[i], MOD)) % MOD;	//
		}
	}
	ret = Po();
	for (int i = 0; i <= part1.len; ++i) {
		for (int j = 0; j <= part2.len; ++j) {
			if (i + j > q) break;
			ret.a[i + j] = (ret.a[i + j] + mul(part1.a[i], part2.a[j], MOD)) % MOD;
		}
	}

	ret.len = min(part1.len + part2.len, q);
	for (LL i = 2 * p * k + 1; i <= n; ++i) {
		if (i % p == 0) continue;
		a[0] = 0;
		for (int j = 0; j <= ret.len; ++j) {
			a[j + 1] = ret.a[j];
			ret.a[j] = (a[j] + mul(ret.a[j], i, MOD)) % MOD;
		}
		if (ret.len < q) {
			++ret.len;
			ret.a[ret.len] = a[ret.len];
		}
	}
	return ret;
}
LL f(LL n, int p, int q) {
	LL ret = 1;
	for (LL i = n; i > 0; i /= p) {
		ret = mul(ret, g(i, 5, 18).a[0], MOD);
	}
	return ret;
}
LL inv(LL a, LL m) {
	LL p = 1, q = 0, b = m, c, d;
	while (b > 0) {
		c = a / b;
		d = a; a = b; b = d % b;
		d = p; p = q; q = d - c * q;
	}
	return p < 0 ? p + m : p;
}
LL gao(LL m, int p, int q) {
	LL n = 2 * m;
	if (m < 0 || m > n || n < 0) return 0;
	int cnt = 0;
	for (LL i = n / p; i > 0; i /= p) cnt += i;
	for (LL i = m / p; i > 0; i /= p) cnt -= 2 * i;
	LL t1 = m + 1;
	while (t1 % 5 == 0) {
		t1 /= 5;
		--cnt;
	}
	t1 = inv(t1, MOD);
	LL t2 = inv(f(m, 5, 18), MOD);
	LL ret = mul(mul(mul(f(n, 5, 18), t2, MOD), t2, MOD), t1, MOD);
	ret = mul(ret, a_b_MOD_c(p, cnt, MOD), MOD);
	return ret;
}
void predo() {
	for (int i = 0; i <= 18; ++i)
		C[i][0] = C[i][i] = 1;
	for (int i = 2; i <= 18; ++i)
		for (int j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
}
int main() {
	//double start=clock(),end;
	int T;
	LL n;
	int cas = 0;
	predo();
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d", &n);
		printf("Case #%d: ", ++cas);
		LL ans = gao(n, 5, 18);
		cout << ans << endl;
	}
	//end=clock();
	//cerr<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
	return 0;
}
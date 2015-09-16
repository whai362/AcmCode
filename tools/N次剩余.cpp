/*hdu 3930
  题意：
  给定newx, k, m, 方程 (x^k)%m=newx, 求在模m意义下的所有解x。
  限制：
  0 <= newx, m, k <= 1.5*10^15; m是素数。
  思路：
  N次剩余
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define LL __int64
#define PB push_back
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

LL ext_gcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) { x = 1, y = 0; return a; }
	LL ret = ext_gcd(b, a % b, y, x);
	y -= a / b * x;
	return ret;
}
vector<LL> a;
bool g_test(LL g, LL p) {
	for (LL i = 0; i < a.size(); ++i)
		if (a_b_MOD_c(g, (p - 1) / a[i], p) == 1)
			return 0;
	return 1;
}
LL pri_root(LL p) {
	a.clear();
	LL tmp = p - 1;
	for (LL i = 2; i <= tmp / i; ++i)
		if (tmp % i == 0) {
			a.push_back(i);
			while (tmp % i == 0)
				tmp /= i;
		}
	if (tmp != 1)
		a.push_back(tmp);
	LL g = 1;
	while (true) {
		if (g_test(g, p))
			return g;
		++g;
	}
}
const int HASH_MOD = 9876543;
LL key[HASH_MOD], val[HASH_MOD];
int head[HASH_MOD], next[HASH_MOD];
struct Hash {
	int tot;
	void init() {
		memset(head, -1, sizeof(head));
		tot = 0;
	}
	LL insert(LL x, LL y) {
		int k = x % HASH_MOD;
		key[tot] = x;
		val[tot] = y;
		next[tot] = head[k];
		head[k] = tot++;
	}
	LL find(LL x) {
		int k = x % HASH_MOD;
		for (int i = head[k]; i != -1; i = next[i])
			if (key[i] == x)
				return val[i];
		return -1;
	}
} hs;
//求解模方程a^x=b(mod m),n为素数,无解返回-1
//注意：要求0 < a < m; 0 <= b < m; 否则按题意自己转化。
//复杂度O(sqrt(m))
LL log_mod(LL a, LL b, LL m) {
	hs.init();
	LL s = ceil(sqrt(m + 0.5));
	LL cur = 1;
	for (int i = 0; i < s; ++i) {
		if (hs.find(cur) == -1) hs.insert(cur, i); //记得先判重，在插入
		cur = cur * a % m;
	}

	LL v = a_b_MOD_c(a, (m - s - 1 + m) % m, m);
	for (int i = 0; i < s; ++i) {
		LL tmp = hs.find(b);
		if (tmp != -1)
			return s * i + tmp;
		b = b * v % m;
	}
	return -1;
}
/*n次剩余
  任务：
  给定N, a, p, 求出(x^N)%p=a 在模p意义下的所有解x。
  说明：
  令g为p的原根，因为p为素数，所以phi(p)=p-1。
  由原根的性质得：
  如果g为p的原根，则：g^i mod p != g^j mod p (p为素数), 其中i != j且i, j介於1至(p-1)之间
  所以，可以设g^y=x, g^t=a，则有：
  g^(y*N)%p=g^t
  又由原根的性质：
  g^(y*N)%p=g^t -> (y*N)%(p-1)=t (此方程可以由拓展欧几里得解)
  另外g^t=a可以由离散对数求出
 */
vector<LL> residue(LL p, LL N, LL a) {
	LL g = pri_root(p);
	g %= p;
	LL m = log_mod(g, a, p);
	vector<LL> ret;
	if (a == 0) {
		ret.PB(0);
		return ret;
	}
	if (m == -1)
		return ret;
	LL A = N, B = p - 1, C = m, x, y;
	LL d = ext_gcd(A, B, x, y);
	if (C % d != 0) return ret;
	x = x * (C / d) % B;
	LL delta = B / d;
	for (int i = 0; i < d; ++i) {
		x = ((x + delta) % B + B) % B;
		ret.PB(a_b_MOD_c(g, x, p));
	}
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	return ret;
}
int main() {
	int cas = 0;
	LL k, m, newx;
	while (scanf("%I64d%I64d%I64d", &k, &m, &newx) != EOF) {
		vector<LL> ans;
		ans = residue(m, k, newx);
		printf("case%d:\n", ++cas);
		if (ans.size() == 0) puts("-1");
		for (int i = 0; i < ans.size(); ++i)
			printf("%I64d\n", ans[i]);
	}
	return 0;
}

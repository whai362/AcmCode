/*lucas定理
  如果：
  n = a[k]*p^k + a[k-1]*p^(k-1) + ... + a[1]*p + a[0]
  m = b[k]*p^k + b[k-1]*p^(k-1) + ... + b[1]*p + b[0]
  则：
  C(n,m) = pe(i=0~k,C(a[i],b[i]))%p 其中pe表示连乘符号。
 */
LL lucas(int n, int m, int MOD) {
	if (n < m) return 0;	//注意
	LL ret = 1;
	while (n && m) {
		LL a = n % MOD, b = m % MOD;
		if (a < b) return 0;
		ret = ret * C(a, b, MOD) % MOD;
		n /= MOD;
		m /= MOD;
	}
	return ret;
}

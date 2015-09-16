/*hdu 3579
  题意：
  给出m_1,m_2,...m_n;a_1,a_2,...,a_n,非互质中国剩余定理。
  思路：
  中国剩余定理

  由于不两两互质，所以只能两个两个解。
  设通解为N
  ->N=m1*k1+r1,N=m2*k2+r2
  ->m1*k1+r1=m2*k2+r2
  ->k1*m1+(-k2*m2)=r2-r1
  ->设a=m1,b=m2,x=k1,y=(-k2),c=r2-r1
  ->ax+by=c 通过 d=ext_gcd(a,b,x,y) 得 d,x
  ->最小整数解x=(x*(c/d)%(b/d)+(b/d))%(b/d)
  ->N=a*(x+n*(b/d))+r1
  ->N=(a*b/d)*n+(a*x+r1)
  ->令m3=a*b/d,r3=a*x+r1,k3=n
  ->N=m3*k3+r3 化成了一个新的式子，不断迭代然后出结果。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
LL ext_gcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) { x = 1, y = 0; return a; }
	LL ret = ext_gcd(b, a % b, y, x);
	y -= a / b * x;
	return ret;
}
int n;
LL a[100005], m[100005];
LL CRT() {
	LL M = m[0];
	LL ret = a[0];
	for (int i = 1; i < n; ++i) {
		LL x, y, d;
		d = ext_gcd(M, m[i], x, y);
		if ((a[i] - ret) % d) return -1;	//注意无解时的返回值
		x = (a[i] - ret) / d * x % (m[i] / d);
		ret += x * M;
		M = M / d * m[i];
		ret %= M;
	}
	ret = (ret + M) % M;
	return ret == 0 ? M : ret;	//模除类问题要注意答案能不能为0
}
int main() {
	int T;
	int cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%I64d", &m[i]);
		for (int i = 0; i < n; ++i)
			scanf("%I64d", &a[i]);
		printf("Case %d: %I64d\n", ++cas, CRT());
	}
	return 0;
}

/*poj 2115
  题意：
  给出a,b,c,k,求x,使得(a+c*x)%(2^k)=b
  限制：
  0 <= a,b,c < 2^k; 1 <= k <= 32
  思路：
  拓展欧几里得单变元模线性方程
  令 A=c;C=((b-a)%(2^k)+2^k)%(2^k);B=2^k
  则这道题就化为Ax%n=B

  对于Ax%B=C
  -> Ax+By=C
  -> d=Ext_gcd(A,B,x,y)	//d其实为gcd(A,B)
  -> if(C%d!=0) 无解 else 有解
  -> x=(x*(C/d)%(B/d)+(B/d))%(B/d)	------1式	//为最小自然数解(最小为0)

  现在推导1式：
  对Ax%B=C 即: Ax+By=C
  d=gcd(A,B),则存在一个x1,y(可以由拓展欧几里得求出)使得 d=Ax1+By ---2式
  由"2式"两边同时模B得：d%B=Ax1%B ---3式
  又因为：C%d==0
  所以(B/d)为整数
  所以由"3式"得：C%B=(C/d)*d%B  =  (C/d)*Ax1%B=A(x1*C/d)%B
  即：C%B=A(x1*C/d)%B
  所以x=x1*(C/d)是一个整数解
  又Ax%B=C -> (A/d)x%(B/d)=C/d -> 可以看出解集为x+k*(B/d) (k=整数)
  所以最小整数解x0 = (x%(B/d)+(B/d))%(B/d) = (x1*(C/d)%(B/d)+(B/d))%(B/d)
 */
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define LL __int64
LL Ext_gcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) { x = 1, y = 0; return a; }
	LL ret = Ext_gcd(b, a % b, y, x);
	y -= a / b * x;
	return ret;
}
//ax%n=b,求出%n范围内得到所有解,这道题用不上
vector<LL> line_mod_equ(LL a, LL b, LL n) {
	LL x, y;
	LL d = Ext_gcd(a, n, x, y);
	vector<LL> ans;
	ans.clear();
	if (b % d == 0) {
		x = (x % n + n) % n;
		ans.push_back(x * (b / d) % (n / d));
		for (LL i = 1; i < d; ++i)
			ans.push_back((ans[0] + i * n / d) % n);
	}
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return ans;
}
int main() {
	LL a, b, c, k;
	while (scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &k) && (a || b || c || k)) {
		k = (1LL << k);
		a = ((b - a) % k + k) % k;
		LL x, y;
		LL d = Ext_gcd(c, k, x, y);
		if (a % d) puts("FOREVER");
		else {
			x = (a / d * x % (k / d) + (k / d)) % (k / d);
			//line_mod_equ(c,a,k);
			printf("%I64d\n", x);
		}
	}
	return 0;
}

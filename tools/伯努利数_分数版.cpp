/*poj 1707
  题意：
  令自然数幂和为S(k,n)=1^k+2^k+...+n^k
  S(k,n)可以表述成：
  S(k,n)=1/M*(a[k+1]*n^(k+1)+a[k]*n^k+...+a[1]*n+a[0])
  给出k，求最小的正整数M，使得a[0]...a[k+1]都为整数。
  限制：
  1 <= k <=20
  题解：
  伯努利数
  S(k,n)=1/(k+1) * ( C(k+1,k)*B[k]*(n+1)^1 + C(k+1,k-1)*B[k-1]*(n+1)^2 + ... + C(k+1,0)*B[0]*(n+1)^(k+1) )
  又因为：
  S(k,n)=S(k,n-1) + n^k
		=1/(k+1) * ( C(k+1,k)*B[k]*n^1 + C(k+1,k-1)*B[k-1]*n^2 + ... + C(k+1,0)*B[0]*n^(k+1) ) + n^k
  求一下a[0]...a[k+1]分母的最小公倍数，然后化简即可。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
const int N = 25;
struct FS {
	LL x, y;
	FS() {}
	FS(LL _x, LL _y) {
		x = _x;
		y = _y;
	}
	FS hj() {
		LL div = __gcd(x, y);
		x /= div;
		y /= div;
	}
	FS operator + (const FS &tmp) {
		LL fz = x * tmp.y + tmp.x * y,
		   fm = y * tmp.y;
		if (fz == 0) return FS(0, 1);
		LL div = __gcd(fz, fm);
		return FS(fz / div, fm / div);
	}
} B[N], a[N];
LL C[N][N];
void init() {
	for (int i = 0; i < N; ++i)
		C[i][0] = C[i][i] = 1;
	for (int i = 2; i < N; ++i)
		for (int j = 1; j < N; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	B[0] = FS(1, 1);
	for (int i = 1; i < N; ++i) {
		FS tmp = FS(0, 1), add;
		for (int j = 0; j < i; ++j) {
			add = B[j];
			add.x *= C[i + 1][j];
			tmp = tmp + add;
		}
		if (tmp.x) tmp.y *= -(i + 1);
		tmp.hj();
		B[i] = tmp;
	}
}
int main() {
	init();
	//for(int i=0;i<10;++i){
	//	cout<<B[i].x<<' '<<B[i].y<<endl;
	//}
	int k;
	scanf("%d", &k);
	LL M = k + 1;
	LL gcd = 0, lcm;
	a[0] = FS(0, 1);
	for (int i = 1; i <= k + 1; ++i) {
		if (B[k + 1 - i].x == 0) { a[i] = FS(0, 1); continue; }
		FS tmp = B[k + 1 - i];
		tmp.x *= C[k + 1][i];
		tmp.hj();
		if (gcd == 0) lcm = gcd = tmp.y;
		a[i] = tmp;
	}
	a[k] = a[k] + FS(k + 1, 1);
	//for(int i=1;i<=k+1;++i){
	//	cout<<a[i].x<<' '<<a[i].y<<endl;
	//}
	for (int i = 2; i <= k + 1; ++i) {
		if (a[i].x == 0) continue;
		lcm = lcm * a[i].y / __gcd(lcm, a[i].y);
	}
	//cout<<lcm<<endl;
	if (lcm < 0) lcm = -lcm;
	M *= lcm;
	printf("%d", M);
	for (int i = k + 1; i >= 0; --i) {
		printf(" %d", a[i].x * lcm / a[i].y);
	}
	puts("");
	return 0;
}

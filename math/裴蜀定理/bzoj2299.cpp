/*bzoj 2299
  题意：
  给你一对数a,b，你可以任意使用(a,b), (a,-b), (-a,b), (-a,-b), (b,a), (b,-a), (-b,a), (-b,-a)这些向量，问你能不能拼出另一个向量(x,y)。
  限制：
  -2*1e9 <= a,b,x,y <= 2*1e9
  思路：
  题目的操作可以化为：
  1. x +- 2a;
  2. y +- 2a;
  3. x +- 2b;
  4. y +- 2b;
  5. x + a && y + b;
  6. x + b && y + a;
  7. x + a + b  && y + a + b;
  其中5，6，7最多执行一次。
  证明：
  原题中(x,y)如果可以拼出来的话，一定是：
  (t1*a + t2*b, t3*a + t4*b)
  t1，t2，t3，t4的奇偶性决定5，6，7的执行次数。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
bool ok(LL x,LL y,LL d){
	if(x%d==0 && y%d==0) return true;
	return false;
}
int main(){
	LL a,b,x,y;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
		LL d=__gcd(2*a,2*b);
		if(ok(x,y,d) || ok(x+a,y+b,d) || ok(x+b,y+a,d) || ok(x+a+b,y+a+b,d)) puts("Y");
		else puts("N");
	}
	return 0;
}

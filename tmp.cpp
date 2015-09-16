/*--------------------------------------------
 * File Name: EX
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-04 14:22:48
 --------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
//解方程ax+by=gcd(a,b) 返回gcd(a,b) 得到一组特解(x,y)
LL extend_Euclid(LL a, LL b, LL &x, LL &y){
	if(b==0){
		x=1; 
			y = 0;
		return a;
	}
	LL r = extend_Euclid(b, a%b, y, x);
	y -= a/b*x;
	return r;
}
#define N 10
//求解ax+by=c 返回0为无解,否则返回gcd(a,b)个解,用X[],Y[]存;
LL X[N], Y[N];

LL equation(LL a, LL b, LL c)
{
	LL x, y;
	LL g = extend_Euclid(a, b, x, y);
	if(c % g)
	  return 0;    //表示无解
	x *= c/g, y *= c/g;
	for(int k = 0;k < g;k++)
	{
		X[k] = (x+b/g*k)%b;
		Y[k] = (c-a*X[k])/b;
	}
	return g;
}

//求解ax=b(mod m) 返回0为无解，否则返回gcd(a,m)个mod m意义下的解,用X[]存
LL mod(LL a, LL b, LL m)
{
	return equation(a, m, b);
}

void eq_set()
{
	LL n, b1, m1, b2, m2, m;
	while(~scanf("%lld", &n))
	{
		scanf("%lld%lld", &m1, &b1);
		n--;
		LL r = 1;
		while(n--)
		{
			scanf("%lld%lld", &m2, &b2);
			if(!r)
			  continue;
			r = equation(m1, m2, b2-b1);
			if(!r)
			  continue;
			b1 += m1*X[0];
			m1 = m1/r*m2;
			b1 = (b1%m1+m1)%m1; 
		}
		if(!r)
		{
			printf("-1\n");
			continue;
		}
		mod(1, b1, m1);
		printf("%lld\n", (X[0]%m1+m1)%m1);
	}
	return;
}

int main()
{
	eq_set();
	return 0;
}

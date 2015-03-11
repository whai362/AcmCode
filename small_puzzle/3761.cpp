/*poj 3761
  题意，求含n个不同元素的排列恰好经过k趟冒泡排序变得有序。问原数组有多少种排列情况

  解法：
  首先，定义一个 f(x)表示在数组中位于元素x左面且大于x的个数。那么，
  1. f(x) = 0 (x = 1,2,...,n)是最终有序的状态
  2. f(x) <= n - x;
  3. 对于每趟冒泡排序，若f(x) != 0，则f(x)--;

  比较好求的是经过不超过k趟冒泡的排列数g(k)
  易知，k趟冒泡达到有序的充要条件是 max f(x) == k
  所以 n - x <= k;即 x >= n -  k时，x可以放在数组的任意位置。
  把元素分为[1,n-k],[n-k+1,n],在n个位置中放好了前n-k个数后，后k个数的方法为k!
  对于前n-k 个数挨个来看，
  首先要是f(1) <= k,则1有k+1个位置可放，放好1后，由于1的位置对f(2)无影响，
  2同样有k+1个位置可放...
  g(k) = (k+1)^(n-k) * k!

  最终结果则为 g(k) - g(k-1) = k! * [(k + 1)^(n - k) - k^(n - k)];
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int MOD=20100713;
const int N=1e6+5;
LL a_b_MOD_c(LL a,LL b,LL mod){
	LL ret = 1;
	a %= mod;
	while(b){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
LL fac[N];
void init(){
	fac[0]=1;
	for(int i=1;i<N;++i)
		fac[i]=fac[i-1]*i%MOD;
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		printf("%I64d\n",fac[k]*(a_b_MOD_c(k+1,n-k,MOD)-a_b_MOD_c(k,n-k,MOD)+MOD)%MOD);
	}
	return 0;
}

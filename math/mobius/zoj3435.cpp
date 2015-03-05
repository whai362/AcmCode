/*zoj 3435
  题意：
  给出3个数a,b,c, 定义一个立方体，这个立方体有a*b*c个点，每个点的坐标都是整数(x,y,z)，求经过坐标(1,1,1)和另外任意一个点(x1,y1,z1)的不同的直线有多少条。
  限制：
  2 <= a,b,c <= 1e6; 有200组数据。
  思路：
  有3种情况：
  1. x1,y1,z1都大于等于2：
  问题就变成求1 <= x <= a-1 && 1 <= y <= b-1 && 1 <= z <= c-1 && gcd(x,y,z)=1的三元组有多少对。
  用莫比乌斯反演来做。
  设f(k)为gcd(x,y,z)=k的三元组(x,y,z)的数目，
  设F(k)为gcd(x,y,z)为k的倍数的三元组(x,y,z)的数目，所以F(k)=floor((a-1)/k)*floor((b-1)/k)*floor((c-1)/k)，然后加上一个分段就可以解决了。
  2. x1,y1,z1中有1个为1
  然后问题就退化成2为的互质问题了，同样可以用莫比乌斯反演来做。
  3. x1,y1,z1中有2个为1
  有3条直线。

  分别考虑好3种情况后加起来即可。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
const int N=1e6+5;
int mu[N];
//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}
int sum[N];
void predo(){
	sum[0]=0;
	for(int i=1;i<N;++i)
		sum[i]=sum[i-1]+mu[i];
}
LL deal(LL a[],int len){
	LL ret=0;
	sort(a,a+len);
	LL last;
	for(int i=1;i<=a[0];i=last+1){
		last=a[0]/(a[0]/i);
		for(int j=1;j<len;++j) last=min(last,a[j]/(a[j]/i));
		LL tmp=sum[last]-sum[i-1];
		for(int j=0;j<len;++j) tmp*=a[j]/i;
		ret+=tmp;
	}
	return ret;
}
LL a[15];
LL gao(LL x,LL y,LL z){
	LL ret=3;
	a[0]=x,a[1]=y,a[2]=z;
	ret+=deal(a,3);
	a[0]=x,a[1]=y;
	ret+=deal(a,2);
	a[0]=y,a[1]=z;
	ret+=deal(a,2);
	a[0]=x,a[1]=z;
	ret+=deal(a,2);
	return ret;
}
int main(){
	getMu();
	//for(int i=1;i<=10;++i) cout<<mu[i]<<' ';
	//cout<<endl;
	predo();
	LL x,y,z;
	while(scanf("%lld%lld%lld",&x,&y,&z)!=EOF){
		printf("%lld\n",gao(x-1,y-1,z-1));
	}
}

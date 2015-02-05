/*cf492d
  题意：
  给出n个询问，玩家1每秒打x枪，玩家2每秒打y枪，每个询问是一个整数a，代表怪物的血量，求最后一枪是谁打的。
  思路：
  设玩家1打了t1秒，玩家2打了t2秒。
  则有：t1*x+t2*y=a;
  设在t秒干掉怪物。
  则有：t=t1 | t=t2;
  则有：t*x+ceil(t*y)=a | ceil(t*x)+t*y=a => t*x+t*y-1<a => t<(a+1)/(x+y) => a/(x+y)<=t<(a+1)/(x+y);
  if(t==t1)
	a/(x+y)<=A/x<(a+1)/(x+y)
  else
	a/(x+y)<=B/y<(a+1)/(x+y);
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define LL __int64
LL x,y,a;
int main(){
	int n;
	scanf("%d%I64d%I64d",&n,&x,&y);
	LL sum=x+y;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		a%=sum;
		LL p1,p2;
		p1=a*x/(x+y);
		if((a*x)%(x+y)!=0) ++p1;
		if(p1*(x+y)>=(a+1)*x) p1=-1;
		p2=a*y/(x+y);
		if((a*y)%(x+y)!=0) ++p2;
		if(p2*(x+y)>=(a+1)*y) p2=-1;
		
		if(p1*y==p2*x || (p1==-1 && p2==-1)) puts("Both");
		else if(p1==-1 || (p2!=-1 && p1*y>p2*x)) puts("Vova");
		else puts("Vanya");
	}
	return 0;
}

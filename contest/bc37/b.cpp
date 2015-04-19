/*hdu 5203 Rikka with wood sticks
  题意：
  勇太有一根长度为n的木棍，这个木棍是由n个长度为1的小木棍拼接而成，当然由于时间放置的久了，一些小木棍已经不牢固了，所以勇太想让六花把这个木棍分成正整数长度的4段，其中有3段要没有不牢固的小木棍，勇太希望这3段木棍的长度和可以最大。同时六花希望在满足勇太要求的情况下让这三根木棍能拼成一个三角形，请问萌萌哒六花有多少种可行的分割方案呢？
  限制：
  1 <= n <= 1e6; 1 <= m <= 1e3
  思路：
  实际上问题会化为：
  1. 给出长度为l1,l2的木棒，把其中一根截成2段，求能组成三角形的方法数。
  2. 长度为l的木棒，截成3段，求能组成三角形的方法数。
  可以由不等式解。
 */
#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
//求长度为l的木棒，截成3段，求能组成三角形的方法数。
LL gao(int l){
	LL ret=0;
	for(int i=1;2*i<l;++i){
		ret+=(l-1)/2-(l/2-i);
	}
	return ret;
}

bool ok(int a,int b,int c){
	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);
	if(a+b>c && b-a<c) return true;
	return false;
}
int main(){
	int n,m;
	int _max,_min;
	while(scanf("%d%d",&n,&m)!=EOF){
		_max=-1;
		_min=n+1;
		int a;
		for(int i=0;i<m;++i){
			scanf("%d",&a);
			_max=max(_max,a);
			_min=min(_min,a);
		}
		int len1=_min-1;
		int len2=n-_max;
		LL ans=0;
		if(len1>len2) swap(len1,len2);
		if(len1==len2){
			puts("0");
			continue;
		}
		else if(len1){
			for(int i=1;i<len2;++i){
				int a=i,b=len2-i;
				if(ok(len1,a,b)) ++ans;
			}
		}
		else{
			ans=gao(len2);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

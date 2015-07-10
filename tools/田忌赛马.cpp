/*poj 2287
  题意：
  田忌赛马 
  如果3匹马变成1000匹，齐王仍然让他的马按从优到劣的顺序出赛，田忌可以按任意顺序选择他的赛马出赛。赢一局，田忌可以得到200两银子，输一局，田忌就要输掉200两银子，平局的话不输不赢。 
  请问田忌最多能赢多少银子?
  思路：
  贪心；
  如果当前最好的马可以胜齐王最好的马，那么让这两匹马比一场；
  如果当前最差的马能胜齐王最差的马，那么让这两匹马比一场；
  如果上面两个条件都不满足，那么让当前最差的马和齐王最好的马比一场。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int a[N],b[N];
void gao(int n){
	int p1=0,p2=0;
	int q1=n-1,q2=n-1;
	int ans=0;
	while(p1<=q1){
		if(a[p1]>b[p2]){
			++p1;
			++p2;
			++ans;
		}
		else if(a[q1]>b[q2]){
			--q1;
			--q2;
			++ans;
		}
		else{
			if(a[p1]!=b[q2])
				--ans;
			++p1;
			--q2;
		}
	}
	printf("%d\n",ans*200);
}
int main(){
	int n;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		for(int i=0;i<n;++i)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		gao(n);
	}
	return 0;
}

/*cf 509C Sums of Digits
  题意：
  给出n个数字各位的加和bi，求一个严格递增的数列。要求最后一个数字最小。
  如：
  3 2 1 -> 3 11 100
  限制：
  1 <= n <= 300; 1 <= bi <=300
  思路：
  贪心，要求最后一个数字最小，只要保证一路过来的数字都尽量小就行。
  令d=b[i]-b[i-1],
  如果d>0，则从最低位填起，尽量把低位填到9
  如果d<=0,则先从低位开始进位，使得d>0，然后就可以转换为第一种情况了。
 */
#include<iostream>
#include<cstdio>
using namespace std;
const int N=505;
int a[N];
int res[N],tot;
void init(){
	tot=0;
}
int trans(int d){
	int pos=0;
	while(res[pos]==9 || d<=0){
		d+=res[pos];
		res[pos]=0;
		++pos;
	}
	++res[pos];
	--d;
	tot=max(tot,pos+1);
	return d;
}
void gao(int d){
	if(d<=0) d=trans(d);
	int pos=0;
	while(d>0){
		if(9-res[pos]<=d){
			d-=9-res[pos];
			res[pos]=9;
		}
		else{
			res[pos]+=d;
			d=0;
		}
		++pos;
	}
	tot=max(tot,pos);
	for(int i=tot-1;i>=0;--i)
		printf("%d",res[i]);
	puts("");
}
int main(){
	int n;
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		gao(a[i]-a[i-1]);
	return 0;
}

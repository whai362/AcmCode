/*codeforces 526 e
  题意：
  给出n个数a1,a2,...,an，这n个数首尾相接形成一个环。
  如：1 2 3
  (1,2) (2,3) (3,1) 相连
  现在再给出q个询问，每个询问为一个b，求把这n个数分成相连的m段，使得每段的和不超过b，求m的最小值。
  限制：
  2 <= n <= 1e6
  1 <= q <= 50
  1 <= ai <= 1e9
  max(ai) <= b <= 1e15
  思路：
  先找出一个最小的段，从最小的段中枚举起点，取最小值即为答案。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=1e6+5;
LL a[N];
LL sum[2*N];
int nxt[N];
int deal(int st,int n){
	int cnt=0;
	int p=st;
	while(p<n){
		++cnt;
		p=nxt[p%n];
	}
	while(p%n<st){
		++cnt;
		p=nxt[p%n];
	}
	return cnt;
}
void gao(LL b,int n){
	int st=0,len=n;

	int p=0,q=0;
	while(p<n){
		while(q<=2*n && sum[q]-sum[p]<=b){
			++q;
		}
		if(q-p-1>n){ puts("1"); return ; }
		else{
			nxt[p]=q-1;
			int tmp=q-p-1;
			if(tmp<len){
				len=tmp;
				st=p;
			}
		}
		++p;
	}
	int ans=n;
	for(int i=st;i<=st+len;++i){
		ans=min(ans,deal(i%n,n));
	}
	printf("%d\n",ans);
}
void In(int &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

void In(LL &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

int main(){
	int n,q;
	In(n);
	In(q);
	for(int i=0;i<n;++i){
		In(a[i]);
	}
	sum[0]=0;
	for(int i=0;i<2*n;++i){
		sum[i+1]=sum[i]+a[i%n];
	}
	LL b;
	for(int i=0;i<q;++i){
		In(b);
		gao(b,n);
	}
	return 0;
}

/*hdu5160
  题意：
  现在要给n个小朋友发苹果。发苹果的时候，小朋友先从左到右随机站成一排。设站好后从左到右小朋友的标号是 p1,p2,p3,...,pn，他们所需要的苹果数目是 Ap1,Ap2,Ap3,...,Apn，对于最左边的人要给他发 Ap1个苹果，对于第i (i>1)个人，如果前面有一个人的苹果要求的数目比他多，那么就不用发给他苹果，否则发给他 Api个苹果。那么对于某一个排列需要多少苹果就可以计算出来了。现在我们想知道对于所有的排列总共要发多少苹果。两个排列不一样当且仅当至少存在一个位置要求的苹果数目不一样。
  限制；
  1 <= n <= 100000
  1 <= Ai <= 1000000000
  思路：
  因为n只有100000，所以对于每个Api如果能O(1)或者O(log(n))算出它被统计了多少次就能解决这个问题。
  现在问题是怎么算出Api被统计了多少次，这是一个组合数学的问题，如：
  现在有一个序列
  下标： 1 2 3 4 5 6 7 8 9 10
  数值： 1 1 1 2 2 3 3 4 4 5
  现在我要算下标为6的数值3被统计了多少次：
  C(10,3)*C(7,2) * C(4,1)*C(3,2)*C(1,1)
  统计前面的       统计后面的(3445)的排
  (11122)的排列    列情况
  情况
  同理，计算下标为7的数值3被统计了多少次：
  C(10,3)*C(7,2) * C(3,2)*C(1,1)
  统计前面的       统计后面的(445)
  (11122)的排列    的排列情况
  情况

  然后我们可以发现前面和后面的排列情况可以预处理出来，然后我们后面就可以O(1)得到Api被统计了多少次。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define LL __int64
const int N=100005;
const int MOD=1000000007;
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
	if(b==0) { x=1, y=0; return a; }
	LL ret= Ext_gcd(b,a%b,y,x);
	y-= a/b*x;
	return ret;
}

LL Inv(LL a,int m){ //求逆元
	LL d,x,y,t= (LL)m;
	d= Ext_gcd(a,t,x,y);
	if(d==1) return (x%t+t)%t;
	return -1;
}

LL Cm(LL n, LL m, LL p){ //求组合数
	LL a=1, b=1;
	if(m>n) return 0;
	while(m){
		a=(a*n)%p;
		b=(b*m)%p;
		m--;
		n--;
	}
	return (LL)a*Inv(b,p)%p;
}
struct Dt{
	LL x;
	int cnt;
	Dt(){}
	Dt(LL _x,int _c){
		x=_x;
		cnt=_c;
	}
};
LL a[N],fro[N],bac[N];
int main(){
	int T;
	int n,cas=0;
	scanf("%d",&T);
	while(T--){
		memset(fro,0,sizeof(fro));
		memset(bac,0,sizeof(bac));
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%I64d",&a[i]);
		sort(a,a+n);

		int len=n,cnt=1;
		fro[0]=1;
		for(int i=1;i<n;++i){
			if(a[i]==a[i-1]){
				++cnt;
				fro[i]=fro[i-1];
			}
			else{
				fro[i]=fro[i-1]*Cm(len,cnt,MOD)%MOD;
				len-=cnt;
				cnt=1;
			}
		}

		LL pre=1,cnm=1;
		len=cnt=1;
		bac[n-1]=1;
		for(int i=n-2;i>=0;--i){
			++len;
			if(a[i]==a[i+1]){
				++cnt;
				cnm=cnm*len%MOD*Inv(cnt,MOD)%MOD;	//cnm*len要MOD,否则会乘爆long long
				bac[i]=pre*cnm%MOD;
			}
			else{
				cnt=1;
				cnm=len;
				pre=bac[i+1];
				bac[i]=pre*cnm%MOD;
			}
		}
		bac[n]=1;
		LL ans=0;

		for(int i=0;i<n;++i){
			ans=(ans+(fro[i]*bac[i+1]%MOD*a[i]%MOD))%MOD;
		}
		printf("Case #%d: %I64d\n",++cas,ans);
	}
	return 0;
}

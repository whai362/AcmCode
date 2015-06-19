/*bzoj 2186 [Sdoi2008]沙拉公主的困惑
  题意：
  大富翁国因为通货膨胀，以及假钞泛滥，政府决定推出一项新的政策：现有钞票编号范围为1到N的阶乘，但是，政府只发行编号与M!互质的钞票。房地产第一大户沙拉公主决定预测一下大富翁国现在所有真钞票的数量。现在，请你帮助沙拉公主解决这个问题，由于可能张数非常大，你只需计算出对R取模后的答案即可。R是一个质数。
  限制：
  数据组数T：1 <= T <= 10000
  R <= 1e9+10
  1 <= N,M <=10000000
  思路：
  首先答案为：
  phi(m!)*n!/m!
  证明过程如下：
  gcd(a,b)=1 <=> gcd(a+b,b)=1
  phi(m!)表示小于m!且与m!互质的数的个数，
  不妨令它们为p[1],p[2],p[3],...,p[k]，则有gcd(p[i],m!)=1，其中1 <= i <= k，
  则有gcd(p[i]+m!,m!)=1，
  所以最后答案为phi(m!)*n!/m!

  然后问题落在phi(m!)的求法上面，
  对于欧拉函数有公式：
  phi(x)=x * (p[1] - 1)/p[1] * (p[2] - 1)/p[2] * ... * (p[k] - 1)/p[k]，其中p[i] (1 <= i <= k) 为x的质因子
  所以，求一遍m!的质因子即可，即为1~m内的素数。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
const int N=1e7+5;
LL fac[N];

LL ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

//要求a与m互质
LL inv(LL a,int m){   //求逆元
    LL d,x,y,t= (LL)m;
    d= ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

bool is_pri[N];
//int pri[N], tot;
void get_pri(int n){
	//tot = 0;
	memset(is_pri, 1, sizeof(is_pri));
	is_pri[0] = is_pri[1] = 0;
	for(int i = 2; i <= n; ++i)
		if(is_pri[i]){
			if(n / i < i) break;
			for(int j = i * i; j <= n; j += i) is_pri[j] = false;
		}
	//for(int i = 2; i <= n; ++i) if(is_pri[i]) pri[tot++] = i;
}

LL ans[N];

void predo(int mod){
	fac[0]=1;
	for(int i=1;i<N;++i){
		fac[i]=fac[i-1]*i%mod;
	}
	get_pri(N-1);
	ans[0]=1;
	for(int i=1;i<N;++i){
		ans[i]=ans[i-1];
		if(is_pri[i]) ans[i]=ans[i]*(i-1)%mod*inv(i,mod)%mod;
	}
}

void gao(int n,int m,int mod){
	printf("%lld\n",ans[m]*fac[n]%mod);
}

int main(){
	int T,R;
	scanf("%d%d",&T,&R);
	predo(R);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		gao(n,m,R);
	}
	return 0;
}

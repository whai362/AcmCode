/*快速计算C(n,m) % p^q (n,m的范围为1e18)
  做法证明详见卡特兰数1e18
  测试数据
  Q=18
  P=5
  100000000000000 1000000000
  2841818259375
  1231235345123746 12312612135656
  460885977500
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
#define LL __int64
using namespace std;
const LL MOD=3814697265625LL; //5^18
const int Q=18;
const int P=5;
//const LL MOD=33232930569601LL; //7^16
//const int Q=16;
//const int P=7;
LL mul(LL a,LL b,LL m){
    LL ret = 0;
    a %= m;
    while(b){
        if(b & 1) ret = (ret + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return ret;
}
LL a_b_MOD_c(LL a,LL b,LL m){
    LL ret = 1;
    a %= m;
    while(b){
        if(b&1) ret = mul(ret,a,m);
        a = mul(a,a,m);
        b >>= 1;
    }
    return ret;
}
struct Po{	//多项式类
	int len;
	LL a[Q+2];
	Po(){
		len=0;
		memset(a,0,sizeof(a));
	}
	void print(){
		for(int i=0;i<=len;++i)
			cout<<a[i]<<' ';
		cout<<endl;
	}
};


Po ret,part1,part2;
LL C[Q+2][Q+2];
LL a[Q+2];
Po g(LL n,int p,int q){
	if(n<=p){
		ret.len=1;
		ret.a[0]=1;
		ret.a[1]=1;
		for(int i=2;i<=n;++i){
			if(i%p==0) continue;
			a[0]=0;
			for(int j=0;j<=ret.len;++j){
				a[j+1]=ret.a[j];
				ret.a[j]=(a[j]+mul(ret.a[j],i,MOD))%MOD;
			}
			if(ret.len<q){
				++ret.len;
				ret.a[ret.len]=a[ret.len];
			}
		}
		return ret;
	}
	LL k=(n+1)/(2*p);
	part1=g(p*k-1,p,q);
	part2=Po();
	part2.len=part1.len;
	part2.a[0]=part1.a[0];

	LL tmp[Q+2];
	tmp[0]=1;
	for(int i=1;i<=part2.len;++i)
	   tmp[i]=mul(tmp[i-1],p*k,MOD);	
	for(int i=1;i<=part2.len;++i){
		for(int j=0;j<=i;++j){
			part2.a[j]=(part2.a[j]+mul(mul(C[i][j],tmp[i-j],MOD),part1.a[i],MOD))%MOD;	//
		}
	}
	ret=Po();
	for(int i=0;i<=part1.len;++i){
		for(int j=0;j<=part2.len;++j){
			if(i+j>q) break;
			ret.a[i+j]=(ret.a[i+j]+mul(part1.a[i],part2.a[j],MOD))%MOD;
		}
	}
	
	ret.len=min(part1.len+part2.len,q);
	for(LL i=2*p*k+1;i<=n;++i){
		if(i%p==0) continue;
		a[0]=0;
		for(int j=0;j<=ret.len;++j){
			a[j+1]=ret.a[j];
			ret.a[j]=(a[j]+mul(ret.a[j],i,MOD))%MOD;
		}
		if(ret.len<q){
			++ret.len;
			ret.a[ret.len]=a[ret.len];
		}
	}
	return ret;
}
LL f(LL n,int p,int q){
	LL ret=1;
	for(LL i=n;i>0;i/=p){
		ret=mul(ret,g(i,P,Q).a[0],MOD);
	}
	return ret;
}
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}
void predo(){
	for(int i=0;i<=Q;++i)
		C[i][0]=C[i][i]=1;
	for(int i=2;i<=Q;++i)
		for(int j=1;j<i;++j)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
}
LL Cm(LL n,LL m,int p,int q){
    if(m<0 || m>n || n<0) return 0;
    LL t=n-m;
    int cnt=0;
    for(LL i=n/p;i>0;i/=p) cnt+=i;
    for(LL i=m/p;i>0;i/=p) cnt-=i;
    for(LL i=t/p;i>0;i/=p) cnt-=i;
    LL ret=mul(mul(f(n,P,Q),inv(f(m,P,Q),MOD),MOD),inv(f(t,P,Q),MOD),MOD);
    ret=mul(ret,a_b_MOD_c(p,cnt,MOD),MOD);
    return ret;
}
int main(){
	predo();
	LL n,m;
	while(cin>>n>>m){
		cout<<Cm(n,m,P,Q)<<endl;
	}
	return 0;
}

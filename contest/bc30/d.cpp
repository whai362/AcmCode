#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#define LL __int64
using namespace std;
const LL MOD=3814697265625LL;
struct Polynomial{
	int len;
	LL a[20];
	Polynomial(){
		len=0;
		memset(a,0,sizeof(a));
	}
	void print(){
		for(int i=0;i<=len;++i)
			cout<<a[i]<<' ';
		cout<<endl;
	}
};
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

//LL fac[20];
//LL Cm(int n,int m){
//	return fac[n]/fac[m]/fac[n-m];
//}
LL Cm[20][20];
Polynomial ret,part1,part2;
LL a[20];
LL t[20];
Polynomial g(LL n,int p,int q){
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
	part2=Polynomial();
	part2.len=part1.len;
	part2.a[0]=part1.a[0];
	t[0]=1;
	for(int i=1;i<=part2.len;++i)
	   t[i]=mul(t[i-1],p*k,MOD);	
	for(int i=1;i<=part2.len;++i){
		for(int j=0;j<=i;++j){
			part2.a[j]=(part2.a[j]+mul(mul(Cm[i][j],t[i-j],MOD),part1.a[i],MOD))%MOD;	//
		}
	}
	ret=Polynomial();
	for(int i=0;i<=part1.len;++i){
		for(int j=0;j<=part2.len;++j){
			if(i+j>q) break;
			ret.a[i+j]=(ret.a[i+j]+mul(part1.a[i],part2.a[j],MOD))%MOD;
		}
	}
	
	ret.len=min(2*part1.len,q);
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
		ret=mul(ret,g(i,5,18).a[0],MOD);
	}
	return ret;
}
LL ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}
LL inv(LL a,LL m){
	//LL p=1,q=0,b=m,c,d;
	//while(b>0){
	//	c=a/b;
	//	d=a; a=b; b=d%b;
	//	d=p; p=q; q=d-c*q;
	//}
	//return p<0?p+m:p;
    LL d,x,y,t=m;
    d= ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}
LL C(LL n,LL m,int p,int q){
	if(m<0 || m>n || n<0) return 0;
	//LL t=n-m;
	int cnt=0;
	for(LL i=n/p;i>0;i/=p) cnt+=i;
	for(LL i=m/p;i>0;i/=p) cnt-=2*i;
	LL t1=m+1;
	while(t1%5==0){
		t1/=5;
		--cnt;
	}
	t1=inv(t1,MOD);
	//for(LL i=t/p;i>0;i/=p) cnt-=i;
	LL t2=inv(f(m,5,18),MOD);
	//LL ret=mul(mul(f(n,5,18),inv(f(m,5,18),MOD),MOD),inv(f(t,5,18),MOD),MOD);
	LL ret=mul(mul(mul(f(n,5,18),t2,MOD),t2,MOD),t1,MOD);
	ret=mul(ret,a_b_MOD_c(p,cnt,MOD),MOD);
	return ret;
}
void predo(){
	//fac[0]=fac[1]=1;
	//for(int i=2;i<=18;++i){
	//	fac[i]=fac[i-1]*i;
	//}
	for(int i=0;i<=18;++i)
		Cm[i][0]=Cm[i][i]=1;
	for(int i=2;i<=18;++i)
		for(int j=1;j<i;++j)
			Cm[i][j]=Cm[i-1][j]+Cm[i-1][j-1];
}
int main(){
	//double start=clock(),end;
	int T;
	LL n;
	int cas=0;
	predo();
	scanf("%d",&T);
	while(T--){
		scanf("%I64d",&n);
		printf("Case #%d: ",++cas);
		//LL ans=(C(2*n,n,5,18)-C(2*n,n-1,5,18)+MOD)%MOD;
		LL ans=C(2*n,n,5,18);
		cout<<ans<<endl;
	}
	//end=clock();
	//cerr<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
	return 0;
}

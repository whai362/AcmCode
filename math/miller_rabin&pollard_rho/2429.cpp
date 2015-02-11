#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define LL unsigned __int64
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
LL a_b_MOD_c(LL a, LL b, LL m){
	LL ret = 1;
	a %= m;
	while(b){
		if(b & 1) ret = mul(ret, a, m);
		a = mul(a, a, m);
		b >>= 1;
	}
	return ret;
}
bool test(LL n, LL a, LL d){
	if(n == 2) return true;
	if(n == a) return true;
	if((n & 1) == 0) return false;
	while(!(d & 1)) d = d >> 1;
	LL t = a_b_MOD_c(a, d, n);
	while((d != n-1) && (t != 1) && (t != n-1)){
		t = mul(t, t, n);
		d = d << 1;
	}
	return (t == n-1 || (d & 1) == 1);
}
//要注意1的情况
const int Times=20;
bool Miller_Rabin(LL n){
	if(n < 2) return false;
	for(int i = 0; i <= Times; ++i){
		LL a=rand()%(n-1)+1;
		if(!test(n, a, n-1)) return false;
	}
	return true;
}
LL pollard_rho(LL n,LL c){
	LL i=1,k=2;
	LL x=rand()%(n-1)+1;
	LL y=x;
	while(1){
		++i;
		x=(mul(x,x,n)+c)%n;
		LL d=__gcd((y-x+n)%n,n);
		if(1<d && d<n) return d;
		if(y==x) return n;
		if(i==k){
			y=x;
			k<<=1;
		}
	}
}
//要注意1的情况
//LL ans;
LL fac[105];
int tot;
void find_fac(LL n,int c){
	if(n==1) return ;
	if(Miller_Rabin(n)){
		//ans=min(ans,n);
		fac[tot++]=n;
		return ;
	}
	LL p=n;
	LL k=c;
	while(p>=n) p=pollard_rho(p,c--);
	find_fac(p,k);
	find_fac(n/p,k);
}
void init(){
	//ans=n;
	tot=0;
}
void gao(LL m,LL n){
	LL ans_x,ans_y,_min=-1;
	int lim=(1<<tot);
	//cout<<tot<<endl;
	//for(int i=0;i<tot;++i){
	//	cout<<fac[i]<<' ';
	//}
	//cout<<endl;
	for(int i=1;i<lim;++i){
		int tmp=i,p=0;
		LL x=1,y;
		while(tmp){
			if(tmp&1) x*=fac[p];
			++p;
			tmp>>=1;
		}
		y=n/x;
		if(__gcd(x,y)==1 && (_min==-1 || _min>=x+y)){ _min=x+y; ans_x=x; ans_y=y; }
	}
	if(ans_x>ans_y) swap(ans_x,ans_y);
	printf("%I64d %I64d\n",m*ans_x,m*ans_y);
}
int main(){
	LL a,b;
	srand(12345);
	//cout<<__gcd(15728640LL,12884901888LL)<<endl;
	//cout<<67553994410557440LL/3<<endl;
	while(scanf("%I64d%I64d",&a,&b)!=EOF){
		if(a==b){ printf("%I64d %I64d\n",a,b); continue; }
		init();
		b/=a;
		find_fac(b,12345);
		gao(a,b);
	}
	return 0;
}


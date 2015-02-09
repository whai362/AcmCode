#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL __int64
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
bool isPrime(LL n){
	if(n < 2) return false;
	LL a[] = {2, 3, 61};
	for(int i = 0; i <= 2; ++i)
		if(!test(n, a[i], n-1)) return false;
	return true;
}

const int N = 1000005;
const int LIM = (1<<16)+5;
bool is_pri[N];
int pri[N],tot;
void predo(){
	tot=0;
	memset(is_pri,1,sizeof(bool)*LIM);
	is_pri[0]=is_pri[1]=0;
	for(int i=2;i<LIM;++i){
		if(is_pri[i]){
			if(LIM/i<i) break;
			for(LL j=i*i;j<LIM;j+=i) is_pri[j]=0;
		}
	}
	for(int i=2;i<=LIM;++i) if(is_pri[i]) pri[tot++]=i;
}
bool ans[N];
bool gao(LL l, LL r){
	memset(ans,1,sizeof(bool)*(r-l+1));
	if(l==1){ ans[0]=0; }
	for(int i=0;i<tot;++i){
		LL t=(LL)pri[i];
		if(r/t<t) break;
		for(LL j=t*max(t,(l+t-1)/t);j<=r;j+=t){	
			ans[j-l]=0;
		}
	}
	LL l1, r1, l2, r2;
	int _max = 0, _min = 0x3f3f3f3f;
	int pre = 0;
	while(!ans[pre] && pre <= r - l) ++pre;
	for(int i = pre+1; i <= r - l; ++i){
		if(ans[i]){
			//cout<<l+i<<endl;
			int tmp = i - pre;
			if(tmp > _max){ _max = max(_max, tmp); l1 = pre; r1 = i;}
			if(tmp < _min){ _min = min(_min, tmp); l2 = pre; r2 = i;}
			pre = i;
		}
	}
	if(_max == 0) puts("There are no adjacent primes.");
	else printf("%I64d,%I64d are closest, %I64d,%I64d are most distant.\n", l2 + l, r2 + l, l1 + l, r1 + l);
}
bool jg(LL n){
	int lim=sqrt(n);
	for(int i=2;i<=lim;++i){
		if(n%i==0){
			cout<<i<<endl;
			return 0;
		}
	}
	return 1;
}
int main(){
	LL l, r;
	//cout<<(1LL<<31)<<endl;
	//cout<<LIM<<endl;
	//cout<<jg(2147483381)<<endl;
	//cout<<jg(2147483383)<<endl;
	predo();
	while(scanf("%I64d%I64d", &l, &r) != EOF)
		gao(l, r);
	return 0;
}

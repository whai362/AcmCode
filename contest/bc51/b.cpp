#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
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
const int Times=3;
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
//小心1的情况
LL get_phi(LL x){
    init();
    find_fac(x,12345);
    LL ret=x;
    for(int i=0;i<tot;++i){
        ret = ret / fac[i] * (fac[i] - 1);
    }
    return ret;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        LL k, b, x, p;
        LL ans;
        scanf("%I64d%I64d%I64d%I64d", &k, &b, &x, &p);
        if(k == 0) {
            LL tmp = (x * k + b) % p;
            if(x == tmp) puts("1");
            else puts("-1");
        } else if(k == 1) {
            if(b == 0) {
                puts("1");
            } else {
                if(p % b == 0) {
                    ans = p / b;
                    printf("%I64d\n", ans);
                } else {
                    puts("-1");
                }
            }
        } else {
            LL A = k;
            LL B = p * (k - 1);
            B = B / __gcd((x * (k - 1) + b), B);
            if(__gcd(A, B) != 1) puts("-1");
            else {
                LL phi = get_phi(B);
                LL ans = phi;
                for(LL i = 1; i * i <= phi; ++i) {
                    if(phi % i == 0) {
                        if(a_b_MOD_c(A, i, B) == 1)
                            ans = min((LL)i, ans);
                        else if(a_b_MOD_c(A, phi / i, B) == 1) {
                            ans = min(phi / i, ans);
                        }
                    }
                }
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}

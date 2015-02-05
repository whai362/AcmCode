#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <map>
#include <vector>

using namespace std;
typedef __int64 LL;

LL ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}
LL a_b_MOD_c(LL a,LL b,LL mod){
    LL ret = 1;
    a %= mod;
    while(b){
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
LL multi(LL a,LL b,LL m)
{
    LL ans = 0;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = (ans + a) % m;
            b--;
        }
        b >>= 1;
        a = (a + a) % m;
    }
    return ans;
}

LL quick_mod(LL a,LL b,LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b&1)
        {
            ans = multi(ans,a,m);
            b--;
        }
        b >>= 1;
        a = multi(a,a,m);
    }
    return ans;
}


const int N = 1000005;

/**以下为求原根部分 */
bitset<N> prime;
int p[N],pri[N];
int k,cnt;

void isprime()
{
    prime.set();
    for(int i=2; i<N; i++)
    {
        if(prime[i])
        {
            p[k++] = i;
            for(int j=i+i; j<N; j+=i)
                prime[j] = false;
        }
    }
}

vector<LL> a;
bool g_test(LL g,LL p){
    for(LL i=0;i<a.size();++i)
        if(quick_mod(g,(p-1)/a[i],p)==1)
            return 0;
    return 1;
}
LL pri_root(LL p){
    a.clear();
    LL tmp=p-1;
    for(LL i=2;i<=tmp/i;++i)
        if(tmp%i==0){
            a.push_back(i);
            while(tmp%i==0)
                tmp/=i;
        }
    if(tmp!=1)
        a.push_back(tmp);
    LL g=1;
    while(true){
        if(g_test(g,p))
            return g;
        ++g;
    }
}
/**以上为求原根部分 */

/** 以下为Baby_Step */

LL gcd(LL a,LL b)
{
    return b ? gcd(b,a%b):a;
}

const int HASH_MOD=9876543;
LL key[HASH_MOD], val[HASH_MOD];
int head[HASH_MOD], next[HASH_MOD];
struct Hash{
    int tot;
    void init(){
        memset(head, -1, sizeof(head));
        tot = 0;
    }
    LL insert(LL x, LL y){
        int k = x % HASH_MOD;
        key[tot] = x;
        val[tot] = y;
        next[tot] = head[k];
        head[k] = tot++;
    }
    LL find(LL x){
        int k = x % HASH_MOD;
        for(int i = head[k]; i != -1; i = next[i])
            if(key[i] == x)
                return val[i];
        return -1;
    }
}hs;
//求解模方程a^x=b(mod m),n为素数,无解返回-1  
//注意：要求0 <= a < m; 0 <= b < m; 否则按题意自己转化。
//复杂度O(sqrt(m))
LL log_mod(LL a, LL b, LL m){
    hs.init();
    LL s = ceil(sqrt(m));
    LL cur = 1;
    for (int i = 0; i < s; ++i){
        if(hs.find(cur)==-1) hs.insert(cur,i);    //记得先判重，在插入
        cur = cur * a % m;
    }
    LL v = quick_mod(a, (m - s - 1 + m) % m, m);	//bug
    for(int i = 0; i < s; ++i){
        LL tmp = hs.find(b);
        if(tmp!=-1)
            return s * i + tmp;
        b=b*v%m;
    }
    return -1;
}
/** 以上为Baby_Step */

LL ans[1005];

void Work(LL A,LL B,LL C)
{
    LL root = pri_root(C);
	//cout<<"r "<<root<<endl;
    root%=C;	//bug
	//cout<<root<<' '<<B<<' '<<C<<endl;
	LL t1 = log_mod(root,B,C);
    LL t2 = C - 1;
    LL d = gcd(A,t2);
    if(t1 % d)
    {
        puts("-1");
        return;
    }
    LL x,y;
    ext_gcd(A,t2,x,y);
    t2 /= d;
    t1 /= d;
    ans[0] = (x * t1 % t2 + t2) % t2;
    for(int i=1; i<d; i++)
        ans[i] = ans[i-1] + t2;
    for(int i=0; i<d; i++)
        ans[i] = quick_mod(root,ans[i],C);
    sort(ans,ans+d);
    for(int i=0; i<d; i++)
        cout<<ans[i]<<endl;
}

int main()
{
    int T = 1;
    LL A,B,C;
    isprime();
    while(cin>>A>>C>>B)
    {
        printf("case%d:\n",T++);
        Work(A,B,C);
    }
    return 0;
}


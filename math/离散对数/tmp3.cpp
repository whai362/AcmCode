#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL __int64

const int HASH_MOD=99991;
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
LL ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

//(A^x)%C=B
//a*x+Cy=B
LL ext_log_mod(LL A,LL B,LL C){
    
    hs.init();
    LL a = 1;
    LL d, cnt = 0;
    while((d = __gcd(A,C)) != 1){
        if(B % d) return -1;
        B /= d;
        C /= d;
        a = a * (A / d) % C;
        ++cnt;
    }
    LL s = ceil(sqrt(C*1.0));
    LL cur = 1;
    for(int i = 0; i < s; ++i){
        if(hs.find(cur)==-1) hs.insert(cur, i);    //记得先判重，在插入
        cur = cur * A % C;
    }
    for(int i = 0; i < s; ++i){
        LL x, y;
        d = ext_gcd(a, C, x, y);
        //x = (x * (B / d) % (C / d) + (C / d)) % (C / d);
        x = x * B % C;
        x = (x % C + C) % C;
        LL fd = hs.find(x);
        if(fd != -1) return i * s + fd + cnt;
        a = a * cur % C;    //
    }
    return -1;
}

LL Baby_Step(LL A,LL B,LL C)
{
    LL ret = 1;
    for(int i=0; i<=50; i++)
    {
        if(ret == B) return i;
        ret = ret * A % C;
    }
    hs.init();
    LL ans = 1;
    LL tmp,cnt = 0;
    while((tmp = __gcd(A,C)) != 1)
    {
        if(B % tmp) return -1;
        B /= tmp;
        C /= tmp;
        ans = ans * (A / tmp) % C;
        cnt++;
    }
    LL M = ceil(sqrt(1.0*C));
    LL t = 1;
    for(int i=0; i<M; i++)
    {
        if(hs.find(t) ==-1) hs.insert(t,i);
        t = t * A % C;
    }
    for(int i=0; i<M; i++)
    {
        LL x,y;
        ext_gcd(ans,C,x,y);
        LL val = x * B % C;
        val = (val % C + C) % C;
        LL j = hs.find(val);
        if(j != -1) return i * M + j + cnt;
        ans = ans * t % C;
    }
    return -1;
}


int main(){
    LL A, B, C;
    while(scanf("%I64d%I64d%I64d", &A, &C, &B) != EOF){
        A %= C;    //记得这些细节
		if(B >= C){
			puts("Orz,I can’t find D!");
			continue;
		}
        LL ans = Baby_Step(A,B,C);
        if(ans == -1)
            puts("Orz,I can’t find D!");
        else
            printf("%I64d\n",ans);
    }
    return 0;
}

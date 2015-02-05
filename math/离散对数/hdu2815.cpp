/*hdu 2815
  题意：
  给出K,P,N, 求最小的D使得：K^D == N(MOD P)
  限制：
  1 <= K,P,N <= 1e9; 注意P不一定是素数。
  思路：
  离散对数
  因为, P不一定是素数, 所以用拓展giant-step baby-step解决。

  拓展giant-step baby-step思路：
  当为P合数时，我们就需要把Baby-Step Giant-Step扩展一下。在普通Baby-Step Giant-Step中，由于是素数，那么，所以一定有唯一解的。那么，当为合数时，我们可以这样处理：
  对于方程：A^x + Cy = B, 我们拿出若干A出来与C来小区公共因子，使(A, C) = 1为止, 然后可以得到类似这样的式子：a * A^x' + C'y = B, 然后用拓展欧几里得计算结果，其余部分与普通giant-step baby-step相似。

  注意：
  假设消因子过程做了cnt次，最后的答案ans为, 如果ans < cnt的话，会有问题，因为由上面过程算出来的答案是最后加上cnt的，所以会有错。所以还要加上一步，从先从 0 到 50 枚举答案，找不到答案，再执行上面的过程。因为P < 1e9, 每次消因子最少消2，所以cnt < 50。
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL __int64

const int HASH_MOD=76543;
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
//注意0 < A < C; 0 <= B < C
//a*x+Cy=B
LL ext_log_mod(LL A,LL B,LL C){
	LL ret = 1;
    for(int i=0; i<=50; i++){
        if(ret == B) return i;
        ret = ret * A % C;
    }

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
		if(hs.find(cur)==-1) hs.insert(cur, i);	//记得先判重，再插入
		cur = cur * A % C;
	}
	for(int i = 0; i < s; ++i){
		LL x, y;
		d = ext_gcd(a, C, x, y);
		x = (x * (B / d) % (C / d) + (C / d)) % (C / d);
		LL fd = hs.find(x);
		if(fd != -1) return i * s + fd + cnt;
		a = a * cur % C;	//
	}
	return -1;
}

int main(){
	LL A, B, C;
	while(scanf("%I64d%I64d%I64d", &A, &C, &B) != EOF){
		A %= C;	//记得这些细节
		//B %= C;
		if(B >= C){
			puts("Orz,I can’t find D!");
			continue;
		}
		LL ans = ext_log_mod(A,B,C);
		if(ans == -1)
			puts("Orz,I can’t find D!");
		else
			printf("%I64d\n",ans);
	}
	return 0;
}

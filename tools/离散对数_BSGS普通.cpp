/*poj 2417
  题意：
  B^L==N(MOD P), 给出P,B,N, 求最小的非负L。
  限制：
  2 <= P < 2^31 && P为素数; 2 <= B <P; 1 <= N < P
  思路：
  离散对数，用giant-step baby-step解决。

  普通giant-step baby-step过程，要求P为素数：
  令s = ceil(sqrt(P)), 则L = b * s + r (0 <= b, r < s),
  即B^L = B^(b * s) * B^r。把所有B^r放入hash表中，从小到大枚举b，得到N^(b * s) * B^r = n。


  费马小定理a^(m-1)=1(mod m), m为素数, 可得：
  1) a^0=1,所以循环节小于等于m,即如果存在解,则最小解x<=m
  2) 对于a^s模m的逆元为a^(m-s-1)

  对于K^D = 1(MOD P)的特殊情况应该优先考虑欧拉定理来解决。
 */
#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<cstring>
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
//求解模方程a^x=b(mod m),n为素数,无解返回-1  
//注意：要求0 < a < m; 0 <= b < m; 否则按题意自己转化。
//复杂度O(sqrt(m))
LL log_mod(LL a, LL b, LL m){
	hs.init();
	LL s = ceil(sqrt(m));
	LL cur = 1;
	for (int i = 0; i < s; ++i){
		if(hs.find(cur)==-1) hs.insert(cur,i);	//记得先判重，在插入
		cur = cur * a % m;
	}
	LL v = a_b_MOD_c(a, (m - s - 1 + m) % m, m);
	for(int i = 0; i < s; ++i){
		LL tmp = hs.find(b);
		if(tmp!=-1)
			return s * i + tmp;
		b=b*v%m;
	}
	return -1;
}

int main(){
	int p, b, n;
	while(scanf("%d%d%d", &p, &b, &n) != EOF){
		LL ans = log_mod(b,n,p);
		if(ans == -1) puts("no solution");
		else printf("%I64d\n", ans);
	}
	return 0;
}

/*另外一种类似离散对数的题目则需要用欧拉定理来解决
  (A ^ x) % B = 1，求x
 */
void gao(LL A, LL B) {
	LL phi = get_phi(B);
	LL ans = phi;
	for (LL i = 2; i * i <= phi; ++i) {
		if (phi % i == 0) {
			while (phi % i == 0)
				phi /= i;
			while (ans % i == 0 && a_b_MOD_c(A, ans / i, B) == 1)
				ans /= i;
		}
	}
	if (phi > 1 && a_b_MOD_c(A, ans / phi, B) == 1)
		ans /= phi;
	printf("%I64d\n", ans);
}

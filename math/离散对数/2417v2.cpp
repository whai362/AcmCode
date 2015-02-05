#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
#define LL __int64
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
//复杂度O(sqrt(m))
LL log_mod(LL a, LL b, LL m){
	map<LL, LL> rec;
	LL s = ceil(sqrt(m + 0.5));
	cout<<"s"<<s<<endl;
	LL cur = 1;
	rec[cur] = s;
	for (int i = 1; i < s; ++i){
		cur = cur * a % m;
		if(rec[cur]==0) rec[cur] = i;	//
	}
	LL v = a_b_MOD_c(a, m - s - 1, m);
	for(int i = 0; i < s; ++i){
		LL tmp = rec[b];
		cout<<b<<' '<<tmp<<endl;
		if(tmp)
			return s * i + (tmp == s ? 0 : tmp);
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

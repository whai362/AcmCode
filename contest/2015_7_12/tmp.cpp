#include<cstdio>   
#include<cstring>   
#include<cmath>
#include<algorithm>   
#include<iostream>
using namespace std;
#define LL long long
const int MAXN=44725;
const int M=1005;
const int N=1000005;
bool is_pri[MAXN];
int pri[MAXN],tot;
void Out(LL x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

void get_pri(int n){
	tot = 0;
	--n;
	memset(is_pri, 1, sizeof(bool) * (n + 1));
	is_pri[0] = is_pri[1] = 0;
	for(int i = 2; i <= n; ++i)
		if(is_pri[i]){
			if(n / i < i) break;
			for(int j = i * i; j <= n; j += i) is_pri[j] = false;
		}
	for(int i = 2; i <= n; ++i) if(is_pri[i]) pri[tot++] = i;
}

//ÅÐ¶Ï´óËØÊý
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
const int Times=5;
bool MiLLer_Rabin(LL n){
	if(n < 2) return false;
	for(int i = 0; i <= Times; ++i){
		LL a=rand()%(n-1)+1;
		if(!test(n, a, n-1)) return false;
	}
	return true;
}

int pri_fac_tot=0;
LL pri_fac[M];
LL pri_fac_cnt[M];

void  get_pri_fac(LL x){
	for(int i=0;i<tot;++i){
		if(x<pri[i]) break;
		if(x%pri[i]==0){
			pri_fac[pri_fac_tot]=pri[i];
			while(x%pri[i]==0){
				x/=pri[i];
				pri_fac_cnt[pri_fac_tot]++;
			}
			pri_fac_tot++;
		}
	}
	if (x!=1){
		pri_fac_cnt[pri_fac_tot]=1;
		pri_fac[pri_fac_tot++]=x;
	}
}
LL fac[N];
int fac_tot=0;
void get_fac(int pos,int x){
	fac[fac_tot++]=x;
	if (pos>=pri_fac_tot) return ;
	LL cur=x;
	for(int i=0;i<pri_fac_cnt[pos]+1;++i){	
		get_fac(pos+1,cur);
		cur*=pri_fac[pos];
	}
}

LL ans[N],cnt=0;
void dfs(int pos,LL k,LL n){
	if(k==1){
		ans[cnt++]=n;
	}
	if(pos<0) return;
	if(k%fac[pos]==0){
		LL tmpk=k/fac[pos];
		LL tmpn=n*(fac[pos]+1);
		while(tmpk%(fac[pos]+1)==0){
			tmpk/=(fac[pos]+1);
			tmpn*=(fac[pos]+1);
		}
		dfs(pos-1,tmpk,tmpn);
	}
	dfs(pos-1,k,n);
}

void gao(LL n){
	int cc=0;
	for(int i=0;i<fac_tot;++i){
		if (MiLLer_Rabin(fac[i]+1)){
			fac[cc++]=fac[i];
		}
	}
	sort(fac,fac+cc);
	cc=unique(fac,fac+cc)-fac;
	dfs(cc-1,n,1);
	sort(ans,ans+cnt);
	cnt=unique(ans,ans+cnt)-ans;
	printf("%d\n",cnt);
	if(cnt){
		Out(ans[0]);
		//printf("%lld",ans[0]);
		for(int i=1;i<cnt;++i){
			putchar(' ');
			Out(ans[i]);
		}
	}
	puts("");
	//for(int i=0;i<cnt;++i){
	//	cout<<ans[i]<<' ';
	//}
	//cout<<endl;
}

void init(){
	cnt=0;
	pri_fac_tot=0;
	fac_tot=0;
}

int main(){
	get_pri(MAXN);
	LL n;
	int cas=0;
	while(scanf("%I64d",&n)!=EOF){
		init();
		get_pri_fac(n); 
		get_fac(0,1);
		printf("Case #%d: ",++cas);
		gao(n);
	}
	return 0;
}

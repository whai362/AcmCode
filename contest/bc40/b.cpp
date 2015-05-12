#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define LL __int64
#define PB push_back
const int N=105;
const int MOD=1000000007;
LL qpl[N];
LL f[N];
int a[N];
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}
void predo(){
	f[0]=1;
	for(int i=1;i<N;++i)
		f[i]=f[i-1]*i%MOD;
	LL ny4=inv(4,MOD);
	for(int i=1;i<N;++i){
		qpl[i]=f[i]*i*(i-1)%MOD*ny4%MOD;
	}
}
vector<int> tab[N];
bool vis[N];
void deal(int id,int n,LL &ans){
	memset(vis,0,sizeof(vis));
	if(tab[id].size()==0) return ;
	LL sum1=0,sum2=0;
	for(int i=0;i<id;++i){
		sum1+=tab[i].size();
		vis[a[i]]=1;
	}
	for(int i=0;i<tab[id].size();++i){
		for(int j=1;j<tab[id][i];++j){
			if(vis[j]==0) ++sum2;
		}
	}
	ans=(ans+sum1*f[n-1-id]*tab[id].size()+sum2*f[n-1-id])%MOD;
	ans=(ans+qpl[n-1-id]*tab[id].size())%MOD;
}
void gao(int n){
	LL ans=0;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if(a[i]>a[j]) tab[i].PB(a[j]);
		}
	}
	for(int i=0;i<n;++i){
		deal(i,n,ans);
	}
	printf("%I64d\n",ans);
}
void init(){
	for(int i=0;i<=N;++i)
		tab[i].clear();
}
int main(){
	int n;
	predo();
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		gao(n);
	}
	return 0;
}

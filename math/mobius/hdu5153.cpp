#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=1e5+5;
const int MOD=1000000007; 
int mu[N],pri[N],pcnt;
bool vis[N];
void getMu(){
	memset(vis,0,sizeof(vis));
	mu[1]=1;
	pcnt=0;
	for(int i=2;i<N;++i){
		if(!vis[i]){
			pri[pcnt++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<pcnt && i*pri[j]<N;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]) mu[i*pri[j]]=-mu[i];
			else{
				mu[i*pri[j]]=0;
				break;
			}
		}
	}
}
int cnt[N];
void predo(){
	for(int i=0;i<pcnt;++i){
		LL p=pri[i];
		while(p<N){
			for(int j=p;j<N;j+=p)
				cnt[j]+=mu[j/p];
			p*=pri[i];
		}
	}
	for(int i=1;i<N;++i) cnt[i]+=mu[i];
}
int a[N];
LL sum1[N],sum2[N],F[N];
LL inv(LL a,LL m){
	LL p=1,q=0,b=m,c,d;
	while(b>0){
		c=a/b;
		d=a; a=b; b=d%b;
		d=p; p=q; q=d-c*q;
	}
	return p<0?p+m:p;
}
void gao(int n){
	int MAX=0;
	LL ji=1;
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));
	for(int i=0;i<n;++i){
		MAX=max(MAX,a[i]);
		ji=ji*a[i]%MOD;
		LL cur=inv(a[i],MOD);
		sum1[a[i]]=(sum1[a[i]]+cur*cur%MOD)%MOD;
		sum2[1]=(sum2[1]+cur)%MOD;
		sum2[a[i]+1]=(sum2[a[i]+1]-cur+MOD)%MOD;
	}
	for(int i=1;i<=MAX;++i){
		sum1[i]=(sum1[i]+sum1[i-1])%MOD;
		sum2[i]=(sum2[i]+sum2[i-1])%MOD;
	}
	LL inv2=inv(2,MOD);
	for(int i=1;i<=MAX;++i){
		LL tmp1=0,tmp2=0;
		for(int j=i;j<=MAX;j+=i){
			tmp1=(tmp1+sum2[j])%MOD;
			int next=min(MAX,j+i-1);
			LL tmp=(LL)(j/i)*(j/i)%MOD;
			tmp2=(tmp2+tmp*(sum1[next]-sum1[j-1])%MOD)%MOD;
		}
		tmp1=tmp1*tmp1%MOD;
		F[i]=((tmp1-tmp2)*inv2%MOD+MOD)%MOD;
	}
	LL ans=0;
	for(int i=1;i<=MAX;++i)
		ans=((ans+F[i]*cnt[i])%MOD+MOD)%MOD;
	ans=ans*ji%MOD;
	printf("%I64d\n",ans);
}
int main(){
	getMu();
	predo();
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		gao(n);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
#define LL long long
const int N=1e2+5;
const int MOD=1000000007; 
int mu[N],pri[N],pcnt;
bool vis[N];
int cnt[N];
void getMu(){
	memset(vis,0,sizeof(vis));
	mu[1]=1;
	pcnt=0;
	for(int i=2;i<N;++i){
		if(!vis[i]){
			pri[pcnt++]=i;
			mu[i]=-1;
			//cnt[i]=1;
		}
		for(int j=0;j<pcnt && i*pri[j]<N;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]){
			   mu[i*pri[j]]=-mu[i];
			   //cnt[i*pri[j]]=-cnt[i]+mu[i];
			}
			else{
				mu[i*pri[j]]=0;
				//cnt[i*pri[j]]=mu[i];
				break;
			}
		}
	}
}
LL sum[N];
//0 1 1 -1 1 -2 1 0 -1 -2
void predo(){
	for(int i=2;i<N;++i){
		if(!vis[i]) cnt[i]=1;
		for(int j=0;j<pcnt && pri[j]<=i && i*pri[j]<N;++j){
			if(i%pri[j]) cnt[i*pri[j]]=-cnt[i]+mu[i];
			else{ cnt[i*pri[j]]=mu[i]; break; }
		}
	}
	//for(int i=0;i<pcnt;++i){
	//	int lim=N/pri[i];
	//	for(int j=1;j<lim;++j){
	//		cnt[j*pri[i]]+=mu[j];
	//	}
	//}
	for(int i=1;i<=N;++i)
		sum[i]=sum[i-1]+cnt[i];
}
int main(){
	//double st=clock(),en;
	getMu();
	predo();
	//for(int i=1;i<=10;++i){
	//	cout<<cnt[i]<<' ';
	//}
	//cout<<endl;
	int T;
	int a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		LL ans=0;
		for(int i=1,ls=0;i<=min(a,b);i=ls+1){
			ls=min(a/(a/i),b/(b/i));
			ans+=((LL)sum[ls]-sum[i-1])*(a/i)*(b/i);
			//ans+=(LL)(a/i)*(b/i)*cnt[i];
		}
		printf("%lld\n",ans);
	}
	//en=clock();
	//cerr<<double(en-st)/CLOCKS_PER_SEC<<endl;
	return 0;
}

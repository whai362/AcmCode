#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
#define LL long long
const int N=1e7+5;
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
LL sum[N];
void predo(){
	for(int i=0;i<pcnt;++i)
		for(int j=pri[i];j<N;j+=pri[i])
			cnt[j]+=mu[j/pri[i]];
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
		//for(int i=1;i<=min(a,b);++i){
		//	ans+=(LL)(a/i)*(b/i)*cnt[i];
		//}
		printf("%lld\n",ans);
	}
	//en=clock();
	//cerr<<double(en-st)/CLOCKS_PER_SEC<<endl;
	return 0;
}

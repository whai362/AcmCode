#include<stdio.h>
#include<string.h>
using namespace std;
#define mod 10007
#define N 50005
#define M 100005
int dis[N],hash[N],ans[N],to[N];
int n,m;
void init(){
	int i,u,v;
	memset(to,0,sizeof(to));
	memset(hash,0,sizeof(hash));
	for(i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		++hash[u];
		++hash[v];
		to[u]=v;
	}
}
void dij(int src){
	int i,d=0;
	for(i=0;i<n;++i){
		dis[src]=d++;
		src=to[src];
	}
}

int a_b_Mod_c(int a, int b, int c){
    int result = 1;
    int digit[32];
    int i,k;
    i=0;
    while(b){
        digit[i++]=b%2;
        b>>=1;
    }
    for(k=i-1;k>=0;k--){
        result=(result*result)%c;
        if(digit[k]==1){
            result=(result*a)%c;
        }
    }
    return result;
}

int main(){
	int i,j,k,src,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(n==1){ printf("%d\n",0); continue; }
		memset(ans,0,sizeof(ans));
		for(i=1;i<=n-1;++i) ans[0]=(ans[0]+a_b_Mod_c(i,k,mod))%mod;
		ans[0]=ans[0]%mod;
		ans[n-1]=ans[0];
		for(i=1,j=n-1;i<n/2;++i,--j){
			ans[i]=(ans[i-1]+a_b_Mod_c(i,k,mod)-a_b_Mod_c(j,k,mod))%mod;
			ans[i]=ans[i]%mod;
			ans[n-1-i]=ans[i];
		}
		if(n%2==1){
			ans[i]=(ans[i-1]+a_b_Mod_c(i,k,mod)-a_b_Mod_c(j,k,mod))%mod;
			ans[i]=ans[i]%mod;
		}
		m=n-1;
		init();
		for(i=0;i<n;++i) if(hash[i]==1){ src=i; break; }
		dij(src);
		for(i=1;i<=n;++i) printf("%d\n",ans[dis[i]]);
	}
	return 0;
}


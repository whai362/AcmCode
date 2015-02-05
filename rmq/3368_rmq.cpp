#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=100005;
int dp[N][20];
void makermq(int n,int b[]){
	for(int i=0;i<n;i++)
		dp[i][0]=b[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=0;i+(1<<j)-1<n;i++)
			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmq(int s,int v){
	int k=(int)(log((v-s+1)*1.0)/log(2.0));
	return max(dp[s][k],dp[v-(1<<k)+1][k]);
}
int a[N],b[N],L[2*N],R[2*N],hash[2*N];
void init(){
	memset(L,0,sizeof(L));
	memset(R,0,sizeof(R));
	memset(hash,0,sizeof(hash));
}
int main(){
	int n,q;
	while(scanf("%d",&n) && n){
		scanf("%d",&q);
		init();
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			a[i]+=N;
		}
		L[a[0]]=0;
		int cnt=0;
		hash[a[0]]=cnt;
		b[cnt]=1;
		for(int i=1;i<n;++i){
			if(a[i]==a[i-1]){
				++b[cnt];
			}
			else{
				L[a[i]]=i;
				R[a[i-1]]=i-1;
				b[++cnt]=1;
				hash[a[i]]=cnt;
			}
		}
		R[a[n-1]]=n-1;
		++cnt;
		makermq(cnt,b);
		/*for(int i=0;i<cnt;++i){
		  cout<<b[i]<<' ';
		  }
		  cout<<endl;*/
		for(int i=0;i<q;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			int left=L[a[u-1]],
				right=R[a[v-1]],
				l=hash[a[u-1]],
				r=hash[a[v-1]];
			//cout<<left<<' '<<right<<' '<<l<<' '<<r<<endl;
			if(l==r){
				int ans=v-u+1;
				printf("%d\n",ans);
			}
			else if(l+1==r){
				int ans=max(b[l]-(u-1-left),b[r]-(right-v+1));
				printf("%d\n",ans);
			}
			else{
				int ans=max(b[l]-(u-1-left),b[r]-(right-v+1));
				printf("%d\n",max(ans,rmq(l+1,r-1)));
			}
		}
	}
	return 0;
}

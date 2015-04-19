#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[1005];
void gao(){
	int lim=0;
	for(int i=0;i<n;++i){
		lim=max(lim,a[i]);
	}
	int ans=lim;
	for(int i=1;i<=lim;++i){
		int cnt=0;
		for(int j=0;j<n;++j){
			cnt+=a[j]/i-1;

			//cout<<cnt<<endl;
			if(a[j]%i) ++cnt;
		}
		//cout<<ans<<' '<<cnt<<' '<<i<<endl;
		ans=min(ans,cnt+i);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	int cas=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		printf("Case #%d: ",++cas);
		gao();
	}
}

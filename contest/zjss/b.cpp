#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
const int N=100005;
int cnt[32][2];
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+n,cmp);
		LL ans=0;
		for(int i=0;i<n;++i){
			for(int j=31;j>=0;--j){
				if((a[i] & (1<<j))){
					ans+=(LL)cnt[j][0];
					break;
				}
			}
			for(int j=31;j>=0;--j){
				if((a[i] & (1<<j))){
					++cnt[j][1];
				}
				else{
					++cnt[j][0];
				}
			}
			//cout<<a[i]<<' '<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
int cnt[105];
int main(){
	int n;
	int a;
	int k;
	while(scanf("%d",&n)!=EOF){
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			++cnt[a];
		}
		scanf("%d",&k);
		int hv=0;
		int ans=0;
		for(int i=0;i<N;++i){
			if(cnt[i]){
				hv+=cnt[i]-1;
				++ans;
			}
		}
		if(hv>=k) printf("%d\n",ans);
		else{
			k-=hv;
			ans-=k;
			printf("%d\n",ans);
		}
	}
	return 0;
}

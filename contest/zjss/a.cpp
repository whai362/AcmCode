#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1005;
int h[N];
int a[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		memset(h,0,sizeof(h));
		int _max=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			++h[a[i]];
			_max=max(_max,h[a[i]]);
		}
		sort(a,a+n);
		n=unique(a,a+n)-a;
		int cnt=0;
		int ans=0;
		for(int i=0;i<n;++i){
			if(h[a[i]]==_max){
				ans=a[i];
				++cnt;
			}
		}
		if(cnt==1){
			printf("%d\n",ans);
		}
		else{
			puts("Nobody");
		}
	}
	return 0;
}

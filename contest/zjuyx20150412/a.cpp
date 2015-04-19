#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
LL a[105];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		int cnt=1;
		int flag=0;
		for(int i=1;i<n;++i){
			if(a[i]==a[i-1]){
				++cnt;
			}
			else{
				if(cnt==1){
					printf("%lld\n",a[i-1]);
					flag=1;
					break;
				}
				cnt=1;
			}
		}
		if(flag==0 && cnt==1){
			printf("%lld\n",a[n-1]);
		}
	}
	return 0;
}

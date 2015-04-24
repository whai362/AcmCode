#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int a[N];
int main(){
	int n;
	while(scanf("%d",&n) && n){
		int sum=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sort(a,a+n);
		int _max=a[n-1];
		int ans=0;
		for(int i=_max;i<=sum;++i){
			if(sum%i==0){
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

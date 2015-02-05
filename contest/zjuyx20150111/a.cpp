#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005;
int a[N];
int main(){
	int n;
	int cas=0;
	while(scanf("%d",&n)!=EOF){
		int ans;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			if(i==0) ans=a[i];
			else ans=__gcd(ans,a[i]);
		}
		printf("Case %d: ",++cas);
		if(ans==1){
			printf("%d\n",2*(n-1));
			for(int i=2;i<=n;++i){
				printf("%d %d\n",1,i);
			}
			for(int i=2;i<=n;++i){
				printf("%d %d\n",1,i);
			}
			printf("\n");
		}
		else{
			puts("-1");
			printf("\n");
		}
	}
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005,
	  INF=0x3f3f3f3f;
int n,s;
int a[N];
void gao(){
	int ans=INF,sum=0,i=0,j=0;
	while(1){
		while(i<n && sum<s){
			sum+=a[i++];
		}
		if(sum<s) break;
		ans=min(ans,i-j);
		sum-=a[j++];
	}
	if(ans==INF) puts("0");
	else printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&s);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		gao();
	}
	return 0;
}

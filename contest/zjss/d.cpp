#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
const int N=1e6+5;
int pre[N];
int last[N];
int a[N];
void predo(int n){
	memset(last,-1,sizeof(last));
	for(int i=0;i<n;++i){
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}
}
LL cal(int i,int n){
	//cout<<(i-pre[i])<<' '<<n-i<<' '<<a[i]<<endl;
	return (LL)(i-pre[i])*(n-i)*a[i];
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		predo(n);
		//for(int i=0;i<n;++i){
		//	cout<<pre[i]<<' ';
		//}
		//cout<<endl;
		LL ans=0;
		for(int i=0;i<n;++i){
			ans+=cal(i,n);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

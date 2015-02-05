#include<cstdio>
#include<iostream>
using namespace std;
int a,b,hash[100005];
int main(){
	int i,m,n;
	long long ans1=0,ans2=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a);
		hash[a]=i+1;
	}
	scanf("%d",&m);
	for(i=0;i<m;++i){
		scanf("%d",&b);
		ans1+=(long long)hash[b];
		ans2+=(long long)(n+1-hash[b]);
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}

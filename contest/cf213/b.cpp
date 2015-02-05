#include<iostream>
#include<cstdio>
using namespace std;
#define N 100005
bool hash[N];
long long a[N];
int main(){
	int ans=2,i,max=1,n;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		cin>>a[i];
	}
	for(i=0;i<n-2;++i){
		if(a[i]+a[i+1]==a[i+2]) ++ans;
		else ans=2;
		if(ans>max) max=ans;
	}
	if(n<=2){
		max=n;
	}
	printf("%d\n",max);
	return 0;
}

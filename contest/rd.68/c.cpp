#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[205];
int main(){
	int i,n,s1=0,s2=0;
	scanf("%d",&n);
	for(i=0;i<2*n-1;++i){
		scanf("%d",&a[i]);
	}
	for(i=0;i<2*n-1;++i){
		s1+=a[i];
	}
	sort(a,a+2*n-1);
	for(i=0;i<n;++i){
		a[i]=-a[i];
	}
	for(i=0;i<2*n-1;++i){
		s2+=a[i];
	}
	printf("%d\n",max(s1,s2));
	return 0;
}

#include<cstdio>
#include<iostream>
using namespace std;
int a[55];
int main(){
	int cnt,T;
	int n;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	cnt=0;
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n-1;++i){
		if(a[i]>a[i-1] && a[i]>a[i+1]){
			++cnt;
		}
	}
	printf("%d\n",cnt);
	}
	return 0;
}

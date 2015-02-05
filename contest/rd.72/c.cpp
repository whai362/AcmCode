#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 2000005
int a[N];

int cmp(int a,int b){
	return a>b;
}
int main(){
	int i,k=1,n;
	long long s=0;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	while(k<=n){
		for(i=0;i<k;++i){
			s+=(__int64)a[i];
		}
		k*=4;
	}
	cout<<s<<endl;
	return 0;
}

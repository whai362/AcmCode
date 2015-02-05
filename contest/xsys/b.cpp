#include<iostream>
#include<cstdio>
using namespace std;
#define N 2005
int a[N],hash[N];
void swap(int i,int j){
	int tmp;
	hash[a[i]]=j;
	hash[a[j]]=i;
	tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
}
int main(){
	int cas=0,n,T;
	int i;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		hash[a[i]]=i;
	}
	int cnt=0;
	for(i=1;i<=n;++i){
		while(a[i]!=i){
			swap(i,hash[a[i]-1]);
			++cnt;
		}
	}
	printf("Case #%d: %d\n",++cas,cnt);
	}
	return 0;
}

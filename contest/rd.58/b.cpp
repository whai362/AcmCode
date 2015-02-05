#include<cstdio>
#include<iostream>
using namespace std;
int c[100005];
int main(){
	int cnt=0,i,n,t;
	scanf("%d%d",&n,&t);
	for(i=0;i<n;++i){
		scanf("%d",&c[i]);
	}
	for(i=0;i<n;++i){
		if(t-c[i]>=0) t-=c[i],++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}

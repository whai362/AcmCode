#include<cstdio>
#include<iostream>
using namespace std;
const int N=50005,
	  INF=0x3f3f3f3f;
int n,l1[N],l2[N];
int abs(int a){
	if(a>=0) return a;
	return -a;
}
int gao(int str[]){
	int a,b;
	a=b=str[0];
	for(int i=1;i<n;++i){
		b=abs(str[i]-b);
	}
	return b;
}
int main(){
	int _max,_min;
	while(scanf("%d",&n)!=EOF){
	for(int i=0;i<n-1;++i){
		l1[i]=n-1-i;
	}
	l1[n-1]=n;
	for(int i=0;i<n;++i){
		l2[i]=n-i;
	}
	_max=gao(l1);
	_min=gao(l2);
	printf("%d %d\n",_min,_max);
	printf("%d",l1[0]);
	for(int i=1;i<n;++i){
		printf(" %d",l1[i]);
	}
	puts("");
	printf("%d",l2[0]);
	for(int i=1;i<n;++i){
		printf(" %d",l2[i]);
	}
	puts("");
	}
	return 0;
}

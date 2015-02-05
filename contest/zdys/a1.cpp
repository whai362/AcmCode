#include<cstdio>
#include<iostream>
using namespace std;
const int N=50005,
	  INF=0x3f3f3f3f;
struct Data{
	int flag;
	int a[N];
}l1,l2;
int n;
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
	_max=0,_min=0x3f3f3f3f;
	if(n==1){
		l1.flag=1;
		l2.flag=0;
		for(int i=0;i<1;++i){
			l1.a[i]=i+1;
			l2.a[i]=i+1;
		}
	}
	else if(n==2){
		l1.flag=1;
		l2.flag=0;
		for(int i=0;i<2;++i){
			l1.a[i]=i+1;
			l2.a[i]=i+1;
		}
	}
	if(n>2){
		l1.flag=1;
		l2.flag=0;
		for(int i=0;i<2;++i){
			l1.a[i]=i+1;
			l2.a[i]=i+1;
		}
		for(int i=2;i<n;++i){
			l1.flag^=1;
			l2.flag^=1;
			if(l1.flag){
				l1.a[i]=i+1;
			}
			else{
				l1.a[i-1]=i+1;
				l1.a[i]=i;
			}
			if(l2.flag){
				l2.a[i]=i+1;
			}
			else{
				l2.a[i-1]=i+1;
				l2.a[i]=i;
			}
		}
	}
	if(l1.flag){
		_max=gao(l1.a);
		_min=gao(l2.a);
	}
	else{
		_max=gao(l2.a);
		_min=gao(l1.a);
	}
	printf("%d %d\n",_min,_max);
	if(l1.flag){
		printf("%d",l1.a[0]);
		for(int i=1;i<n;++i){
			printf(" %d",l1.a[i]);
		}
		puts("");
		printf("%d",l2.a[0]);
		for(int i=1;i<n;++i){
			printf(" %d",l2.a[i]);
		}
		puts("");
	}
	else{
		printf("%d",l2.a[0]);
		for(int i=1;i<n;++i){
			printf(" %d",l2.a[i]);
		}
		puts("");
		printf("%d",l1.a[0]);
		for(int i=1;i<n;++i){
			printf(" %d",l1.a[i]);
		}
		puts("");
	}
	}
	return 0;
}

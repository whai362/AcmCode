#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 25
int a[N],d[3];
bool cmp(int n1,int n2){
	return n1>n2;
}
int get(){
	int i,id,_min=0x3f3f3f3f;
	for(i=0;i<3;++i){
		if(_min>d[i]) _min=d[i],id=i;
	}
	return id;
}
int main(){
	int n,t;
	int i;
	scanf("%d",&t);
	while(t--){
	scanf("%d",&n);
	memset(d,0,sizeof(d));
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	for(i=0;i<n;++i){
		d[get()]+=a[i];
	}
	int _max=0,_min=0x3f3f3f3f;
	for(i=0;i<3;++i){
		if(d[i]>_max) _max=d[i];
		if(d[i]<_min) _min=d[i];
	}
	printf("%d\n",_max-_min);
	}
	return 0;
}

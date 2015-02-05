#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 105
struct data{
	int c,x,id;
}d[N];
bool cmp1(data d1,data d2){
	return d1.x<d2.x;
}
bool cmp2(data d1,data d2){
	return d1.id<d2.id;
}
int main(){
	int n,m,l,r;
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		scanf("%d",&d[i].x);
		d[i].id=i;
	}
	for(i=0;i<m;++i){
		scanf("%d%d",&l,&r);
	}
	sort(d,d+n,cmp1);
	for(i=0;i<n;++i){
		d[i].c=i%2;
	}
	sort(d,d+n,cmp2);
	for(i=0;i<n;++i){
		printf("%d ",d[i].c);
	}
	printf("\n");
	return 0;
}

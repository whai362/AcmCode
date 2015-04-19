#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define LL __int64
LL x[10],y[10],z[10];
bool zj(int a,int b,int c){
	LL x1,y1,z1;
	LL x2,y2,z2;
	x1=x[a]-x[b];
	y1=y[a]-y[b];
	z1=z[a]-z[b];

	x2=x[b]-x[c];
	y2=y[b]-y[c];
	z2=z[b]-z[c];
	if(x1*x2+y1*y2+z1*z2==0) return true;
	return false;
}
LL sqr(LL a){
	return a*a;
}
LL dis(int a,int b){
	return sqr(x[a]-x[b])+sqr(y[a]-y[b])+sqr(z[a]-z[b]);
}
void _swap(int a,int b){
	swap(x[a],x[b]);
	swap(y[a],y[b]);
	swap(z[a],z[b]);
}
void tz(){
	LL d;
	LL _max=0,id=0;
	for(int i=1;i<4;++i){
		d=dis(0,i);
		if(d>_max){
			_max=d;
			id=i;
		}
	}
	if(id!=2){
		_swap(id,2);
	}
}
int main(){
	int n;
	int cas=0;
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<4;++i){
			scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
		}
		tz();
		int flag=1;
		LL d=dis(0,1);
		for(int i=0;i<4;++i){
			if( !(zj(i,(i+1)%4,(i+2)%4) && dis(i,(i+1)%4)==d) ){
				flag=0;
				break;
			}
		}
		printf("Case #%d: ",++cas);
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}

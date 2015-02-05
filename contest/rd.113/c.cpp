#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 1005
#define T 1000005
int A,B,ca,cb,n;
int h1[N],h2[N];
void gao1(){
	if(A==0){
		printf("fill A\n");
		A=ca;
	}
	else if(B==cb){
		printf("empty B\n");
		B=0;
	}
	else{
		printf("pour A B\n");
		if(cb-B>A){
			B+=A;
			A=0;
		}
		else{
			A-=cb-B;
			B=cb;
		}
	}
}
void gao2(){
	if(B==0){
		printf("fill B\n");
		B=cb;
	}
	else if(A==ca){
		printf("empty A\n");
		A=0;
	}
	else{
		printf("pour B A\n");
		if(ca-A>B){
			A+=B;
			B=0;
		}
		else{
			B-=ca-A;
			A=ca;
		}
	}
}
int main(){
	int i;
	while(scanf("%d%d%d",&ca,&cb,&n)!=EOF){
	memset(h1,0,sizeof(h1));
	memset(h2,0,sizeof(h2));
	for(i=0;i<T;++i){
		h1[(i*ca)%cb]=1;
		h2[(i*cb)%ca]=1;
	}
	A=B=0;
	if(h1[n]){
		while(B!=n){
			gao1();
		}
	}
	else{
		while(B!=n){
			gao2();
		}
	}
	printf("success\n");
	}
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
int a,b;
void gao(){
	bool f=true;
	while(1){
		if(a>b) swap(a,b);
		if(b%a==0) break;
		if(b-a>a) break;
		b-=a;
		f=!f;
	}
	if(f) puts("Stan wins");
	else puts("Ollie wins");
}

int main(){
	while(scanf("%d%d",&a,&b) && (a||b)){
		gao();
	}
	return 0;
}

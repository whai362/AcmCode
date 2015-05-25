#include<iostream>
#include<cstdio>
using namespace std;
void gao(int n){
	int cnt=0;
	for(int i=0;i<30;++i){
		if((1<<i) & n) ++cnt;
	}
	printf("%d\n",(1<<cnt));
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		gao(n);
	}
	return 0;
}

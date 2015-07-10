#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k) && (n || k)){
		if((n-1)%(k+1)==0)
			puts("Jiang");
		else
			puts("Tang");
	}
	return 0;
}

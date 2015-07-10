#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) && (n || m)){
		if(n%2==0) puts("Wonderful!");
		else if(n%2==1 && m%2==0) puts("Wonderful!"); 
		else puts("What a pity!");
	}
	return 0;
}

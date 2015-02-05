#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",min(n,m)+1);
	for(i=1,j=0;i<=n-1 && j<=m-1;++i,++j){
		printf("%d %d\n",i,j);		
	}
	if(n<=m) printf("%d %d\n",0,j);
	printf("%d %d\n",n,m);
	return 0;
}


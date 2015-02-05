#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int count=0,i,j,x,y,a,b,tmp;
	scanf("%d%d%d%d",&x,&y,&a,&b);
	tmp=max(a,b+1);
	for(i=tmp;i<=x;++i){
		for(j=b;j<i && j<=y;++j){
			++count;
		}
	}
	printf("%d\n",count);	
	for(i=tmp;i<=x;++i){
		for(j=b;j<i && j<=y;++j){
			printf("%d %d\n",i,j);
		}
	}
	return 0;
}

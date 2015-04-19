#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a1,h1,a2,h2;
		scanf("%d%d%d%d",&a1,&h1,&a2,&h2);
		h1-=a2;
		h2-=a1;
		if(a1==0) puts("Invalid");
		else{
			if(h1<=0)
				printf("Discard ");
			else
				printf("%d %d ",a1,h1);
			if(h2<=0)
				printf("Discard\n");
			else
				printf("%d %d\n",a2,h2);
		}
	}
	return 0;
}

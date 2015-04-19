#include<iostream>
#include<cstdio>
using namespace std;
int tab3[4][4]={
	0,0,0,0,
	0,0,1,0,
	0,1,1,1,
	0,0,1,0
};

int main(){
	int x,r,c;
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		scanf("%d%d%d",&x,&r,&c);
		printf("Case #%d: ",++cas);
		if(x==1){
			puts("GABRIEL");
		}
		else if(x==2){
			if(r%2==0 || c%2==0) puts("GABRIEL");
			else puts("RICHARD");
		}
		else if(x==3){
			if(tab3[r-1][c-1]) puts("GABRIEL");
			else puts("RICHARD");
		}
		else{
			if(r>c) swap(r,c);
			if((r==3 && c==4) || (r==4 && c==4)) puts("GABRIEL");
			else puts("RICHARD");
		}
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int x,y,t1,t2;
	scanf("%d%d",&x,&y);
	if(y==0 && (x==0 || x==1)) printf("0\n");
	else{
		t1=max(abs(x),abs(y));
		if(x==t1 && y==-(t1-1)) t2=0;
		else if(y>-t1 && y<=t1 && x==t1) t2=1;
		else if(x>=-t1 && x<t1 && y==t1) t2=2;
		else if(y>=-t1 && y<t1 && x==-t1) t2=3;
		else if(x>-t1 && x<=t1+1 && y==-t1) t2=4; 
		t2+=(t1-1)*4;
		printf("%d\n",t2);
	}
	return 0;
}

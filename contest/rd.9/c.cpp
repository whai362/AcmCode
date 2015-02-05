#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n,x,y,t;
	scanf("%d%d%d",&n,&x,&y);
	if(n*y%100) t=n*y/100+1;
	else t=n*y/100;
	if(t>x)
	  printf("%d\n",t-x);
	else
	  printf("%d\n",0);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main(){
	double R,r;
	int i,n,t;
	scanf("%d",&t);
	for(i=1;i<=t;++i){
		scanf("%lf%d",&R,&n);
		printf("Scenario #%d:\n%.3f\n\n",i,(R*sin(pi/n))/(1+sin(pi/n)));
	}
	return 0;
}

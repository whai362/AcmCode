#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		double n,a,r;
		scanf("%lf%lf%lf",&n,&a,&r);
		double R=a/(tan(pi/n)*2.0);
		//cout<<R<<endl;
		printf("Case #%d:\n",++cas);
		if(R>=r) puts("Give me a kiss!");
		else puts("I want to kiss you!");
	}
	return 0;
}

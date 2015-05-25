#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		double n;
		scanf("%lf",&n);
		double a=1.0+(n-2.0)*19.0/27.0;
		double b=(46.0-38.0/n)/(19.0-11.0/n);
		printf("Case #%d:\n%.6f %.6f\n",++cas,a,b);
	}
}

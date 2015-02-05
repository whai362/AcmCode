//(n+1)a[1]=n*a[0]+a[n+1]-2*c[n]-4*c[n-1]-...-2*n*c[1]

#include<iostream>
#include<cstdio>
using namespace std;
int n;
double a[3005],c[3005];
int main(){
	int i;
	double tmp=0.0;
	scanf("%d",&n);
	scanf("%lf%lf",&a[0],&a[n+1]);
	for(i=1;i<=n;++i){
		scanf("%lf",&c[i]);
	}
	for(i=1;i<=n;++i){
		tmp+=c[n+1-i]*2*i;
	}
	printf("%.2f\n",(n*a[0]+a[n+1]-tmp)/(n+1));
	return 0;
}

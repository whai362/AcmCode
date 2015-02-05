#include<iostream>
#include<cstdio>
using namespace std;
int n;
double a[3005],c[3005];
double cal(int i){
	cout<<i<<endl;
	if(a[i]!=0.0) return a[i]; 
	a[i]=(cal(i-1)+cal(i+1))/2-c[i];
	return a[i];
}
int main(){
	int i;
	scanf("%d",&n);
	scanf("%lf%lf",&a[0],&a[n+1]);
	for(i=1;i<=n;++i) scanf("%lf",&c[i]);
	printf("%.2f\n",cal(1));
	return 0;
}

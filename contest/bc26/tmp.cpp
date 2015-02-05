#include<iostream>
#include<cstdio>
using namespace std;
double gao(int a,int b){
	double x=a,y=1;
	double ans=0;
	for(int i=1;i<=b;++i){
		ans+=y/x;
		x*=a;
		y*=(a-1);
	}
	return double((long long)(1+a)*a/2)*ans;
}
int main(){
	int a,b;
	cin>>a>>b;
	printf("%.3lf\n",gao(a,b));
}

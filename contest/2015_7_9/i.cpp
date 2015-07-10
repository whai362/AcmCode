#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1005;
double x[N],y[N],t[N];
double sqr(double x){
	return x*x;
}
double dis(int i,int j){
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}
void gao(int n){
	double ans=0;
	for(int i=1;i<n;++i){
		ans=max(ans,dis(i,i-1)/(t[i]-t[i-1]));
	}
	printf("%.10f\n",ans);
}
int main(){
	int T;
	int n;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>t[i]>>x[i]>>y[i];
		}
		gao(n);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-10;
const double INF=1e20;
double a[3],b[3];
double dx[]={-1,1,-1,1};
double dy[]={1,-1,-1,1};
bool ok(double x){
	double max1=-INF,min1=INF;
	for(int i=0;i<4;++i){
		double tmpx=a[0]+dx[i]*x;
		double tmpy=a[1]+dy[i]*x;
		double tmp=tmpx*tmpy;
		max1=max(max1,tmp);
		min1=min(min1,tmp);
	}
	double max2=-INF,min2=INF;
	for(int i=0;i<4;++i){
		double tmpx=b[0]+dx[i]*x;
		double tmpy=b[1]+dy[i]*x;
		double tmp=tmpx*tmpy;
		max2=max(max2,tmp);
		min2=min(min2,tmp);
	}
	if(max1>max2){
		swap(max1,max2);
		swap(min1,min2);
	}
	if(max1>=min2) return true;
	return false;
}
int main(){
	scanf("%lf%lf%lf%lf",&a[0],&b[0],&b[1],&a[1]);
	double l=0,r=1e20;
	int cnt=0;
	while(fabs(r-l)>eps){
		if(cnt>1e6) break;
		double mid=(l+r)/2.0;
		if(ok(mid)) r=mid;
		else l=mid;
		++cnt;
	}
	printf("%.10f\n",r);
	return 0;
}

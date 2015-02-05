#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
struct point{
	double x,y;
}p[105];
double dis(point a,point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
	int i,n,k;
	double d,t;
	cin>>n>>k;
	d=0;
	for(i=0;i<n;++i){
		cin>>p[i].x>>p[i].y;
	}
	for(i=0;i<n-1;++i){
		d+=sqrt(dis(p[i],p[i+1]));
	}
	t=d*k/50;
	cout<<fixed<<setprecision(10)<<t<<endl;
}

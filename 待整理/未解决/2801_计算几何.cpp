#include<iostream>
#include<cmath>
using namespace std;
#define pi acos(-1.0)
#define eps 1e-7
struct point{
	double fi,nu;
}p[25];
int n;
double dis(point a,point b){
	double t1,t2;
	t1=fabs(a.fi-b.fi)*pi/180.0;
	t2=fabs(a.nu-b.nu);
	t2=min(t2,360.0-t2)*pi/180.0;
	return t1*t1+t2*t2;
}
bool ok(double r){
	int i,j,f=1;
	for(i=0;i<n;++i){
		for(j=i+1;j<n;++j){
			if(r*r<dis(p[i],p[j])){
				f=0;
				break;
			}
		}
		if(!f) break;
	}
	return f;
}
int main(){
	int i;
	double max=pi,min=0.0,mid;
	cin>>n;
	for(i=0;i<n;++i)
	  cin>>p[i].fi>>p[i].nu;
	while(max-min>eps){
		mid=(max+min)/2;
		if(ok(mid)) max=mid;
		else min=mid;
		cout<<mid<<endl;
	}
	cout<<(max+min)/2<<endl;
}

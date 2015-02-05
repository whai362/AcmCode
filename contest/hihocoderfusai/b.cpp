#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define N 105
const double pi=acos(-1.0);
struct building{
	double x,y,r,h;
}b[N];
int main(){
	int n;
	double h,r,s_d,s_l;
	int i;
	cin>>r>>h;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		cin>>b[i].x>>b[i].y>>b[i].r>>b[i].h;
	}
	i=0;
	double dis=sqrt(b[i].x*b[i].x+b[i].y*b[i].y),
		   p=r-b[i].h*r/h;
	cout<<dis<<' '<<p<<endl;
	if(p>=dis-r && p<=dis+r){
		if(p<=dis){
			s_l=2*b[i].r;
		}
		else{
			double tmp=p-dis;
			s_l=2*sqrt(b[i].r*b[i].r-tmp*tmp);
		}
	}
	cout<<s_l<<endl;
	double arfa=2*asin(s_l/(2*r));
	cout<<1-arfa/360<<endl;
	return 0;
}

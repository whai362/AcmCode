#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double eps=1e-8;
const int N=10005;
struct Pt{
	double x,y,z;
	double v,h;
}p[N];
double cal(double x,int n) {
    double _max=0;
    for(int i=0;i<n;++i) {
        double xl=p[i].v/(x-p[i].h);
		_max=max(_max,xl);
    }
    return _max*x;
}
double sqr(double x){
	return x*x;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		double max_h=0,max_v=0;
		for(int i=0;i<n;++i){
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
			p[i].v=p[i].z;
			p[i].h=sqrt(sqr(p[i].x)+sqr(p[i].y));
			max_v=max(max_v,p[i].v);
			max_h=max(max_h,p[i].h);
		}
		double L=max_h,R=1e6;
		//cout<<"!"<<endl;
		while(L+eps<R){
			double ml=(2*L+R)/3;
			double mr=(L+2*R)/3;
			double ans_l=cal(ml,n)*ml*ml;
			double ans_r=cal(mr,n)*mr*mr;
			if(ans_l>ans_r){
				L=ml+eps;
			}
			else{
				R=mr-eps;
			}
		}
		double ans=(L+R)/2;
		printf("%.3f %.3f\n",cal(ans,n),ans);
	}
	return 0;
}

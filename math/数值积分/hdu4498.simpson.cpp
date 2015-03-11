#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define PB push_back
const double EPS=1e-8;
vector<double> x;
void cal(double a,double b,double c){	//计算a*x^2+b*x+c=0的解
	if(a==0 && b==0)
		return ;
	if(a==0){
		double t=-c/b;
		if(t>=0 && t<=100)
			x.PB(t);
		return ;
	}
	double delta=b*b-4*a*c;
	if(delta<0) return ;
	if(delta==0){
		double t=-b/(2*a);
		if(t>=0 && t<=100)
			x.PB(t);
	}
	else{
		double t1=(-b+sqrt(delta))/(2*a);
		double t2=(-b-sqrt(delta))/(2*a);
		if(t1>=0 && t1<=100)
			x.PB(t1);
		if(t2>=0 && t2<=100)
			x.PB(t2);
	}
}

const int N=105;
double A[105],B[105],C[105];
int sel;
double f(double x){
	return sqrt(1.0+(2.0*A[sel]*x+B[sel])*(2.0*A[sel]*x+B[sel]));
}
int get_best(double x,int n){
	int ret=0;
	double _min=100;
	for(int i=1;i<=n;++i){
		double tmp=A[i]*x*x+B[i]*x+C[i];
		if(tmp<_min){
			_min=tmp;
			ret=i;
		}
	}
	return ret;
}
//三点simpson法
double simpson(double a,double b){
	double c =  a+(b-a)/2;
	return (f(a) + 4*f(c) + f(b))*(b-a)/6;
}
//自适应Simpson公式(递归过程)。已知整个区间[a,b]上的三点simpson值A 
double asr(double a , double b ,double eps ,double A){
	double c = a+ (b-a)/2;
	double L = simpson(a,c) ,R = simpson(c,b);
	if(fabs(A-L-R)<=15*eps) return L + R +(A-L-R)/15;
	return asr(a,c,eps/2,L) + asr(c,b,eps/2,R);
}
//自适应Simpson公式(主过程) 
double asr(double a, double b, double eps){
	return asr(a, b, eps, simpson(a, b));
}
int main(){
	int T;
	double k,a,b;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		A[0]=0;
		B[0]=0;
		C[0]=100;
		for(int i=1;i<=n;++i){
			scanf("%lf%lf%lf",&k,&a,&b);
			A[i]=k;
			B[i]=-2.0*a*k;
			C[i]=k*a*a+b;
		}
		x.clear();
		for(int i=0;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				cal(A[i]-A[j],B[i]-B[j],C[i]-C[j]);
		double ans=0;
		x.PB(0); x.PB(100);
		sort(x.begin(),x.end());
		for(int i=0;i<x.size()-1;++i){
			double l=x[i],r=x[i+1];
			if(fabs(r-l)<EPS) continue;
			double mid=(l+r)/2;
			sel=get_best(mid,n);
			//cout<<l<<' '<<r<<endl;
			ans+=asr(l,r,EPS);
			//cout<<ans<<endl;
		}
		printf("%.2f\n",ans);
	}
	return 0;
}

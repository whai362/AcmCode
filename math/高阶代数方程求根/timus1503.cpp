#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define PB push_back
const double EPS=1e-12;
const double INF=1e+12;
inline int sign(double x){
	return x<-EPS?-1:x>EPS;
}
inline double get(const vector<double> &coef,double x){
	double e=1,s=0;
	for(int i=0;i<coef.size();++i) s+=coef[i]*e,e*=x;
	return s;
}
double find(const vector<double> &coef,int n,int lo,int hi){
	double sign_lo,sign_hi;
	sign_lo=sign(get(coef,lo));
	if(sign_lo==0) return lo;
	sign_hi=sign(get(coef,hi));
	if(sign_hi==0) return hi;
	if(sign_lo*sign_hi>0) return INF;
	for(int step=0;step<100 && hi-lo>EPS;++step){
		double m=(lo+hi)/2;
		int sign_mid=sign(get(coef,m));
		if(sign_mid==0) return m;
		if(sign_lo*sign_mid<0) hi=m;
		else lo=m;
	}
	return (lo+hi)/2;
}
vector<double> gao(vector<double> coef,int n){
	vector<double> ret;
	if(n==1){
		if(sign(coef[1])) ret.PB(-coef[0]/coef[1]);
		return ret;
	}
	vector<double> dcoef(n);
	for(int i=0;i<n;++i) dcoef[i]=coef[i+1]*(i+1);
	vector<double> droot=gao(dcoef,n-1);
	droot.insert(droot.begin(),-INF);
	droot.PB(INF);
	for(int i=0;i+1<droot.size();++i){
		double tmp=find(coef,n,droot[i],droot[i+1]);
		if(tmp<INF) ret.PB(tmp);
	}
	return ret;
}
int main(){
	return 0;
}

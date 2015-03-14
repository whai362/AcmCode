#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const double EPS=1e-10;
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){ x=_x; y=_y; }
	Point operator + (Point p){ return Point(x+p.x,y+p.y); }
	Point operator - (Point p){ return Point(x-p.x,y-p.y); }
	Point operator * (double d){ return Point(d*x,d*y); }
	double dot(Point p){ return x*p.x+y*p.y; }	//内积
	double det(Point p){ return x*p.y-p.x*y; }
};
bool cmpxy(const Point &p,const Point &q){
	if(p.x!=q.x) return p.x<q.x;
	return p.y<q.y;
}
vector<Point> convex_hull(Point *ps,int n){	//凸包要注意退化成2个点，1个点的情况
	sort(ps,ps+n,cmpxy);
	int k=0;
	vector<Point> qs(n*2);	//构造中的凸包
	for(int i=0;i<n;++i){	//构造凸包的下侧
		while(k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) --k;
		qs[k++]=ps[i];
	}
	for(int i=n-2,t=k;i>=0;--i){	//构造凸包的上侧
		while(k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) --k;
		qs[k++]=ps[i];
	}
	qs.resize(k-1);
	return qs;
}
double dist(Point p,Point q){
	return (p-q).dot(p-q);
}
const int N=1e5+5;
Point ps[N];
void xzqk(int n){
	vector<Point> qs=convex_hull(ps,n);
	n=qs.size();
	if(n==2){	//特别处理凸包退化的情况
		printf("%.0f\n",dist(qs[0],qs[1]));
		return ;
	}
	int i=0,j=0;
	for(int k=0;k<n;++k){
		if(!cmpxy(qs[i],qs[k])) i=k;
		if(cmpxy(qs[j],qs[k])) j=k;
	}
	double ans=0;
	int si=i,sj=j;
	while(i!=sj || j!=si){
		ans=max(ans,dist(qs[i],qs[j]));
		if((qs[(i+1)%n]-qs[i]).det(qs[(j+1)%n]-qs[j])<0)
			i=(i+1)%n;
		else
			j=(j+1)%n;
	}
	printf("%.3f\n",sqrt(ans));
}
int main(){
	int T;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&ps[i].x,&ps[i].y);
		xzqk(n);
	}
	return 0;
}

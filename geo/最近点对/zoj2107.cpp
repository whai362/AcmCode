/*zoj 2107
  题意：
  给出n个点，求最近点对的距离/2。
  限制：
  2 <= n <= 1e5
  思路：
  点分治
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double INF=1e30;
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

const int N=100005;
Point p[N];
int t[N];
double dist(Point a,Point b){
	return sqrt((a-b).dot(a-b));
}
bool cmpxy(Point a,Point b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
bool cmpy(int a,int b){
	return p[a].y<p[b].y;
}
double gao(int l,int r){
	double d=INF;
	if(l==r) return d;
	if(l+1==r) return dist(p[l],p[r]);
	int mid=(l+r)>>1;
	d=min(gao(l,mid),gao(mid+1,r));
	int cnt=0;
	for(int i=l;i<=r;++i){
		if(fabs(p[mid].x-p[i].x)<d)
			t[cnt++]=i;
	}
	sort(t,t+cnt,cmpy);
	for(int i=0;i<cnt;++i){
		for(int j=i+1;j<cnt && p[t[j]].y-p[t[i]].y<d;++j)
			d=min(d,dist(p[t[j]],p[t[i]]));
	}
	return d;
}
int main(){
	int n;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p,p+n,cmpxy);
		//for(int i=0;i<n;++i){
		//	cout<<p[i].x<<' '<<p[i].y<<endl;
		//}
		printf("%.2f\n",gao(0,n-1)/2);
	}
	return 0;
}

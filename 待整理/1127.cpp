#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define eps 1e-10
#define N 10005
struct point{
	double x,y;
	point(){}
	point(double _x,double _y){
		x=_x;
		y=_y;
	}
	point operator -(const point &b)const{
		return point(x-b.x,y-b.y);
	}
	double operator *(const point &b)const{
		return x*b.y-y*b.x;
	}
	double operator &(const point &b)const{
		return x*b.x-y*b.y;
	}
};
struct line{
	point p1,p2;
}l[N];
int f[N];
int sgn(double d){ return d<-eps?-1:d>eps; }
bool inter(line l1,line l2){
	return
		max(l1.p1.x,l1.p2.x)>=min(l2.p1.x,l2.p2.x) &&
		max(l2.p1.x,l2.p2.x)>=min(l1.p1.x,l1.p2.x) &&
		max(l2.p1.y,l2.p2.y)>=min(l1.p1.y,l1.p2.y) &&
		sgn((l2.p1-l1.p1)*(l1.p2-l1.p1))*sgn((l2.p2-l1.p1)*(l1.p2-l1.p1))<=0 &&
		sgn((l1.p1-l2.p1)*(l2.p2-l2.p1))*sgn((l1.p2-l2.p1)*(l2.p2-l2.p1))<=0;
}
int getF(int n){
	if(f[n]!=n) return f[n]=getF(f[n]);
	return n;
}
int main(){
	int a,b,i,j,n;
	while(scanf("%d",&n) && n){
		for(i=0;i<n;++i){
			cin>>l[i].p1.x>>l[i].p1.y>>l[i].p2.x>>l[i].p2.y;
		}
		for(i=0;i<=n;++i){
			f[i]=i;
		}
		for(i=0;i<n-1;++i){	//检测相交代码正确性
			for(j=i+1;j<n;++j){
				if(inter(l[i],l[j])){
					int fi,fj;
					fi=getF(i);
					fj=getF(j);
					if(fi!=fj){
						f[fj]=fi;
					}
				}
			}
		}
		while(scanf("%d%d",&a,&b) && (a||b)){
			if(getF(a-1)==getF(b-1)) printf("CONNECTED\n");
			else printf("NOT CONNECTED\n");
		}
	}
	/*for(i=0;i<n-1;++i){	//检测相交代码正确性
	  for(j=i+1;j<n;++j){
	  cout<<inter(l[i],l[j])<<endl;
	  }
	  }*/
	return 0;
}
/*检测相交代码正确性
  4
  0 0 3 3
  0 3 3 0
  0 5 5 0
  5 5 5 0
  1
  1
  0
  0
  0
  1
  */ 

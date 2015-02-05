#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * 一、
 * 首先，一些常用定义
 * some definitions about 运算符
 * */
//definition of Point
struct Point{
	double x, y;
	Point(double x = 0, double y = 0):x(x), y(y){}//construct function
};

//definition of Vector
typedef Point Vector;// To realize it from program, we name Point as anotherword - Vector

const double PI = acos(-1.0);

//以下函数顺序严格

//Vector + Vector = Vector, Point + Point = Vector;
Vector operator + (Vector A, Vector B){
	return Vector(A.x + B.x, A.y + B.y);
}

// Point - Point = Vector
Vector operator - (Vector A, Vector B){
	return Vector(A.x - B.x, A.y - B.y);
}

//Vector * number = Vector
Vector operator * (Vector A, double p){
	return Vector(A.x * p, A.y * p);
}

//Vector / number = Vector
Vector operator / (Vector A, double p){
	return Vector(A.x / p, A.y / p);
}

bool operator < (const Point & a, const Point & b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const double eps = 1e-10;//define the precision

//estimate if the error is in the eps range
int dcmp(double x){
	return (x > eps) - (x < -eps);         //x>eps  —> 1；x < -eps  —> -1.
}

//estimate if Point a and Point b is equal in the eps range
bool operator == (const Point & a, const Point & b){
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

//definition of Line
struct Line{
	Point p;
	Vector v;
	double a;
	Line (Point p = Point(), Vector v = Vector(1, 0)) : p(p), v(v) {a = atan2(v.y, v.x);}//构造函数
	bool operator < (const Line & b) const {return a < b.a;}
	Point point(double t){return p + v * t;}
};

/*
 * 二、
 * 以下开始基本运算
 * I'm some Basic Operations, such as 点积，叉积，relation of locations of 2 Vectors, rotations of Vectors, geometry operation of plural numbers
 * */
//Calc 点积
double Dot(Vector A, Vector B){
	return A.x * B.x + A.y * B.y;
}

//Calc length by 点积
double Length(Vector A){
	return sqrt(Dot(A, A));
}

//Calc Angle by 点积
double Angle(Vector A, Vector B){
	return acos(Dot(A, B) / Length(A) / Length(B));
}

//Calc 叉积
double Cross(Vector A, Vector B){
	return A.x * B.y - A.y * B.x;
}
double Area2(Point A, Point B, Point C){
	return Cross(B - A, C - A);
}

//Rotation of Vector : x' = x * cos a - y * sin a, y' = x * sin a + y * cos a;   a - 逆时针旋转的角,根据两角和的公式推出，-为顺时针旋转，+为逆时针旋转
Vector Rotate(Vector A, double rad){//rad is 弧度
	return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

// 法线
Vector Normal(Vector A){
	double L = Length(A);
	return Vector(-A.y / L, A.x / L);	
}

/*
 * 三、
 * 点和直线
 * */
//求2直线交点 - 直线P+tv,Q+tw有唯一交点，当且仅当Cross(v, w)!=0，参数式
//精度要求极高的时候可自定义分数类
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
	Vector u = P - Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + v * t;
}

//点到直线的距离，两点式
double DistanceToLine(Point P, Point A, Point B){
	Vector v1 = B - A, v2 = P - A;
	return fabs(Cross(v1, v2)) / Length(v1);
}

//点到线段的距离
double DistanceToSegment(Point P, Point A, Point B){
	if(A == B)
		return Length(P - A);
	Vector v1 = B - A, v2 = P - A, v3 = P - B;
	if(dcmp(Dot(v1, v2)) < 0)
		return Length(v2);
	else return fabs(Cross(v1, v2)) / Length(v1);//在线段上方
}

//点P在直线上的投影Q，向量PQ、AB垂直
Point GetLineProjection(Point P, Point A, Point B){
	Vector v = B - A;
	return A + v * (Dot(v, P - A) / Dot(v, v));
}

//线段相交的判定 - 每条线段的2个端点在另一条线段两侧
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2){
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
		   c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
//允许在端点相交
bool OnSegment(Point p, Point a1, Point a2){
	return dcmp(Cross(a1 - p, a2 - p)) && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

const int N=105;
Point p[N];
int n;

struct Circle{
	Point o;
	double r;
	Circle(){}
	Circle(Point _o,double _r){
		o=_o;
		r=_r;
	}
};

double dis(Point a,Point b){
	Vector ab=a-b;
	return Dot(ab,ab);
}

Circle get_circle(Point p1,Point p2,Point p3){
	double a,b,c,d,e,f,x,y,r;
	a=2*(p2.x-p1.x);
	b=2*(p2.y-p1.y);
	c=Dot(p2,p2)-Dot(p1,p1);
	d=2*(p3.x-p2.x);
	e=2*(p3.y-p2.y);
	f=Dot(p3,p3)-Dot(p2,p2);
	if(b*d-e*a==0){
		if(p1<p2) swap(p1,p2);
		if(p2<p3) swap(p2,p3);
		if(p1<p2) swap(p1,p2);
		x=(p1.x+p3.x)/2;
		y=(p1.y+p3.y)/2;
	}
	else{
		x=(b*f-e*c)/(b*d-e*a);
		y=(d*c-a*f)/(b*d-e*a);
	}
	r=dis(p1,Point(x,y));
	return Circle(Point(x,y),r);
}
Circle min_circle(){
	Circle ret=Circle(p[0],0);
	for(int i=1;i<n;++i){
		if(dis(p[i],ret.o) - ret.r > eps){
			ret=Circle(p[i],0);
			for(int j=0;j<i;++j){
				if(dis(p[j],ret.o) - ret.r > eps){
					ret.o=(p[i]+p[j])/2;
					ret.r=dis(p[j],ret.o);
					for(int k=0;k<j;++k){
						if(dis(p[k],ret.o) - ret.r > eps)
							ret=get_circle(p[i],p[j],p[k]);
					}
				}
			}
		}
	}
	ret.r=sqrt(ret.r);
	return ret;
}

int main(){
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		Circle ans=min_circle();
		printf("%.2lf %.2lf %.2lf\n",ans.o.x,ans.o.y,ans.r);
	}
}

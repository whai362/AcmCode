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

double dis(Point p1,Point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

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


/*一、
 *圆的问题
 * */
//define a circle
struct Circle{
	Point c;//圆心
	double r;
	Circle(Point c, double r) : c(c), r(r){}
	//通过圆心角求圆周上点坐标的函数
	Point point(double a){
		return Point(c.x + cos(a) * r, c.y + sin(a) * r);
	}
};

//直线和圆的交点
int getLineCircleIntersection(Line L, Circle C, double &t1, double &t2,vector<Point> &sol){
	double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
	double e = a * a + c * c, f = 2 * (a * b + c * d), g = b * b + d * d - C.r * C.r;
	double delta = f * f - 4 * e * g;//判别式
	if(dcmp(delta) < 0)//相离
		return 0;
	else if(dcmp(delta) == 0){//相切
		t1 = t2 = -f / (2 * e);
		sol.push_back(L.point(t1));
		return 1;
	}
	t1 = (-f - sqrt(delta)) / (2 * e);
	sol.push_back(L.point(t1));
	t2 = (-f + sqrt(delta)) / (2 * e);
	sol.push_back(L.point(t2));
	return 2;
}

int main(){
	double Rm,R,r,x,y,vx,vy;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf",&Rm,&R,&r,&x,&y,&vx,&vy)!=EOF){
	Point coin=Point(x,y);
	Vector dir=Vector(vx,vy);
	Line l=Line(coin,dir);
	Circle da=Circle(Point(0,0),R+r),
		   xiao=Circle(Point(0,0),Rm+r);
	vector<Point> x1,x2;
	int cnt1,cnt2;
	double t1,t2;
	cnt1=getLineCircleIntersection(l,da,t1,t2,x1);
	cnt2=getLineCircleIntersection(l,xiao,t1,t2,x2);
	Vector dir2=Vector(-x,-y);
	double arfa=Dot(dir,dir2);
	double V=sqrt(vx*vx+vy*vy);
	//cout<<arfa<<endl;
	if(cnt1<=1 || arfa<0+eps || V<eps) puts("0.000");
	else if(cnt2<=1){
		double ans;
		ans=dis(x1[0],x1[1]);
		printf("%.3lf\n",fabs(ans)/V);
	}
	else{
		double ans;
		ans=dis(x1[0],x1[1])-dis(x2[0],x2[1]);
		printf("%.3lf\n",fabs(ans)/V);
	}
	}
	return 0;
}

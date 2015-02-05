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

//线段相交的判定 - 每条线段的2个端点在另一条线段两侧
bool gao(Point a1, Point a2, Point b1, Point b2){
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
		   c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

Point s,t,o1,o2;
int main(){
	scanf("%lf%lf",&s.x,&s.y);
	scanf("%lf%lf",&t.x,&t.y);
	double _inf=1e6+5;
	int n;
	double a,b,c;
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;++i){
		scanf("%lf%lf%lf",&a,&b,&c);
		if(a==0){
			o1.y=o2.y=-c/b;
			o1.x=_inf;
			o2.x=-_inf;
		}
		else if(b==0){
			o1.x=o2.x=-c/a;
			o1.y=_inf;
			o2.y=-_inf;
		}
		else{
			o1.x=_inf;
			o2.x=-_inf;
			o1.y=(a*o1.x+c)/(-b);
			o2.y=(a*o2.x+c)/(-b);
		}
		//cout<<o1.x<<' '<<o1.y<<endl;
		//cout<<o2.x<<' '<<o2.y<<endl;
		if(gao(s,t,o1,o2)) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}

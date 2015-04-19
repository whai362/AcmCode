1. a*b*c=4*R*s(由面积公式及正弦定理得到)
2. 海伦公式: s=sqrt(p*(p-a)*(p-b)*(p-c))、p=(a+b+c)/2
3. 已知三角形的三边abc求出半径: R=abc/sqrt(a+b+c)(a+b-c)(a+c-b)(b+c-a)
4. 圆台: V=πh(R^2＋Rr＋r^2)/3
5. pick公式:
设A为平面上以格子点为顶点的单纯多多形，则其面积为： 
s=b/2+i-1
其中b为边界上的格子点数,i为內部的格子点数。

例子：
/*
   题意：给出三个点的坐标，问在这三个点坐标里面的整数坐标点有多少个（不包含边上的）
*/
#include<cstdio>
#include<cmath>
using namespace std;
struct point{
	int x,y;
}p[3];
int _abs(int x){
	if(x<0) return -x;
	else return x;
}
int xmul(point a,point b,point c){
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
int gcd(int a,int b){
	if(b) return gcd(b,a%b);
	return a;
}
int p_num(point a,point b){
	return gcd(_abs(a.x-b.x),_abs(a.y-b.y));
}
int main(){
	int i;
	double s,b;
	while(1){
		for(i=0;i<3;++i) scanf("%d%d",&p[i].x,&p[i].y);
		if(p[0].x==0&&p[0].y==0&&p[1].x==0&&p[1].y==0&&p[2].x==0&&p[2].y==0) break;
		s=fabs((xmul(p[0],p[1],p[2])+0.0)/2);
		b=p_num(p[0],p[1])+p_num(p[0],p[2])+p_num(p[1],p[2]);
		printf("%.0f\n",s-b/2+1);
	}
	return 0;
}
6. 叉积的意义：
a * b = |a| * |b| * sin<a,b>

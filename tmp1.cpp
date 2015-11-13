#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define eps 1e-8
#define N 100010
struct point
{
	double x, y;
	void sc(){
		scanf("%lf%lf", &x, &y);
	}
	point operator - (const point &b) const{
		point c;
		c.x = x-b.x, c.y = y-b.y;
		return c;
	}
	point(){}
	point(double x, double y):x(x), y(y){}
}p[2*N];
double cross(point P, point Q){
	return P.x*Q.y - P.y*Q.x;
}
int stk[N], top;
bool h(point &A, point &B, point &C, point &D)
{
	double sa = cross(A-C, A-D);
	double sb = cross(B-C, B-D);
	if(sa * sb > 0 || fabs(sa * sb) < eps) return false;
	return true;
}
bool check(point &A, point &B, point &C, point &D)
{
	return (max(A.x, B.x) >= min(C.x, D.x)) &&
		(max(A.y, B.y) >= min(C.y, D.y)) &&
		(max(C.x, D.x) >= min(A.x, B.x)) &&
		(max(C.y, D.y) >= min(A.y, B.y)) &&
		h(A, B, C, D) && h(C, D, A, B);
}
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		int top = 0, tp = 0;
		for(int i = 0;i < n;i++)
		{
			p[2*i].sc();
			p[2*i+1].sc();
			stk[i] = 0;
		}
		//for(int j = n-1;j >= 0;j--)
		//	for(int i = 0;i < j;i++) if(!stk[i])
		//		if(check(p[2*i], p[2*i+1], p[2*j], p[2*j+1])) {
		//			stk[i] = 1;
		//			break;
		//		}
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if(check(p[2*i], p[2*i+1], p[2*j], p[2*j+1])) {
					stk[i] = 1;
					break;
				}
			}
		}
		printf("Top sticks: ");
		for(int i = 0;i < n;i++) if(!stk[i])
			stk[top++] = i;
		for(int i = 0;i < top;i++)
			printf("%d%c%c", stk[i]+1, ",."[i==top-1], " \n"[i == top-1]);
	}
	return 0;
}

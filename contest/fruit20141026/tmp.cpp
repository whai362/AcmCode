/* ***********************************************
Author        :kuangbin
Created Time  :2014/10/4 21:49:13
File Name     :E:\2014ACM\专题学习\计算几何\模拟退火\POJ1379.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 10100;
const double PI = acos(-1.0);
struct Point{
	double x,y;
	void input(){
		scanf("%lf%lf",&x,&y);
	}
	double distance(Point b){
		return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
	}
}p[MAXN],tp[50];
double dist[50];
int n;
double calc(Point p0){
	double ret = 1e20;
	for(int i = 0;i < n;i++)
		ret = min(ret,p[i].distance(p0));
	return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
	double X,Y;
	scanf("%d",&T);
	srand(time(NULL));
	int P = 15, L = 30;
	while(T--){
		scanf("%lf%lf%d",&X,&Y,&n);
		for(int i = 0;i < n;i++)p[i].input();
		for(int i = 0;i < P;i++){
			tp[i].x = (rand()%1000+1)/1000.0*X;
			tp[i].y = (rand()%1000+1)/1000.0*Y;
			dist[i] = calc(tp[i]);
		}
		double step = sqrt(X*X + Y*Y)/2;
		while(step > 1e-5){
			for(int i = 0;i < P;i++){
				Point cur, pre = tp[i];
				for(int j = 0;j < L;j++){
					double angle = (rand()%1000+1)/1000.0*2*PI;
					cur.x = pre.x + cos(angle)*step;
					cur.y = pre.y + sin(angle)*step;
					if(cur.x < 0 || cur.x > X || cur.y < 0 || cur.y > Y)continue;
					double tmp = calc(cur);
					if(tmp >  dist[i]){
						tp[i] = cur;
						dist[i] = tmp;
					}
				}
			}
			step *= 0.8;
		}
		int id;
		double ans = 0;
		for(int i = 0;i < P;i++)
			if(dist[i] > ans){
				ans = dist[i];
				id = i;
			}
		printf("The safest point is (%.1lf, %.1lf).\n",tp[id].x,tp[id].y);
	}
    return 0;
}

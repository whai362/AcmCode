/*poj 2420
  题意：
  平面上给你n个点(xi,yi)，让你求一个点，到这n点的距离和最小。
  限制：
  1 <= n <= 100
  0 <= xi,yi <= 1e4, 为整数
  思路：
  模拟退火

  其伪代码如下：
  Let s = s0
  For k = 0 through k_max (exclusive):
	T := temperature(k / k_max)
  	Pick a random neighbour, s_new := neighbour(s)
  	If P(E(s), E(s_new), T) > random(0, 1), move to the new state:
  		s := s_new
  Output: the final state s
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const double E = exp(1.0);
struct Pt{
	double x,y;
}p[105];
double sqr(double x){
	return x*x;
}
double dis(Pt a, Pt b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
double get_sum(Pt p0, int n){
	double ret = 0;
	for(int i = 0; i < n; ++i)
		ret += dis(p0, p[i]);
   return ret;	
}
int main(){
	srand(1123);
	int n;
	int limit = 10000; //(x,y)的范围
	while(scanf("%d", &n) != EOF){
		double x0 = 0, y0 = 0;
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf", &p[i].x, &p[i].y);
			x0 += p[i].x;
			y0 += p[i].y;
		}
		x0 /= n;
		y0 /= n;
		double ans = get_sum((Pt){x0, y0}, n);
		double temp = 1e5; //初始温度, 根据题目修改
		while(temp > 0.02){ //0.02为温度的下限, 若温度temp达到下限, 则停止搜索
			double x = 0, y = 0;
			for(int i = 0; i < n; ++i){ //获取步长的规则根据题目而定
				x += (p[i].x - x0) / dis((Pt){x0, y0}, p[i]);
				y += (p[i].y - y0) / dis((Pt){x0, y0}, p[i]);
			}
			double tmp = get_sum((Pt){x0 + x * temp, y0 + y * temp}, n); //标函数E(x_new);
			if(tmp < ans){
				ans = tmp;
				x0 += x * temp;
				y0 += y * temp;
			} else if(pow(E, (ans - tmp) / temp) > (rand() % limit) / (double)limit){
				ans = tmp;
				x0 += x * temp;
				y0 += y * temp;
			}
			temp *= 0.9; //0.9为降温退火速率, (范围为0~1, 越大得到全局最优解的概率越高, 运行时间越长
		}
		printf("%.0f\n", ans);
	}
	return 0;
}

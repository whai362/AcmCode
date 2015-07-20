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
			for(int i = 0; i < n; ++i){ //获取步长的规则根据题目而定, 和下面的另外一道题对比着看
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

/*poj 2069 Super Star
  题意：
  给定n个点(xi, yi, zi), 要求覆盖这些点的最小球半径。
  限制：
  4 <= n <= 30
  0 <= xi, yi, zi <= 100
  思路：
  模拟退火
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
const double E = exp(1.0);
struct Pt{
	double x, y, z;
}p[35];
double sqr(double x){
	return x * x;
}
double dis(Pt a, Pt b){
	return sqrt(sqr(a.x - b.x) +
				sqr(a.y - b.y) +
				sqr(a.z - b.z));
}
double get_max_r(Pt p0, int n){
	double ret = 0;
	for(int i = 0; i < n; ++i)
		ret = max(ret, dis(p0, p[i]));
	return ret;
}
int main() {
	int n;
	int limit = 100;
	while(scanf("%d", &n) && n){
		double x0 = 0, y0 = 0, z0 = 0;
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
			x0 += p[i].x;
			y0 += p[i].y;
			z0 += p[i].z;
		}
		x0 /= n;
		y0 /= n;
		z0 /= n;
		//cout<<x0<<' '<<y0<<' '<<z0<<endl;
		double ans = get_max_r((Pt){x0, y0, z0}, n);
		double temp = 1e5;
		while(temp > 1e-8){
			double x = 0, y = 0, z = 0;
			double max_r = 0;
			for(int i = 0; i < n; ++i){
				double r = dis((Pt){x0, y0, z0}, p[i]);
				if(r > max_r){
					x = (p[i].x - x0) / r;
					y = (p[i].y - y0) / r;
					z = (p[i].z - z0) / r;
					max_r = r;
				}
			}
			double tmp = get_max_r((Pt){
					x0 + x * temp,
					y0 + y * temp,
					z0 + z * temp}, n);
			if(tmp < ans){
				ans = tmp;
				x0 += x * temp;
				y0 += y * temp;
				z0 += z * temp;
			} else if(pow(E, (ans - tmp) / temp) > (rand() % limit) / (double)limit){
				ans = tmp;
				x0 += x * temp;
				y0 += y * temp;
				z0 += z * temp;
			}

			temp *= 0.998;
		}
		printf("%.5f\n", ans);
	}
	return 0;
}

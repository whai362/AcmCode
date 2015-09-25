#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
const double E = exp(1.0);
const double INF = 1e30;

//double maxx = -INF, minn = INF;

const int N = 200000 + 5;

double x[N];

double sqr(double x) {
    return x * x;
}

double fun(double v, int n) {
	double tmp = x[0] - v, ret = x[0] - v;
	//cout<<x[0] - v<<' ';
	bool flag = 0;
	if(x[0] < v) flag = 1;
	for(int i = 1; i < n; ++i) {
		if(x[i] < v) flag = 1;
		tmp += x[i] - v;
		//cout<<x[i] - v<<' ';
		if(tmp < x[i] - v) {
			tmp = x[i] - v;
		}
		ret = max(tmp, ret);
	}
	//cout<<endl;
	//cout<<ret<<endl;
	if(flag) {
		tmp = v - x[0];
		for(int i = 1; i < n; ++i) {
			tmp += v - x[i];
			if(tmp < v - x[i]) {
				tmp = v - x[i];
			}
			ret = max(tmp, ret);
		}
	}
	return ret;
}

int main() {
    int n;
    cin>>n;
    double x0 = 0;
    for(int i = 0; i < n; ++i) {
        cin>>x[i];
        x0 += x[i];
        //maxx = max(x[i], maxx);
        //minn = min(x[i], minn);
    }
    x0 /= n;
    int limit = 20000;
    double ans = fun(x0, n);
    double temp = 1e5; //初始温度, 根据题目修改
    while (temp > 0.0000001) { //0.02为温度的下限, 若温度temp达到下限, 则停止搜索
        double X = 0;
        for (int i = 0; i < n; ++i) { //获取步长的规则根据题目而定, 和下面的另外一道题对比着看
            X += (x[i] - x0);
        }
        double tmp = fun(X, n); //标函数E(x_new);
        if (tmp < ans) {
            ans = tmp;
            x0 += X * temp;
        } else if (pow(E, (ans - tmp) / temp) > (rand() % limit) / (double)limit) {
            ans = tmp;
            x0 += X * temp;
        }
        temp *= 0.9; //0.9为降温退火速率, (范围为0~1, 越大得到全局最优解的概率越高, 运行时间越长
    }
    cout<<x0<<endl;
    printf("%.7f\n", fun(x0, n));
}

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
	//浮点数普通输出
	double a = 123.123456789;
	cout<<a<<endl;	//这个默认保留6位有效数字
	printf("%lf\n", a);	//这个默认保留小数点后6位

	//浮点数保留小数点后3位四舍五入输出
	cout<<fixed<<setprecision(3)<<a<<endl; //用这个的话要#include<iomanip>
	printf("%.3lf\n", a);

	return 0;
}
